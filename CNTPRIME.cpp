#include <stdio.h>
#include <iostream>
#include <bitset>
#define N 1000099


using namespace std;

int array[15000]	;
bitset <N> primes	;

struct node
{
	int value, reset1, reset2	;
	
};

node ST[400000]	;

void sieve(){

    primes[1] = 0;

    for(int i = 4; i < N; i += 2) primes[i] = 0	;

    for(int i = 3; i * i <= N;  i += 2)
        if(primes[i])
            for(int j = i*i; j <= N; j += 2 * i)
                primes[j] = 0 ;
 }

void build(int pos, int low, int high){

	if(low == high){

		if (primes[array[low]])
			ST[pos].value = 1	;
		ST[pos].reset1 = ST[pos].reset2 = 0	;
		return ;

	}

	int mid = (low+high) / 2	;
	build(2*pos+1, low, mid)	;
	build(2*pos+2, mid+1, high)	;

	ST[pos].value = ST[2*pos+1].value + ST[2*pos+2].value	;

}

void pushdown(int low, int high, int pos, int value){

	ST[pos].value = (high - low + 1) * value;

	if (low != high){

		if (value){
			ST[2*pos+1].reset1 = 1;
			ST[2*pos+2].reset1 = 1;
			ST[2*pos+1].reset2 = 0;
			ST[2*pos+2].reset2 = 0;
		}
		else{

			ST[2*pos+1].reset2 = 1;
			ST[2*pos+2].reset2 = 1;	
			ST[2*pos+1].reset1 = 0;
			ST[2*pos+2].reset1 = 0;
		}
	}

	ST[pos].reset1 =  0	;
	ST[pos].reset2 =  0	;
}

void update(int i, int j, int low, int high, int pos, int value){

	if (ST[pos].reset1)
		pushdown(low, high, pos, 1)	;
	if (ST[pos].reset2)
		pushdown(low, high, pos, 0)	;

	if (j < low || i > high)
		return ;

	if (i <= low && high <= j){
		pushdown(low, high, pos, value)	;
		return ;
	}

	int mid = (low+ high)  / 2	;
	update(i, j, low, mid, 2*pos+1, value)	;
	update(i, j, mid+1, high, 2*pos+2, value)	;

	ST[pos].value = ST[2*pos+1].value + ST[2*pos+2].value	;

}

int query(int i, int j, int low, int high, int pos){

	if (ST[pos].reset1)
		pushdown(low, high, pos, 1)	;
	if (ST[pos].reset2)
		pushdown(low, high, pos, 0)	;

	if (j < low || i > high)	
		return 	0	;

	if (i <= low && high <= j)
		return ST[pos].value	;

	int mid = (low +  high) / 2	; 
	return (query(i, j, low, mid, 2*pos+1) + query(i, j, mid+1, high, 2*pos+2))	;

}


int main(){

	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	int t, n, q, type, value, L, R, test = 1;
	primes.set()	;
	sieve()	;
	scanf("%d", &t)	;
	while(t--){
		
		memset(ST, 0, sizeof(ST))	;
		memset(array, 0, sizeof(array))	;
		
		scanf("%d %d", &n, &q)	;
		for(int i = 0; i < n; i++)
			scanf("%d", &array[i])	;
		build(0, 0, n-1)	;

		printf("Case %d:\n", test++)	;
		for (int i = 0; i < q; i++){

			scanf("%d %d %d", &type, &L, &R)	;
			L--	;	
			R--	;
			if (type)
				printf("%d\n", query(L, R, 0, n-1, 0))	;

			else{

				int factor = 0	;
				scanf("%d", &value)	;
				if (primes[value])
					factor = 1	;
				update(L, R, 0, n-1, 0, factor)	;
			}
		}
	}

	return 0	; 
}