#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAXN 1000005
using namespace std;
long long int BIT[MAXN]    ;

void update(int idx, int value){
    for(; idx <= MAXN; idx += idx & -idx)
        BIT[idx] += value   ;
}

long long int query(int idx){
    long long int s = 0  ;
    for(; idx > 0; idx -= idx & -idx)
        s += BIT[idx]   ;
    return s    ;
}
int main(){
    int t, n, value   ;
    long long int ans   ;
    cin >> t    ;
    while(t--){
        ans = 0 ;
        memset(BIT, 0, sizeof BIT)  ;
        cin >> n   ;
        for (int i = 0; i < n; i++){
            cin >> value;
            if (value == 0)
                continue    ;
            ans += query(value - 1) ;
            update(value, value) ;
        }
        cout << ans << "\n" ;

    }

    return 0    ;
}
