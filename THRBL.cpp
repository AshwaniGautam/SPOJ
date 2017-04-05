#include<bits/stdc++.h>

using namespace std;

int arr[50000], ST[200000]  ;
int N, M, ans    ;

inline void build(int low, int high, int pos){

    if(low==high){
        ST[pos] = arr[low]  ;
        return ;
    }
    int mid = (low + high) / 2  ;
    build(low, mid, 2*pos+1);
    build(mid+1, high, 2*pos+2) ;
    ST[pos] = max(ST[2*pos+1], ST[2*pos+2]) ;

}

inline int query(int i, int j, int low, int high, int pos){

    if(j < low || i > high)
        return 0    ;
    if(i <= low && high <= j)
        return ST[pos]  ;
    int mid = (low+high) / 2    ;
    return max(query(i, j, low, mid, 2*pos+1), query(i, j, mid+1, high, 2*pos+2))   ;
}
int main(){

    cin.sync_with_stdio(false)  ;
    cin >> N  >> M     ;
    for(int i = 0; i < N; i++)
        cin >> arr[i]   ;

    build(0, N-1, 0)    ;
    for(int i = 0; i < M; i++){
        int u, v    ;
        cin >> u >> v ;
        v -= 2;
        if(v < u)
            ans++  ;
        else
            if(query(u, v, 0, N-1, 0) <= arr[u-1])
                ans++   ;
    }
    cout << ans << "\n" ;

    return 0    ;
}
