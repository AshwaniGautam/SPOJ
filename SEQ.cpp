#include <stdio.h>
#include <iostream>
#include <string.h>
#define MOD 1000000000
using namespace std;

int K;

struct Matrix{

	long long int A[10][10]	;

	Matrix operator * (Matrix& B)	const{

		Matrix C;
		memset(C.A, 0, sizeof(C.A))	;
		
		for (int i = 0; i < 10; i++)  for(int j = 0; j < 10; j++)  for(int k = 0; k < 10; k++)
			C.A[i][j] = (C.A[i][j] + A[i][k] * B.A[k][j]) % MOD	;

		return C;
	}
}	;



Matrix bin_pow(Matrix T, long long int exp){

	if (exp == 1)
		return T;

	Matrix inter = bin_pow(T, exp / 2)	;

	if (exp % 2)
		return T * inter * inter	;
	return inter * inter	;

}

int main(){

	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	int n, t;
	int b[15], c[15] ;

	scanf("%d", &t)	;
	while(t--){

		scanf("%d", &K)	;
		
		Matrix trans;
		long long int sol = 0	;

		memset(trans.A, 0, sizeof(trans.A))	;
		memset(b, 0, sizeof(b))	;
		memset(c, 0, sizeof(c))	;

		for (int i = 0; i < K; i++)
			scanf("%d", &b[i])	;

		for (int i = 0; i < K; i++)
			scanf("%d", &c[i])		;
		
		scanf("%d\n", &n)	;


		for (int i = 0; i < K; i++) 
			trans.A[0][i] = c[i]	;

		for (int i = 1; i < 11; i++)
			trans.A[i][i-1] = 1;

		if (n <= K)
			printf("%d\n", b[n-1])	;

		else{

			Matrix ans = bin_pow(trans, n - K)	;

			for(int i = 0 ; i < K; i++)
				sol = (sol + ans.A[0][i]* b[K-1-i])% MOD	; 
			printf("%lld\n", sol)	;

		}

	}
	return 0	;
}