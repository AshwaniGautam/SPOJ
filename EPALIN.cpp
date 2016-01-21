#include<bits/stdc++.h>
#define N 100005
using namespace std		;
string original ;
string rev  ;
string medium   ;
vector <int> vec (N,0)    ;

using namespace std;
void z_function(){
    int left  = 0   ;
    int right = 0   ;
    int n = medium.size()    ;
    for (int i = 1; i < n; i++){

        if (i <= right)
            vec[i] = min(right - i + 1, vec[i - left]) ;

        while (i + vec[i] < n  && medium[vec[i]] == medium[i + vec[i]])
            vec[i]++    ;

        if (i + vec[i] -1 > right){
            right = i + vec[i] - 1  ;
            left = i    ;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);   cin.tie(0)  ;
    while(!cin.eof()){
            cin >> rev ;
            original = rev;
            reverse(rev.begin(), rev.end())   ;
            medium = rev + original ;
            z_function()   ;
            int n = original.size()	;
            int m = 2 * n	;
           for(int i = n; i < m; i++)
           		if (m - i == vec[i]){
                        cout << original    ;
           			for (int j  = n - vec[i] - 1; j >= 0; j--)
           				cout << original[j] ;
                    break;

           		}
            cout << "\n"    ;
            for (int i = 0; i < m; i++)
                vec[i] = 0  ;
    }
    return  0;
}
