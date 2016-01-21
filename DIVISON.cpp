#include<stdio.h>
#include<iostream>
#define inv 333333336
#define mod 1000000007
using namespace std     ;
int bin_exp(unsigned long long n){
    if (n == 0)
            return 1    ;
    if (n == 1)
            return 2    ;
    int result = bin_exp(n/2)   ;
    if (n % 2)
        return 2 * result * result  ;
    return result * result  ;

    }
int main(){
    unsigned long long N    ;
    while(scanf("%llu", &N)!= EOF){
            if (N % 2){
                printf("%llu hi this is N", N ) ;
                int result = ((bin_exp(N) + 1) * inv) % mod ;
                printf("%d\n", result)  ;
            }
            else{
                printf("%llu hi this is N", N ) ;
                int result = ((bin_exp(N) + 2) * inv) % mod;
                printf("%d\n", result)  ;
            }
    }

}
