#include<stdio.h>
#include<iostream>
#include<bitset>
#include<vector>
# define N 10000
using namespace std;
int primes[10000]   ;
int lucky [10000]   ;
void sieve(){

    for (int i = 4; i < N; i += 2) primes[i] = 1  ;
    for (int i = 3; i < N; i += 2)
        if (primes[i] == 0)
            for (int j = i; j < N; j += i)
                primes[j] += 1  ;

}
int main(){
    int t, n    ;
    primes[2] = 1   ;
    sieve() ;
    int j = 0   ;
    for (int i = 0; i < N; i++){
        if (j < 1000)
            if (primes[i] >= 3){
                lucky[j] = i    ;
                j += 1  ;
        }
    }
    cin >> t    ;
    while(t--){
        cin >> n    ;
        cout << lucky[n - 1] << "\n"    ;
    }
    return 0    ;
}
