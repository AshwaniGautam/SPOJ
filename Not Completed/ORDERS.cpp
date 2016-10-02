/*
The darkest places in the hell are reserved for those who maintain thier neutrality in the time of moral crisis- Bertrand Zobrist
Religion and GOD are the only shit between India and Development.
*/
#include<stdio.h>
#include<iostream>
using namespace std;
int array[200000]   ;

struct node{
    int lazy, value;
};
node tree[800000]   ;

void build(int index, int val, int low, int high, int pos){
    if (index < low || index > high)
        return  ;
    if (low == high){
        tree[pos].value = val;
        return ;
        }
    int mid = (low+high) / 2    ;
    build(index, val, low, mid, 2*pos+1)   ;
    build(index, val, mid+1, high, 2*pos+2) ;
    return;
}

void update(int i, int j, int val, int low, int high, int pos){
    if (tree[pos].lazy){
        if (high!=low){
            tree[2*pos+1].lazy += tree[pos].lazy;
            tree[2*pos+2].lazy += tree[pos].lazy;
            }
        tree[pos].value += tree[pos].lazy ;
        tree[pos].lazy = 0  ;
    }
    if (low > j || high < i)
        return ;
    if (i <= low && high <= j){
        if (low!=high){
            tree[2*pos+1].lazy += 1;
            tree[2*pos+2].lazy += 1;
            return ;
        }
        tree[pos].value += val  ;

        return ;
        }
    int mid = (low+high) / 2    ;
    update(i, j, val, low, mid, 2*pos+1)  ;
    update(i, j, val, mid+1, high, 2*pos+2)   ;
    return  ;
}
int query(int index, int low, int high, int pos){
    if (tree[pos].lazy){
        if (high!=low){
            tree[2*pos+1].lazy += tree[pos].lazy;
            tree[2*pos+2].lazy += tree[pos].lazy;
            }
        tree[pos].value += tree[pos].lazy ;
        tree[pos].lazy = 0  ;
    }

    if (index < low || index > high)
        return 0;

    if (low == high){
        return tree[pos].value  ;
        }

    int mid = (low+high) / 2    ;
    return (query(index, low, mid, 2*pos+1) + query(index, mid+1, high, 2*pos+2));
}

int main(){
    int T, N;
    scanf("%d", &T) ;
    while(T--){
        scanf("%d", &N) ;
        for (int i = 0; i < N; i++){
            scanf("%d", &array[i])  ;
            build(i, i+1, 0, N-1, 0)    ;
        }
        /*for (int i = 0; i < 20; i++)
        cout << tree[i].value << " "  ;
            cout << endl;*/
        for (int i = 0; i < N; i++){
            update(i, i, -1 * array[i], 0, N-1, 0)  ;
            for (int i = 0; i < 20; i++)
            cout << tree[i].value << " "  ;
            cout << endl;
            update(i - array[i], i-1, 1, 0, N-1, 0)  ;
            for (int i = 0; i < 20; i++)
            cout << tree[i].value << " "  ;
            cout << endl;
        }
        for (int i = 0; i < 20; i++)
            cout << tree[i].value << " "  ;

        cout << endl;

        for (int i = 0; i < 20; i++)
            cout << tree[i].lazy << " "  ;

        for(int i = 0; i < N; i++)
            printf("%d ", query(i, 0, N-1, 0))  ;
        printf("\n")    ;

        for (int i = 0; i < 20; i++)
            cout << tree[i].value << " "  ;

        cout << endl;

        for (int i = 0; i < 20; i++)
            cout << tree[i].lazy << " "  ;

    }
    return 0    ;
}
