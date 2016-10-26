#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int K;
long long int MOD	;

struct Matrix{

	long long int A[20][20]	;

	Matrix operator * (Matrix& B)	const{

		Matrix C;
		memset(C.A, 0, sizeof(C.A))	;
		
		for (int i = 0; i < 20; i++)  for(int j = 0; j < 20; j++)  for(int k = 0; k < 20; k++)
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
	int  t;
	int b[20], c[20] ;
	long long int prefix[20]	;
	long long int m, n  	;
	scanf("%d", &t)	;
	while(t--){

		scanf("%d", &K)	;
		
		Matrix Left, Right, trans;
		long long int sol, l, r = 0	;

		memset(trans.A, 0, sizeof(trans.A))	;
		memset(b, 0, sizeof(b))	;
		memset(c, 0, sizeof(c))	;
		memset(prefix, 0, sizeof(prefix))	;

		for (int i = 0; i < K; i++)
			scanf("%d", &b[i])	;

		for (int i = 0; i < K; i++)
			scanf("%d", &c[i])		;
		
		scanf("%lld %lld %lld\n", &m, &n, &MOD)	;

		prefix[0] = b[0]	;
		for(int i = 1; i < K; i++)
			prefix[i] = prefix[i-1] + b[i]	;

		trans.A[0][0] = 1	;
		for (int i = 1; i < K+1; i++){ 
			trans.A[0][i] = c[i-1]	;
			trans.A[1][i] = c[i-1]	;
		}

		for (int i = 2; i < K+1; i++)
			trans.A[i][i-1] = 1;

		if (m-1 > K){
			Left = bin_pow(trans, m - K - 1)	;
			l = prefix[K-1] % MOD	;
			for(int i = 1; i < K+1; i++)
				l = (l + Left.A[0][i] * b[K-i]) % MOD		;
		}
		else
			l = prefix[m-2] % MOD	;

		if (n > K){
			Right = bin_pow(trans, n - K);
			r = prefix[K-1] % MOD	;
			for(int i = 1; i < K+1; i++)
				r = (r + Right.A[0][i] * b[K-i]) % MOD	;   

		}
		else
			r = prefix[n-1] % MOD	;
		printf("%lld\n", ((r - l)%MOD+MOD)%MOD)	;

	}

	return 0	;
}