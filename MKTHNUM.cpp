#include <bits/stdc++.h>

using namespace std;

/*
    Pre-Processing : O(QlogQ)
    update: O(logN)
    query: O(logN)
    Running Time : O( (N + Q) ROOT(N) logN) ~ O(N ROOT(N) logN) > 10^5 * 10^2 * 10 = 10^8 TLE :(

*/

/*  Will do after learning Persistence Segment Tree :) */

struct node{

    int left, right, k , idx;

};

int N, Q, BLOCK_SIZE    ;
int arr[100002] ;
node queries[5002]  ;
int answers[5002]   ;
set<int> myset ;
unordered_map<int, int> mymap;
unordered_map<int, int> reverse_map ;
int ST[370000]   ;

inline void update(int idx, int low, int high, int pos, int value){

    if(idx < low || idx > high)
        return ;
    if(low == high){
        ST[pos] += value;
        return ;
    }
    int mid = (low + high) / 2  ;
    update(idx, low, mid, 2*pos+1, value)   ;
    update(idx, mid+1, high, 2*pos+2, value)    ;
    ST[pos] = ST[2*pos+1]  + ST[2*pos+2]   ;
}

inline int query(int low, int high, int pos, int k) {

    if(low == high)
        return low    ;

    int mid = (low + high) / 2  ;

    if(ST[2*pos+1] >= k)
        return query(low, mid, 2*pos+1, k)  ;

    else
        return query(mid+1, high, 2*pos+2, k - ST[2*pos+1])   ;

}

inline bool cmp(node x, node y){

    int x_block = x.left / BLOCK_SIZE   ;
    int y_block = y.left / BLOCK_SIZE   ;

    if(x_block != y_block)
        return x_block < y_block    ;
    return x.right < y.right    ;
}

int main(){

    cin.sync_with_stdio(false)  ;
    cin >> N >> Q   ;

    BLOCK_SIZE = static_cast<int>(sqrt(N))  ;

    for(int i = 0; i < N; i++){
        cin >> arr[i]   ;
        myset.insert(arr[i])    ;
    }

    int iter = 0    ;
    for(auto it : myset){
        mymap[it] = iter ;
        reverse_map[iter] = it  ;
        iter++  ;
    }

    for(int i = 0; i < N; i++)
        arr[i] = mymap[arr[i]]  ;

    for(int i = 0; i < Q; i++){
        int u, v, z ;
        cin >> u >> v >> z  ;
        u-- ; v --;
        queries[i].left = u ;
        queries[i].right = v    ;
        queries[i].k = z    ;
        queries[i].idx = i  ;
    }

    sort(queries, queries + Q, cmp) ;

    int m_left = queries[0].left ;
    int m_right = m_left - 1    ;

    for(int i = 0; i < Q; i++){

        int left = queries[i].left  ;
        int right = queries[i].right    ;

        while(m_right > right){
            update(arr[m_right], 0, N-1, 0, -1) ;
            m_right--   ;
        }
        while(m_right < right){
            m_right++  ;
            update(arr[m_right], 0, N-1, 0, 1)  ;
        }
        while(m_left > left){
            m_left--    ;
            update(arr[m_left], 0, N-1, 0, 1)  ;
        }
        while(m_left < left){
            update(arr[m_left], 0, N-1, 0, -1)  ;
            m_left++    ;
        }
        answers[queries[i].idx] = query(0, N-1, 0, queries[i].k)   ;
    }
    for(int i = 0; i < Q; i++)
        cout << reverse_map[answers[i]] << "\n"  ;
    return 0    ;
}
