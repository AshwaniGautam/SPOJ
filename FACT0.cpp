#include<iostream>
#include<stdio.h>
#include<bitset>
#include<vector>
#define gc getchar_unlocked
#define N 400000000
using namespace std;
bitset <N> bits  ;
vector <int> primes  ;

void sieve(){
    bits[0] = 0;
    bits[1] = 0;
    for(int i = 3; i * i <= N;  i += 2)
        if(bits[i])
            for(int j = i*i; j <= N; j += 2 * i)
                bits[j] = 0 ;

    primes.push_back(2) ;
    for(int i = 3; i <=N; i += 2)
        if (bits[i])
            primes.push_back(i) ;
}

void factorize(long long int n){
    int count  = 0, i = 0 ;
    long long int m ;
    m = n   ;
    while (primes[i] * primes[i] <= n and i < primes.size()){
            count = 0   ;
            if ( m % primes[i] == 0)
                while(m % primes[i] == 0){
                        m  /= primes[i] ;
                        count += 1  ;
                }
            if (count!=0)
                cout << primes[i] << "^" << count << " ";
            i += 1  ;
    }
    if (m != 1)
        cout << m << "^" << "1" ;
}
int main(){
    long long int n ;
    ios_base::sync_with_stdio(false);   cin.tie(0)  ;
    bits.set()  ;
    sieve() ;
    while(1){
        scanf("%lld", &n)	;
        if (n == 0)
            return 0;
        if (n == 1)
                cout << "1^1\n";
        factorize(n)  ;
        cout << "\n"    ;
    }
    return 0;
}
