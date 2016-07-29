#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector <int> array(10000);

long long int merge(int start, int end){
    int mid = (start+end) >>  1   ;
    int m = array[mid]  ;
    int j = 0   ;
    if (m == array[mid])
        j = mid ;
    else
        j = mid+1   ;
    long long int sol = 0 ;
    int i = j   ;
    while(i <= end && m <= array[i]){
        sol += m    ;
        i ++      ;
    }
    i = j - 1   ;
    while(i >= 0 && m <= array[i]){
        sol += m    ;
        i --      ;
    }
    return sol  ;

}

long long int solve(int start, int end){
    if (start == end)
        return array[start];

    int mid = (start+end) >> 1   ;
    long long int a = solve(start, mid) ;
    long long int b = solve(mid+1, end) ;
    long long int c = merge(start, end)   ;
    return max(max(a, b), c)    ;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int size, k;

    while(1){
        scanf("%d", &size)  ;
        if (size == 0)
            return 0;
        for (int i = 0; i < size; i++){
            scanf("%d", &array[i])  ;
            }
        printf("%lld\n", solve(0, size-1))    ;
    }
}
