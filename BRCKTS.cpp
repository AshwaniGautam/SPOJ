/*
The darkest places in the hell are reserved for those who maintain thier neutrality in the time of moral crisis- Bertrand Zobrist
Religion and GOD are the only shit between India and Development.
*/
#include<stdio.h>
#include<iostream>
using namespace std ;

struct node{
    int open, close ;
};

node tree[120009]   ;

void update(int index, char value, int low, int high, int pos){

    if (index > high || index < low)
        return  ;

    if (low == high){
        //cout << value ;
        if (value == '('){
            tree[pos].open = 1 ;
            tree[pos].close = 0 ;
            }
        else{
            tree[pos].close = 1;
            tree[pos].open = 0  ;
            }
        return  ;
    }

    int mid = (low+high) / 2    ;
    update(index, value, low, mid, 2*pos+1) ;
    update(index, value, mid+1, high, 2*pos+2)  ;
    tree[pos].open = tree[2*pos+2].open + max(tree[2*pos+1].open - tree[2*pos+2].close, 0)   ;
    tree[pos].close = tree[2*pos+1].close + max(tree[2*pos+2].close - tree[2*pos+1].open, 0) ;
}

char array[30005]   ;
int main(){
    int T = 10, N, M, op  ;
    while(T--){
        printf("Test %d:\n",(10-T)) ;
        scanf("%d", &N) ;
        scanf("%s", array)   ;
        for(int i = 0; i < N; i++)
            update(i, array[i], 0, N-1, 0)  ;
        /*for(int i = 0; i <= 7; i++)
            cout << tree[i].open << " " << tree[i].close << endl;*/
        scanf("%d", &M) ;
        while(M--){
            scanf("%d", &op)    ;
            if (op){
                if (array[op-1] == '('){
                    char l = ')'    ;
                    update(op-1, l, 0, N-1, 0)    ;
                    array[op-1] = ')'   ;
                }
                else{
                    char l = '('    ;
                    update(op-1, l, 0, N-1, 0)    ;
                    array[op-1] = '('   ;
            }
        }
        else
        {
            if (tree[0].open == 0 && tree[0].close == 0)
                printf("YES\n") ;
            else
                printf("NO\n")  ;
                }

        }
    }
    return 0    ;
}
