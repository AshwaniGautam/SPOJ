/*
The darkest places in the hell are reserved for those who maintain thier neutrality in time of moral crisis- Bertrand Zobrist.
Religion and GOD are the only shit between India and Development.
*/
#include<iostream>
#include<stdio.h>
using namespace std;

int arra[100007]   ;

struct node{
    int prefix, suffix, freq, pre_val, suf_val;
};

node tree [400009]  ;
void update(int index, int val, int low, int high, int pos){
    if (index > high || index < low)
        return  ;

    if (low == high){
        tree[pos].prefix = 1    ;
        tree[pos].suffix = 1    ;
        tree[pos].freq = 1  ;
        tree[pos].pre_val = val;
        tree[pos].suf_val = val;
        return  ;
        }
    int mid = (low+high) / 2    ;
    update(index, val, low, mid, 2*pos+1) ;
    update(index, val, mid+1, high, 2*pos+2)  ;
    tree[pos].pre_val = tree[2*pos+1].pre_val;
    tree[pos].suf_val = tree[2*pos+2].suf_val;
    tree[pos].prefix  = tree[2*pos+1].pre_val == tree[2*pos+2].pre_val ? tree[2*pos+1].prefix + tree[2*pos+2].prefix : tree[2*pos+1].prefix;
    tree[pos].suffix  = tree[2*pos+2].suf_val == tree[2*pos+1].suf_val ? tree[2*pos+2].suffix + tree[2*pos+1].suffix : tree[2*pos+2].suffix;
    tree[pos].freq    = max(max(tree[2*pos+1].freq, tree[2*pos+2].freq), tree[2*pos+1].suf_val == tree[2*pos+2].pre_val ? tree[2*pos+1].suffix + tree[2*pos+2].prefix : 0)  ;
    return  ;
}

void query(int i, int j, int low, int high, int pos, node &T){
    if (i == low && j == high){
        T.freq = tree[pos].freq;
        T.prefix = tree[pos].prefix ;
        T.pre_val = tree[pos].pre_val;
        T.suffix = tree[pos].suffix ;
        T.suf_val = tree[pos].suf_val;
        return ;
    }
    int mid = (low+high) / 2    ;
    if (j <= mid) return query(i, j, low, mid, 2*pos+1, T) ;
    else if (i > mid) return query(i, j, mid+1, high, 2*pos+2, T)  ;
    else{
        node Left, Right    ;
        query(i, mid, low, mid, 2*pos+1, Left)    ;
        query(mid+1, j, mid+1, high, 2*pos+2, Right)    ;
        T.freq = max(max(Left.freq, Right.freq), Left.suf_val == Right.pre_val ? Left.suffix + Right.prefix : 0)  ;
        T.pre_val = Left.pre_val;
        T.suf_val = Right.suf_val;
        T.prefix  = Left.pre_val == Right.pre_val ? Left.prefix  + Right.prefix : Left.prefix;
        T.suffix  = Right.suf_val == Left.suf_val ? Right.suffix + Left.suffix : Right.suffix;
        return ;
    }
}
int main(){
    int N, M, L, R, why    ;
    node T  ;
    while(true){
        scanf("%d", &N) ;
        if (N == 0)
            break   ;
        scanf("%d", &M) ;
        for (int i = 0; i < N; i++){
            scanf("%d", &arra[i])  ;
            update(i, arra[i], 0, N-1, 0)   ;
            }
    /*for (int i = 0; i < 40; i++)
        {
            printf("( %d %d %d %d %d )\n", tree[i].freq, tree[i].prefix, tree[i].pre_val, tree[i].suffix, tree[i].suf_val)  ;
        }*/

        while(M--){
            scanf("%d %d", &L, &R)  ;
            query(L-1, R-1, 0, N-1, 0, T)    ;
            printf("%d\n", T.freq)  ;
        }
        }
    return  0   ;
}
