#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAXN 1000004
using namespace std;
int BIT[MAXN]    ;
int arr[MAXN]    ;

void update(int idx, int value, int n)  {
    for (; idx <= n; idx += idx & -idx)
        BIT[idx] += value   ;
}
int query(int idx){
    int s = 0   ;
    for (; idx > 0; idx -= idx & -idx)
        s += BIT[idx]   ;
    return s    ;
}
int main(){
    int N, K    ;
    cin >> N >> K   ;
    while(K--){
        int L, R    ;
        cin >> L >> R   ;
        update(L, 1, N) ;
        update(R + 1, -1, N) ;
    }
    for (int i = 0; i < N; i++)
        arr[i] = query(i + 1)   ;
    sort(arr, arr + N)  ;
    cout << arr[N / 2] << "\n"  ;

    return  0  ;
}
