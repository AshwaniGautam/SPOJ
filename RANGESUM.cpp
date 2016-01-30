#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std ;
vector <long long int> cumu  ;
int arr[100005] ;
int main(){
    int n, tmp, prev, Q, j = 1, L, R, size1   ;
    long long int ans = 0   ;
    char type  ;
    prev = 0    ;
    cin >> n    ;
    for (int i = 0; i < n; i++)
        cin >> arr[i]   ;
    cumu.push_back(0)   ;
    cumu.push_back(arr[n - 1])  ;
    for (int i = n - 2; i >= 0 ; i--, j++)
        cumu.push_back(cumu[j] + arr[i])    ;
    cin >> Q    ;
    size1 = n   ;
    while(Q--){
        cin >> type;
        if (type == '1'){
            cin >> L >> R   ;
            L = size1 - L + 1    ;
            R = size1 - R   ;
            ans = cumu[L] - cumu[R] ;
            cout << ans << "\n" ;

        }
        else{
            size1++  ;
            cin >> tmp  ;
            cumu.push_back(cumu[j] + tmp)   ;
            j++ ;

        }

    }

    return 0    ;
}
