/*
The darkest places in the hell are reserved for those who maintain thier neutrality in times of moral crisis- Bertrand Zubrist
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#define INF 1000000
using namespace std;

struct node{

    int prefix_sum, suffix_sum, total_sum, solution ;

}  ;

node ST[131075]   ;
int array[50010]    ;


/*Why you don't use build, you think its cooler to call update for every element, let me tell you its not -_-. Build is cool, cooler then  your dumb ass boyfriend, get yourself a build*/

void build(int low, int high, int pos){

    if (low == high){

        ST[pos].solution   = array[low] ;
        ST[pos].prefix_sum = array[low] ;
        ST[pos].suffix_sum = array[low] ;
        ST[pos].total_sum  = array[low] ;

        return  ;

    }

    int mid =(low+high) / 2 ;
    build(low, mid, 2*pos+1)    ;
    build(mid+1, high, 2*pos+2) ;

    ST[pos].total_sum = ST[2*pos+1].total_sum + ST[2*pos+2].total_sum    ;
    ST[pos].solution = max(max(ST[2*pos+1].solution, ST[2*pos+2].solution), ST[2*pos+1].suffix_sum + ST[2*pos+2].prefix_sum)  ;
    ST[pos].prefix_sum =  max(ST[2*pos+1].total_sum + ST[2*pos+2].prefix_sum, ST[2*pos+1].prefix_sum)   ;
    ST[pos].suffix_sum =  max(ST[2*pos+2].total_sum + ST[2*pos+1].suffix_sum, ST[2*pos+2].suffix_sum)   ;

    return ;
}


void update(int index, int low, int high, int pos){

    if (index < low || index > high)
        return  ;

    if(low == high){

        ST[pos].prefix_sum = array[index]      ;
        ST[pos].suffix_sum = array[index]      ;
        ST[pos].solution   = array[index]      ;
        ST[pos].total_sum  = array[index]      ;
        return  ;

    }

    int mid = (low+high) / 2    ;
    update(index, low, mid, 2*pos + 1)    ;
    update(index, mid + 1, high, 2*pos + 2) ;

    ST[pos].total_sum = ST[2*pos+1].total_sum + ST[2*pos+2].total_sum    ;
    ST[pos].solution = max(max(ST[2*pos+1].solution, ST[2*pos+2].solution), ST[2*pos+1].suffix_sum + ST[2*pos+2].prefix_sum)  ;
    ST[pos].prefix_sum =  max(ST[2*pos+1].total_sum + ST[2*pos+2].prefix_sum, ST[2*pos+1].prefix_sum)   ;
    ST[pos].suffix_sum =  max(ST[2*pos+2].total_sum + ST[2*pos+1].suffix_sum, ST[2*pos+2].suffix_sum)   ;

    return;
}

void query(int i, int j, int low, int high, int pos, node &T){

    if (j < low || high < i){

        T.solution   = -INF    ;
        T.prefix_sum = -INF    ;
        T.suffix_sum = -INF    ;
        T.total_sum  =    0    ;

        return  ;

    }

    if (i <= low && high <= j){

        T.solution   = ST[pos].solution    ;
        T.prefix_sum = ST[pos].prefix_sum  ;
        T.suffix_sum = ST[pos].suffix_sum  ;
        T.total_sum  = ST[pos].total_sum   ;

        return  ;

    }

    int mid = (low + high) / 2    ;
    node left, right    ;

    query(i, j, low, mid, 2*pos+1, left)  ;
    query(i, j, mid+1, high, 2*pos+2, right)    ;

    T.solution = max(max(left.solution, right.solution),left.suffix_sum+right.prefix_sum) ;
    T.prefix_sum = max(left.total_sum + right.prefix_sum, left.prefix_sum)  ;
    T.suffix_sum = max(left.suffix_sum+right.total_sum, right.suffix_sum)   ;
    T.total_sum = left.total_sum + right.total_sum  ;

}


int main(){
    node T  ;
    int n, L, R, m, type   ;
    int ans = 0   ;
    scanf("%d", &n)    ;

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i])  ;

    build(0, n-1, 0)    ;

    scanf("%d", &m)    ;
    while(m--){
        scanf("%d %d", &L, &R)  ;
            query(L-1, R-1, 0, n-1, 0, T)  ;
            printf("%d\n", T.solution) ;
    }
    return 0    ;
}
