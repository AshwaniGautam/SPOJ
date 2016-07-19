/*
The darkest places in the hell are reserved for those who maintain thier neutrality in times of moreal crisis- Bertrand Zubrist
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

struct node{    int prefix_sum, suffix_sum, total_sum, solution ;   }   ;

int prefix_sum[300009], suffix_sum[300009], total_sum[300009], solution[300009]  ;
int array[55000]    ;


void update(int index, int value, int low, int high, int pos){

    if (index < low || index > high)
        return  ;

    if(low == high){
        prefix_sum[pos] = value    ;
        suffix_sum[pos] = value    ;
        solution[pos]   = value    ;
        total_sum[pos]  = value    ;
        return  ;
    }

    int mid = (low+high) / 2    ;
    update(index, value, low, mid, 2*pos+1)    ;
    update(index, value, mid+1, high, 2*pos+2) ;

    total_sum[pos] = total_sum[2*pos+1] + total_sum[2*pos+2]    ;
    solution[pos] = max(max(solution[2*pos+1], solution[2*pos+2]), suffix_sum[2*pos+1]+prefix_sum[2*pos+2])  ;

    prefix_sum[pos] =  max(total_sum[2*pos+1] + prefix_sum[2*pos+2], prefix_sum[2*pos+1])   ;
    suffix_sum[pos] =  max(total_sum[2*pos+2] + suffix_sum[2*pos+1], suffix_sum[2*pos+2]);

    return;
}

void query(int i, int j, int low, int high, int pos, node &T){

    if (low == i && high == j){
        T.solution   = solution[pos]    ;
        T.prefix_sum = prefix_sum[pos]  ;
        T.suffix_sum = suffix_sum[pos]  ;
        T.total_sum  = total_sum[pos]   ;
        return  ;
    }

    int mid = (low+high) / 2    ;
    if (j<=mid)
        query(i, j, low, mid, 2*pos+1, T)   ;
    else if (mid < i)
        query(i, j, mid+1, high, 2*pos+2, T)    ;
    else{
        node left, right    ;
        query(i, mid, low, mid, 2*pos+1, left)  ;
        query(mid+1, j, mid+1, high, 2*pos+2, right)    ;

        T.solution = max(max(left.solution, right.solution),left.suffix_sum+right.prefix_sum) ;
        T.prefix_sum = max(left.total_sum + right.prefix_sum, left.prefix_sum)  ;
        T.suffix_sum = max(left.suffix_sum+right.total_sum, right.suffix_sum)   ;
        T.total_sum = left.total_sum + right.total_sum  ;

    }
}


int main(){
    node T  ;
    int n, L, R, m, type   ;
    int ans = 0   ;
    scanf("%d", &n)    ;

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i])  ;

    for (int i = 0; i < n; i++){
        update(i, array[i], 0, n-1, 0)    ;
    }

    scanf("%d", &m)    ;
    while(m--){
        scanf("%d %d %d", &type, &L, &R)  ;
        if (type){
            query(L-1, R-1, 0, n-1, 0, T)  ;
            printf("%d\n", T.solution) ;
        }
        else
            update(L-1, R, 0, n-1, 0)   ;
    }
    return 0    ;
}
