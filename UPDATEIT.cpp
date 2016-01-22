#include<stdio.h>
#include<iostream>
#include<string.h>
# define N 10001
using namespace std;
long long int BIT[N]    ;

int parent(int i) { return i - (i & -i) ;}
int child (int i) { return i + (i & -i) ;}

long long int query(int R){
    long long int Right = 0   ;
    while(R > 0){
        Right += BIT[R] ;
        R = parent(R) ;
    }
    return Right   ;
}

void update(int index, int value, int n){
        while (index <= n){
            BIT[index] += value;
            index = child(index)    ;
        }
}

int main(){
    long long int t, n, U, Q, value, L, R, index  ;
    scanf("%d", &t)    ;
    while(t--){
        memset(BIT, 0, sizeof BIT)  ;
        scanf("%d %d", &n, &U)  ;
        for (int i = 0; i < U; i++){
            scanf("%d %d %d", &L, &R, &value)   ;
            update(L + 1, value, n) ;
            update(R + 2, -value, n)    ;
        }
        scanf("%d", &Q) ;
        for (int i = 0; i < Q; i++){
            scanf("%d", &index) ;
            index += 1  ;
            cout << query(index) << "\n"    ;
        }
    }
    return 0    ;
}
