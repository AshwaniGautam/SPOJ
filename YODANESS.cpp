#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
using namespace std;
char string1[25] ;
int BIT[30007]  ;
map <string, int> eval  ;
vector<string> s    ;
void update(int idx, int n){
    for (; idx <= n; idx += idx & -idx)
        BIT[idx] += 1   ;
}
int query(int L, int R){
    int Left = 0, Right = 0 ;
    for (; L > 0; L -= L & -L)
        Left += BIT[L]  ;
    for(; R > 0; R -= R & -R)
        Right += BIT[R] ;

    return (Right - Left)   ;
}
int main(){
    int t, n    ;
    string s1, s2    ;
    long long int ans  ;
    cin >> t   ;
    while(t--){
        ans = 0 ;
        memset(BIT, 0, sizeof BIT)  ;
        cin >> n   ;
        for (int i = 0; i < n; i++){
            scanf("%s", string1)    ;
            s.push_back(string1)    ;
        }
        for (int i = 0; i < n ; i++){
            scanf("%s", string1)    ;
            eval[string1] = i + 1   ;
        }

        for(int i = 0; i < n ;i++){
            int j = eval[s[i]]      ;
            ans += query(j, n) ;
            update(j, n)    ;

        }
        cout << ans << endl;
        s.clear()   ;
    }

    return 0    ;
}
