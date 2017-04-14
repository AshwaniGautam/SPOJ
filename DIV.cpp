#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int primes[1000002], divide[1000020] ;
vector<int> soln    ;

inline void sieve(){

    for(int i = 1; i <= MAX; i ++)
        for(int j = i; j <= MAX; j += i)
            divide[j]++    ;

    for(int i = 4; i <= MAX; i += 2)
        primes[i] = 1   ;
    for(int i = 3; i*i<= MAX; i += 2)
        if(!primes[i])
            for(int j = i*i; j <= MAX; j += 2*i)
                primes[j] = 1   ;

    soln.push_back(2)   ;
    for(int i = 3; i <= 1001; i++)
        if(!primes[i])
            soln.push_back(i)   ;
}


int main(){

    sieve() ;
    int turn  = 0 ;
    primes[1] = 1 ;
    for(int i = 1; i <= MAX; i++){
        int n = divide[i]  ;
        for(int j = 0; j < soln.size(); j++)
            if(n % soln[j] == 0 and !primes[soln[j]]){
                if(!primes[n / soln[j]] and (n / soln[j]) != soln[j]){
                    turn++  ;
                    if(turn % 9 == 0)
                        cout << i << "\n"   ;
                    break;
                }
            }
    }
    return 0    ;
}
