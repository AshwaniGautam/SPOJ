#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unordered_map>
#define N 10000099


using namespace std;	

unordered_map <int, int> mymap ;


int array[N], count		;
struct node
{
	int lazy, value	;
};

node ST[N << 2]	;

void pushdown(int low, int high, int pos, int value){

	ST[pos].value = value	;
	if (low != high){

		ST[2*pos+1].lazy = value	; 
		ST[2*pos+2].lazy = value	; 
	}

	ST[pos].lazy = 0 ;
}

void unique(int low, int high, int pos){

	if (ST[pos].lazy)
		pushdown(low, high, pos, ST[pos].lazy)	;

	if (low == high){
		mymap.insert(make_pair(ST[pos].value, 1))	;
		return;
	}

	int mid = (low + high) / 2	;
	unique(low, mid, 2*pos+1)	;
	unique(mid+1, high, 2*pos+2)	;

}


void update(int i, int j, int low, int high, int pos, int value){

	if (ST[pos].lazy)
		pushdown(low, high, pos, ST[pos].lazy)	;

	if(j < low || i > high)
		return ;

	if (i <= low && high <= j){
		pushdown(low, high, pos, value)	;
		return ;
	}

	int mid = (low + high) / 2		;
	update(i, j, low, mid, 2*pos+1, value)	;
	update(i, j, mid+1, high, 2*pos+2, value)	;

}

int main(){

	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	int t, q, L, R 	;
	scanf("%d", &t)	;
	while(t--){

		memset(ST, 0, sizeof(ST))	;	
		mymap.clear();
		scanf("%d", &q)	;
		for (int i = 1; i <= q; i++){

			scanf("%d %d", &L , &R)	;
			L-- ;
			R--	;
			update(L, R, 0, N-1, 0, i)	;

		}
		
		unique(0, N-1, 0)	;
		printf("%d\n", mymap.size());
	}

	return 0	;
}