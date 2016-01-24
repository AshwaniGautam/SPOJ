#include<stdio.h>
#include<iostream>
#define MAXN 100005
using namespace std ;
long long int cumu [MAXN]   ;
long long int bit[MAXN] ;
int LMAX[MAXN]  ;
int RMAX[MAXN]  ;
void update(int idx, int value, int n){
    for(; idx <= n; idx += idx & -idx)
        bit[idx] += value;
}

long long int query(int idx){
    long long int ans = 0   ;
    for(; idx > 0; idx -= idx & -idx)
        ans += bit[idx] ;
    return ans  ;
}

int main(){
    int t, L, R, i = 0, l, r   ;
    cin >> t    ;
    long long int result1, result2  ;
    while(t--){
        cin >> LMAX[i] >> RMAX[i]   ;
        i++ ;
    }
    for (int j = 0; j < i; j++){
        l = max(l, LMAX[i])   ;
        r = max(r, RMAX[i])   ;
    }
        int global = max(l, r)  ;
        for (int j = 0; j < i; j++){

            result1 = query(LMAX[j])   ;
            result2 = query (RMAX[j])  ;
            cout << result1 + result2 - cumu[LMAX[j]] - cumu[RMAX[j]] << "\n" ;
            cumu[LMAX[j]] = result1   ;
            cumu[RMAX[j]] = result2   ;
            update(LMAX[j]+1, 1, global)  ;
            update(RMAX[j], -1, global)   ;
        }
    return 0    ;
}
