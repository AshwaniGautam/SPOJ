#include<stdio.h>
#include<iostream>
#include<string.h>
#define N 10000005
using namespace std;
int BIT[N]  ;
int parent(int i){   return i - (i & -i) ;  }
int child (int i){   return i + (i & -i) ;   }

void update(int index, int n){
        while (index <= n){
            BIT[index] += 1 ;
            index = child(index)    ;
        }
}

long long int query(int L, int R){
    long long int Left = 0, Right = 0  ;
    while(L > 0){
        Left += BIT[L]  ;
        L = parent(L)   ;
    }
    while(R > 0){
        Right += BIT[R] ;
        R = parent(R)   ;
    }
    return (Right - Left)   ;
}
int main(){
    int t, Ni, value   ;
    cin >> t    ;
    long long int ans   ;
    while(t--){
        memset(BIT, 0, sizeof BIT)  ;
        cin >> Ni   ;
        ans = 0 ;
        for (int i = 1; i <= Ni; i++){
            cin >> value;
            ans += query(value, N) ;
            update(value, N)   ;
        }
        cout << ans << endl;
    }

    return 0    ;
}
