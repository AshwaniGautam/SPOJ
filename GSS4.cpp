#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int array[100009]   ;
int ST[500005], flag[100009]  ;

void update(int index, int low, int high, int pos, int inv){
    if (index > high || index < low) return     ;
    if(low == high){
        if (inv){
            ST[pos] = array[index]  ;
        }
        else{
            ST[pos] = int(pow(ST[pos], 0.5)) ;
            if (ST[pos] == 1)
                flag[index] = 0;
        }
        return;
    }

    int mid = (low+high) / 2    ;
    update(index, low, mid, 2*pos+1, inv)    ;
    update(index, mid+1, high, 2*pos+2, inv) ;
    ST[pos] = ST[2*pos+1] + ST[2*pos+2] ;
    return ;
}

long long int query(int i, int j, int low, int high, int pos){
    if (high < i || low > j)
        return 0;
    if (i <= low && high <= j)
        return ST[pos]  ;
    int mid  = (low+high) /  2  ;
    long long int a = query(i, j, low, mid, 2*pos+1)    ;
    long long int b = query(i, j, mid+1, high, 2*pos+2)  ;
    long long int c = a + b;
    return c    ;
}

int main(){
    int N, L, R, M, type, test = 0   ;
    while(scanf("%d", &N) != 0){
        test++  ;
        memset(ST, 0, sizeof ST)    ;
        memset(array, 0, sizeof ST) ;
        memset(flag, 1, sizeof flag)    ;
        for (int i = 0; i < N; i++){
            scanf("%d", &array[i])  ;
            update(i, 0, N-1, 0, 1) ;
        }
        scanf("%d", &M);
        /*for (int i = 0; i < 17; i++)
            cout << ST[i] << " "    ;
        for (int i = 0; i < 8; i++)
            cout << array[i] << " " ;
        cout << endl;*/
        printf("Case #%d:\n", test) ;
        while(M--){
            scanf("%d %d %d", &type, &L, &R)  ;
            L = min(L, R)   ;
            R = max(L, R)   ;
            if (!type)
                for (int i = L-1; i < R; i++){
                    if (flag[i]){
                        update(i, 0, N-1, 0, 0)    ;
                    }
                }
            else{
                printf("%lld\n", query(L-1, R-1, 0, N-1, 0))    ;
            }
        }
        printf("\n")    ;
    }
    return 0    ;
}
