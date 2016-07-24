/*
The darkest places in the earth are reserved for those who maintain thier neutrality in the time of moral crisis- Bertrand Zobrist
Religion and GOD are the only shit between India and Development.
*/
#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int mod_1, mod_2, ans, lazy   ;
};

node tree[400009]   ;

void build(int low, int high, int pos){
    if (high == low){
        tree[pos].ans = 1;
        tree[pos].mod_1 = 0 ;
        tree[pos].mod_2 = 0 ;
        tree[pos].lazy =   0;
        return ;
    }
    int mid = (low+high) / 2    ;
    build(low, mid, 2*pos+1)  ;
    build(mid+1, high, 2*pos+2);
    tree[pos].ans = high - low + 1  ;
    tree[pos].mod_1 = 0 ;
    tree[pos].mod_2 = 0 ;
    tree[pos].lazy =   0;
    return;
}


void update(int i, int j, int low, int high, int pos){
    if (tree[pos].lazy){
        if (tree[pos].lazy % 3 == 1){
            int swap = tree[pos].mod_2    ;
            tree[pos].mod_2 = tree[pos].mod_1   ;
            tree[pos].mod_1 = tree[pos].ans ;
            tree[pos].ans = swap;
        }
        else
            if(tree[pos].lazy % 3 == 2){
                int swap = tree[pos].mod_1    ;
                tree[pos].mod_1 = tree[pos].mod_2 ;
                tree[pos].mod_2 = tree[pos].ans   ;
                tree[pos].ans = swap;
            }
        if (high != low){
            tree[2*pos+1].lazy += tree[pos].lazy;
            tree[2*pos+2].lazy += tree[pos].lazy;
        }
        tree[pos].lazy = 0  ;
    }
    if (low > j || high < i)
        return ;
    if (i <= low && high <= j){
        int swap = tree[pos].mod_2    ;
        tree[pos].mod_2 = tree[pos].mod_1   ;
        tree[pos].mod_1 = tree[pos].ans ;
        tree[pos].ans = swap   ;
        if (low != high){
            tree[2*pos+1].lazy ++;
            tree[2*pos+2].lazy ++;
            }
        return;
    }
    int mid = (low+high) / 2    ;
    update(i, j, low, mid, 2*pos+1) ;
    update(i, j, mid+1, high, 2*pos+2)  ;
    tree[pos].lazy = 0  ;
    tree[pos].mod_1 = tree[2*pos+1].mod_1 + tree[2*pos+2].mod_1 ;
    tree[pos].mod_2 = tree[2*pos+1].mod_2 + tree[2*pos+2].mod_2 ;
    tree[pos].ans = tree[2*pos+1].ans + tree[2*pos+2].ans ;
    return  ;
}

int query(int i, int j, int low, int high, int pos){
    if (tree[pos].lazy){
        if (tree[pos].lazy % 3 == 1){
            int swap = tree[pos].mod_2    ;
            tree[pos].mod_2 = tree[pos].mod_1   ;
            tree[pos].mod_1 = tree[pos].ans ;
            tree[pos].ans = swap;
        }
        else
            if(tree[pos].lazy % 3 == 2){
                int swap = tree[pos].mod_1    ;
                tree[pos].mod_1 = tree[pos].mod_2 ;
                tree[pos].mod_2 = tree[pos].ans   ;
                tree[pos].ans = swap;
            }
        if (high != low){
            tree[2*pos+1].lazy += tree[pos].lazy;
            tree[2*pos+2].lazy += tree[pos].lazy;
        }
        tree[pos].lazy = 0  ;
    }
    if (low > j || high < i)
        return 0;
    if (i <= low && high <= j)
        return tree[pos].ans    ;
    int mid = (low+high) / 2    ;
    return (query(i, j, low, mid, 2*pos+1)  +    query(i, j, mid+1, high, 2*pos+2));
}
int main(){
    int N, Q, type, L, R    ;
    scanf("%d %d", &N, &Q)   ;
    build(0, N-1, 0)    ;
    while(Q--){
        scanf("%d %d %d", &type, &L, &R)    ;
        if (type){
            printf("%d\n", query(L, R, 0, N-1, 0))  ;
        }
        else
            update(L, R, 0, N-1, 0) ;
    }
    return 0    ;
}
