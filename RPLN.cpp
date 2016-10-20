#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 100000
#define INF 1 << 30

using namespace std;

int array[N]	;
int ST[350000]	;

void build(int pos, int low, int high){

	if (low == high){
		ST[pos] = array[low]	;
		return;
	}
	int mid = (low + high) / 2	;
	build(2*pos+1, low, mid)	;
	build(2*pos+2, mid+1, high)	;

	ST[pos] = min(ST[2*pos+1], ST[2*pos+2])	;

}

int query(int i, int j, int low, int high, int pos){

	if (j < low || i > high)
		return	INF	;

	if (i <= low && high <= j) 
		return ST[pos]	;

	int mid = (low + high) / 2	;
	return min(query(i, j, low, mid, 2*pos+1), query(i, j, mid+1, high, 2*pos+2))	;

}

int main(){
	
	ios_base::sync_with_stdio(false);   cin.tie(0)  ;

	int t, n, q, A, B 	;
	int test = 1	;
	scanf("%d", &t)	;
	
	while(t--){

		scanf("%d %d", &n, &q)	;
		for(int i = 0; i < n; i++)
			scanf("%d", &array[i])	;

		build(0, 0, n-1)	;
		printf("Scenario #%d: \n", test++)	;

		for (int i = 0; i < q; i++){

			scanf("%d %d", &A, &B)	;
			A--	;
			B--	;
			printf("%d\n", query(A, B, 0, n-1, 0))	;

		}
	}
	return 0	;
}