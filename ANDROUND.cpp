/*
The darkest places in the hell are reserved for those who maintain thier neutrality in time of moral crisis.
Religion and GOD are the only shit between India and Development
*/
#include<stdio.h>
#include<iostream>
#include<bitset>
#include<math.h>
#include<string.h>
using namespace std;
int array[20005], solution[20005]   ;
int ST[80005]   ;

void build(int low, int high, int pos){
    if (high == low){
        ST[pos] = array[low]    ;
        return;
        }
    int mid = (low+high) / 2    ;
    build(low, mid, 2*pos+1)    ;
    build(mid+1, high, 2*pos+2) ;
    ST[pos] = ST[2*pos+1] & ST[2*pos+2] ;
    return;
}

int query(int i, int j, int low, int high, int pos){
    if (j < low || high < i)
        return 0x7fffffff;
    if (i <= low && high <= j)
        return ST[pos]  ;
    int mid = (low+high) / 2    ;
    return (query(i, j, low, mid, 2*pos+1) & query(i, j, mid+1, high, 2*pos+2))  ;
}
int main(){
    int T, N, K, ans ;
    scanf("%d", &T)    ;
    while(T--){
        ios_base::sync_with_stdio(false);   cin.tie(0)  ;
        memset(ST, 0, sizeof ST)   ;
        scanf("%d %d", &N, &K)   ;
        for(int i = 0; i < N; i++)
            scanf("%d", &array[i]) ;
        build(0, N-1, 0)    ;
        K = min(K, N / 2)   ;
        for (int i = 0; i < N; i++){
            int result = 0x7fffffff ;
            if (i + K > N - 1)
                result &= query(i, N - 1, 0, N - 1, 0) & query(0, (K - N + i) % N, 0, N - 1, 0)  ;
            else if (i + K <= N - 1)
                result &= query(i, i + K, 0, N - 1, 0)  ;
            if (i - K < 0)
                result &= query(0, i, 0, N - 1, 0) & query(N - K + i, N - 1, 0, N - 1, 0) ;
            else if (i - K >= 0)
                result &= query(i - K, i, 0, N - 1, 0)  ;

            printf("%d ", result);
        }
        printf("\n");
    }
    return  0;
}
