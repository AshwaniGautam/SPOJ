#include <stdio.h>
#include <iostream>
using namespace std;

int MOD;

struct Matrix{

	long long int A[2][2]	;

};

Matrix Matrix_Mult(Matrix D, Matrix E){

	Matrix C	;

	C.A[0][0] = (D.A[0][0] * E.A[0][0] + D.A[0][1] * E.A[1][0]) % MOD;
	C.A[0][1] = (D.A[0][0] * E.A[0][1] + D.A[0][1] * E.A[1][1]) % MOD;
	C.A[1][0] = (D.A[1][0] * E.A[0][0] + D.A[1][1] * E.A[1][0]) % MOD;
	C.A[1][1] = (D.A[1][0] * E.A[0][1] + D.A[1][1] * E.A[1][1]) % MOD;

	return C;
}


Matrix F(Matrix T, int n){

	if (n == 1)
		return T 	;

	Matrix inter = F(T, n / 2)	;

	if (n % 2)
		return Matrix_Mult(T, Matrix_Mult(inter, inter))	;
	return Matrix_Mult(inter, inter)	;
}


int main(){


	Matrix trans	;
	int vec[2]	;
	vec[0] = 1; vec[1] = 0	;

	trans.A[0][0] = 1; trans.A[0][1] = 1    ;
	trans.A[1][0] = 1; trans.A[1][1] = 0	; 

	int t;
	int n;
	scanf("%d", &t)	;
	while(t--){

		scanf("%d %d", &n, &MOD)	;
		n++;
		printf("%lld\n", (((2*(F(trans, n).A[0][0]) - 1) - n)%MOD+MOD)%MOD)	;
	}

	return 0	;
}

