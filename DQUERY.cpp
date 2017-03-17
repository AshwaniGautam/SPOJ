#include <bits/stdc++.h>

using namespace std;

struct node{

    int left, right, idx    ;

};

int N, Q;
int arr[300004]  ;
node queries[200002]    ;
int BLOCK_SIZE  ;
int answers[200002] ;
int check[1000009]    ;

inline int add(int x){

    check[x]++  ;
    if (check[x] == 1)
        return 1   ;
    return 0    ;
}

inline int remove(int x){

    check[x]--  ;
    if (check[x] == 0)
        return -1   ;
    return 0;
}

inline bool cmp(const node x, const node y){

    int x_block = x.left / BLOCK_SIZE   ;
    int y_block = y.left / BLOCK_SIZE   ;

    if (x_block!=y_block)
        return x_block < y_block    ;
    return x.right < y.right    ;

}

int main(){

    cin.sync_with_stdio(false)  ;
    cin >> N    ;
    BLOCK_SIZE = static_cast<int>(sqrt(N))  ;

    for(int i = 0; i < N; i++)
        cin >> arr[i]   ;

    cin >> Q    ;
    for(int i = 0; i < Q; i++){
        cin >> queries[i].left >> queries[i].right ;
        queries[i].left-- ;
        queries[i].right--;
        queries[i].idx = i    ;
    }

    sort(queries, queries + Q, cmp) ;

    int m_left = queries[0].left    ;
    int m_right = m_left-1  ;
    int curr_answer     ;

    for(int i = 0; i < Q; i++){

        int left = queries[i].left    ;
        int right=queries[i].right    ;

        while(m_right < right){
            m_right++   ;
            curr_answer += add(arr[m_right])   ;
        }
        while(m_right > right){
            curr_answer += remove(arr[m_right]) ;
            m_right--   ;
        }
        while(m_left < left){
            curr_answer += remove(arr[m_left])  ;
            m_left++    ;
        }
        while(m_left > left){
            m_left--    ;
            curr_answer += add(arr[m_left]) ;
        }
        answers[queries[i].idx] = curr_answer ;
    }

    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n"  ;
    return 0    ;
}
