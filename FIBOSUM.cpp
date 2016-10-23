#include <stdio.h>
#include <iostream>
#include <string.h>
#define MOD 1000000007
using namespace std;

int vec[2];

struct Matrix{

	long long int A[2][2]	;

}	;

Matrix matrix_mult(Matrix D, Matrix E){

	Matrix C	;

	C.A[0][0] = (D.A[0][0] * E.A[0][0] + D.A[0][1] * E.A[1][0]) % MOD;
	C.A[0][1] = (D.A[0][0] * E.A[0][1] + D.A[0][1] * E.A[1][1]) % MOD;
	C.A[1][0] = (D.A[1][0] * E.A[0][0] + D.A[1][1] * E.A[1][0]) % MOD;
	C.A[1][1] = (D.A[1][0] * E.A[0][1] + D.A[1][1] * E.A[1][1]) % MOD;

	return C;
}

Matrix F(Matrix A, int n){

	if (n == 1)
		return A;

	if (n % 2)
		return matrix_mult(A,  F(A, n-1))	;

	Matrix inter = F(A, n / 2)	;
	return matrix_mult(inter, inter)	;
}

int main(){

	ios_base::sync_with_stdio(false);   cin.tie(0)  ;

	int t, L, R ;	
	scanf("%d", &t)	;

	vec[0] = 1, vec[1] = 0	;
	Matrix trans, Right, Left;
	trans.A[0][0] = 1, trans.A[0][1] = 1	;
	trans.A[1][0] = 1; trans.A[1][1] = 0 	;

	while(t--){

		scanf("%d %d", &L, &R)	;
		L++;
		R++;
		if (L == 1)
			Left.A[0][0] = 1 ; 
		else
			Left = F(trans, L-1)	;
		Right = F(trans, R)  	;
		
		printf("%lld\n", ((Right.A[0][0]-Left.A[0][0])%MOD+MOD)%MOD)	;
	}
	return 0	;
}