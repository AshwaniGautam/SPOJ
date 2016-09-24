#include <iostream>
#include <stdio.h>
#define N 100009
using namespace std 	;

int array[N]	;

struct node{

	long long int lazy_square, lazy_linear ;
	long long int linear_sum, square_sum	;

};

node ST[272149]	;

void combine(int pos){

	ST[pos].linear_sum = ST[2*pos+1].linear_sum + ST[2*pos+2].linear_sum	;
	ST[pos].square_sum = ST[2*pos+1].square_sum + ST[2*pos+2].square_sum	;
	
}

void pushdown_reset(int low, int high, int pos, long long int value){

	ST[pos].square_sum  = (high - low + 1) * value * value	;
	ST[pos].linear_sum  = (high - low + 1) * value						;

	if (high != low){

		ST[2*pos+1].lazy_linear = value	;
		ST[2*pos+2].lazy_linear = value	; 
		ST[2*pos+1].lazy_square = 0	;
		ST[2*pos+2].lazy_square = 0	;

	}

	ST[pos].lazy_linear = 0	;
	ST[pos].lazy_square = 0	;
}

void pushdown_add(int low, int high, int pos, long long int value){

	ST[pos].square_sum += (value * value * (high - low + 1)) + 2 * value * ST[pos].linear_sum	; 	
	ST[pos].linear_sum +=  value * (high - low + 1)	;

	if (low != high){

		int mid = (low+high) / 2	;
		if (ST[2*pos+1].lazy_linear)
			pushdown_reset(low, mid, 2*pos + 1, ST[pos].lazy_linear)	;
		
		if (ST[2*pos+2].lazy_linear)
			pushdown_reset(mid+1, high, 2*pos + 2, ST[pos].lazy_linear)	;

		ST[2*pos+1].lazy_square += value	;
		ST[2*pos+2].lazy_square += value	;
		
	}

	ST[pos].lazy_square  =	0	;

}

void build(int low, int high, int pos){

	if (low == high){

		ST[pos].square_sum = array[low] * array[low]	;
		ST[pos].linear_sum = array[low]	;
		ST[pos].lazy_linear = 0		;
		ST[pos].lazy_square = 0		;

		return 	;
	}

	int mid = (low + high) / 2	;
	build(low, mid, 2*pos+1)	;
	build(mid+1, high, 2*pos+2)	;

	combine(pos)	;
	
	ST[pos].lazy_linear = 0		;
	ST[pos].lazy_square = 0		;

}

void update_reset(int i, int j, int low, int high, int pos, long long int value){

	if (ST[pos].lazy_linear)
		pushdown_reset(low, high, pos, ST[pos].lazy_linear)	;

	if (j < low || i > high)
		return;

	if (i <= low && high <= j){
		pushdown_reset(low, high, pos, value)	;
		return;
	}

	int mid = (high + low) / 2	;
	update_reset(i, j, low, mid, 2*pos+1, value)	;
	update_reset(i, j, mid+1, high, 2*pos+2, value)	;

	combine(pos)	;

}

void update_add(int i, int j, int low, int high, int pos, long long int value){

	if (ST[pos].lazy_linear)
		pushdown_reset(low, high, pos, ST[pos].lazy_linear)	;

	if (ST[pos].lazy_square)
		pushdown_add(low, high, pos, ST[pos].lazy_square)	;

	if (j < low || i > high)
		return ;

	if (i <= low && high <= j){
		pushdown_add(low, high, pos, value)	;
		return;
	}

	int mid = (low + high) / 2	;
	update_add(i, j, low, mid, 2*pos+1, value)	;
	update_add(i, j, mid+1, high, 2*pos+2, value)	;

	combine(pos)	;

}

int query(int i, int j, int low, int high, long long int pos){

	if (ST[pos].lazy_linear)
		pushdown_reset(low, high, pos, ST[pos].lazy_linear)	;

	if (ST[pos].lazy_square)
		pushdown_add(low, high, pos, ST[pos].lazy_square)	;

	if(j < low || i > high)
		return 0	;

	if (i <= low && high <= j)
		return ST[pos].square_sum	;

	int mid = (low+high) / 2	;
	return	(query(i, j, low, mid, 2*pos+1) + query(i, j, mid+1, high, 2*pos+2))	;

}


int main(){

	int test = 1, t, n, q, L, R, type 	;
	long long int value	;
	scanf("%d", &t)	;
	while(t--){
		printf("Case %d:\n", test)	;
		test++	;
		scanf("%d %d", &n, &q)	;
		for (int i = 0; i < n; i++)
			scanf("%d", &array[i])	;

		build(0, n-1, 0)	;

		for (int i = 0; i < q; i++){
			scanf("%d %d %d", &type, &L, &R)	;

			if(type == 2)

				printf("%d\n", query(L-1, R-1, 0, n-1, 0))	;

			else{
					
				scanf("%lld", &value)	;

				if(type == 1)
					update_add(L-1, R-1, 0, n-1, 0, value)	;

				else
					update_reset(L-1, R-1, 0, n-1, 0, value)	;

			}
		}
	}

	return 0	;
}