#include<bits/stdc++.h>
#define MAX 3170
using namespace std;

int test, N, prime[3170] ;
vector<int>primes ;


inline void sieve(){

    for(int i = 2; i <= MAX; i += 2)
        prime[i] = 1    ;
    for(int i = 3; i * i <= MAX; i += 2)
        if(!prime[i])
            for(int j = i * i; j <= MAX; j += 2*i)
                prime[j] = 1    ;
    primes.push_back(2) ;
    for(int i = 3; i <= MAX; i+= 2)
        if(!prime[i])
            primes.push_back(i) ;
}

int main(){
    cin.sync_with_stdio(0)  ;
    sieve() ;
    cin >> test ;

    while(test--){
        cin >>  N   ;
        int odd = 0, even = 0   ;
        for(int i = 0; i < primes.size(); i++){
            int counter = 0 ;
            if(N % primes[i] == 0){
                while(N % primes[i] == 0){
                    counter++   ;
                    N /= primes[i]  ;
                }
                if(counter % 2)
                    odd++   ;
                else
                    even++  ;
            }
        }
                    if(N > 1)
                odd++    ;

            if(even > odd)
                cout << "Psycho Number\n"   ;
            else
                cout << "Ordinary Number\n" ;
    }
    return  0;

}
