/*
The darkest places in the hell are reserved for those who maintain thier neutrality in times of moral crisis- Bertrand Zubrist
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define INF 1 << 20

int array[10001]	;

struct node{

	int solution, prefix_sum, suffix_sum, total;

}	;

node ST[32770]	;

void build(int low, int high, int pos){

	if (low == high){

		ST[pos].solution   = array[low]	;
		ST[pos].prefix_sum = array[low]	;
		ST[pos].suffix_sum = array[low]	;
		ST[pos].total      = array[low]	;

		return 	;

	}

	int mid =(low+high) / 2	;
	build(low, mid, 2*pos+1)	;
	build(mid+1, high, 2*pos+2)	;

	ST[pos].total = ST[2*pos+1].total +  ST[2*pos+2].total			;
	ST[pos].solution = max(max(ST[2*pos+1].solution, ST[2*pos+2].solution), ST[2*pos+1].suffix_sum + ST[2*pos+2].prefix_sum)	;
	ST[pos].prefix_sum = max(ST[2*pos+1].total + ST[2*pos+2].prefix_sum, ST[2*pos+1].prefix_sum)	;
	ST[pos].suffix_sum = max(ST[2*pos+2].total + ST[2*pos+1].suffix_sum, ST[2*pos+2].suffix_sum)	;

	return	;
}

void query(int i, int j, int low, int high, int pos, node &T){

	if (j < low || i > high){

		T.solution   =  -INF	;
		T.prefix_sum =  -INF	;
		T.suffix_sum =  -INF	;
		T.total      = 	0	;

		return 	;

	}

	if (i <= low && high <= j){

		T.solution   = ST[pos].solution	;
		T.prefix_sum = ST[pos].prefix_sum	;
		T.suffix_sum = ST[pos].suffix_sum	;
		T.total      = ST[pos].total	    ;

		return	;
	}

	int mid = (low + high) / 2	;
	node right, left	;
	query(i, j, low, mid, 2*pos+1, left)		;
	query(i, j, mid+1, high, 2*pos+2, right)	;

	T.solution = max(max(right.solution, left.solution), left.suffix_sum + right.prefix_sum)	;
	T.prefix_sum = max(left.total  + right.prefix_sum, left.prefix_sum)		;
	T.suffix_sum = max(right.total + left.suffix_sum, right.suffix_sum)	;
	T.total = left.total +  right.total			;

}
int main(){

	int test, n, q, ans, x1, y1, x2, y2	;
	cin >> test	;
	node T 	;
	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	while(test--){

		scanf("%d", &n)	;
		for (int i = 0; i < n; i++)
			scanf("%d", &array[i])	;

		build(0, n-1, 0)	;

		scanf("%d", &q)	;
		while(q--){

			scanf("%d %d %d %d", &x1, &y1, &x2, &y2)	;

			x1--	;
			y1--	;
			x2--	;
			y2--	;

			if (y1 < x2){

				node a, b, c 	;

				query(x1, y1, 0, n-1, 0, a)		;
				query(x2, y2, 0, n-1, 0, b)		;
				query(y1+1, x2-1, 0, n-1, 0,c)	;

				cout << a.suffix_sum + b.prefix_sum + c.total	<< "\n";

			}

			else{

				node a, b, c 	;

				query(x1, x2-1, 0, n-1, 0, a)	;
				query(x2,   y1, 0, n-1, 0, b)	;
				query(y1+1, y2, 0, n-1, 0, c)	;

				ans = max(max(max(a.suffix_sum + b.prefix_sum, b.solution), b.suffix_sum + c.prefix_sum), a.suffix_sum+b.total+c.prefix_sum) 	;
				
				cout << ans << "\n"	;

			}

		}

	}
	return 0	;
}