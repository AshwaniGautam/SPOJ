#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <bitset>
#include <cmath>

using namespace std;

long long int array[100009]   ;
long long int ST[262150]  ;

void build(int low, int high, int pos){

    if (low == high){
        
        ST[pos] = array[low]    ;
        return;

    }

    int mid = (low+high) / 2    ;
    build(low, mid, 2*pos+1)    ;
    build(mid+1, high, 2*pos+2) ;

    ST[pos] = ST[2*pos+1] + ST[2*pos+2] ;

    return;
}

void update(int L, int R, int low, int high, int pos){

    if ( low > R || high < L)
         return     ;

    if (ST[pos] == (high - low + 1))
        return  ;

    if(low == high){

        ST[pos] = sqrt(ST[pos]) ;
        return;
    }

    int mid = (low+high) / 2    ;
    update(L, R, low, mid, 2*pos+1) ;
    update(L, R, mid+1, high, 2*pos+2)  ;

    ST[pos]  = ST[2*pos+1] +  ST[2*pos+2]   ;

    return ;
}

long long int query(int i, int j, int low, int high, int pos){

    if (high < i || low > j)
        return 0;

    if (i <= low && high <= j)
        return ST[pos]  ;

    int mid  = (low+high) /  2  ;
    return(query(i, j, low, mid, 2*pos+1) + query(i, j, mid+1, high, 2*pos+2))  ;

}

int main(){

        ios_base::sync_with_stdio(false);   cin.tie(0)  ;
        int N, L, R, M, type, test = 0   ;
        while(scanf("%d", &N) != EOF){

            test++  ;
            memset(ST, 0, sizeof ST)    ;
            for (int i = 0; i < N; i++)
                scanf("%lld", &array[i])  ;
            build(0, N - 1, 0)  ;
            scanf("%d", &M);

            printf("Case #%d:\n", test) ;
            while(M--){
                scanf("%d %d %d", &type, &L, &R)  ;

                if (!type)
                    update(min(L, R) - 1, max(L, R) - 1, 0, N-1, 0)    ;

                else
                    printf("%lld\n", query(min(L, R) - 1, max(L, R) - 1, 0, N-1, 0))    ;
            }
            printf("\n")    ;
    }
    return 0    ;
}
