/*
The Darkest places in the hell are reserved for those who maintain thier neutrality in the time of moral crisis- Bertrand Zobrist
Religion and God are the only shit between India and development.
*/

#include<stdio.h>
#include<iostream>

using namespace std;
int array[100009]   ;
struct node{
    int maximum = 0, sum = 0    ;
};
node tree[400009]   ;

void update(int index, int value, int low, int high, int pos){

    if (index > high || index < low)
        return ;
    if (low == high){
        tree[pos].maximum = value;
        return;
    }
    int mid = (low+high) / 2    ;
    update(index, value, low, mid, 2*pos+1) ;
    update(index, value, mid+1, high, 2*pos+2) ;
    tree[pos].sum = max(max(tree[2*pos+1].sum, tree[2*pos+2].sum), tree[2*pos+1].maximum + tree[2*pos+2].maximum)   ;
    tree[pos].maximum = max(tree[2*pos+1].maximum, tree[2*pos+2].maximum)   ;
    return  ;
}

void query(int i, int j, int low, int high, int pos, node &T){
    if (low == i && j == high){
        T.maximum = tree[pos].maximum   ;
        T.sum     = tree[pos].sum ;
        return  ;
    }
    int mid = (low+high) / 2    ;
    if (j <= mid)   query(i, j, low, mid, 2*pos+1, T) ;
    else if (mid < i) query(i, j, mid+1, high, 2*pos+2, T)  ;
    else{
        node L, R   ;
        query(i, mid, low, mid, 2*pos+1, L) ;
        query(mid+1, j, mid+1, high, 2*pos+2, R)    ;
        T.maximum = max(L.maximum, R.maximum) ;
        T.sum = max(max(L.sum, R.sum), L.maximum + R.maximum)    ;
    }
}

int main(){
    int N, M, L, R   ;
    char type;
    node T      ;
    cin >> N    ;
    for (int i = 0; i < N; i++){
        cin >> array[i] ;
        update(i, array[i], 0, N-1, 0)    ;
    }

    cin >> M    ;
    while(M--){
        cin >> type >> L >> R ;
        if (type == 'Q'){
            query(L-1, R-1, 0, N-1, 0, T)  ;
            cout << T.sum  << "\n";
        }
        else
            update(L-1, R, 0, N-1, 0) ;
    }
    return 0    ;
}
