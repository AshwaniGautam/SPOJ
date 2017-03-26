/*
    Space : O(NlogN)
    Pre_processing : O(NlogN)
    Query : O(logN)

*/

#include<bits/stdc++.h>

using namespace std ;

int last_ans = 0, N, Q  ;
int arr[30003]  ;
vector<int>ST[120004]   ;

inline void build(int low, int high, int pos){

    if(low == high){
        ST[pos].push_back(arr[low]) ;
        return  ;
    }
    int mid = (low + high) / 2  ;
    build(low, mid, 2*pos+1)    ;
    build(mid+1, high, 2*pos+2) ;
    merge(ST[2*pos+1].begin(), ST[2*pos+1].end(), ST[2*pos+2].begin(), ST[2*pos+2].end(), back_inserter(ST[pos]))  ;
}

inline int query(int i, int j, int low, int high, int pos, int value){

    if(j < low || i > high)
        return 0    ;

    if(i <= low && high <= j)
        return ST[pos].size() - (upper_bound(ST[pos].begin(), ST[pos].end(), value) - ST[pos].begin()) ;

    int mid = (low + high) / 2  ;
    return query(i, j, low, mid, 2*pos+1, value) + query(i, j, mid+1, high, 2*pos+2, value);
}

int main(){
    cin.sync_with_stdio(false)  ;
    cin >> N    ;
    for(int i = 0; i < N; i++)
        cin >> arr[i]   ;

    build(0, N-1, 0)    ;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int a, b, c ;
        cin >> a >> b >> c  ;

        a ^= last_ans   ;
        b ^= last_ans   ;
        c ^= last_ans   ;

        last_ans = query(a-1, b-1, 0, N-1, 0, c)    ;
        cout << last_ans << endl ;
    }
    return 0;
}
