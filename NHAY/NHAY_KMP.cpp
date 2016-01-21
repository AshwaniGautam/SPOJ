#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string needle;
string haystack;
string lesss    ;
vector<int> pi   ;
void Prefix_Function(string needle, long long int M){
    pi.push_back(0) ;
    long long int k = 0 ;
    for (long long int i = 1; i < M; i++){
        //cout << k << " " << i << " " << needle[k] << " " << needle[i] <<endl;
        while(needle[k] != needle[i]){
            if (!k)
                break   ;
            k = pi[k - 1]   ;
        }
        if (needle[k] == needle[i])
            k += 1  ;
        pi.push_back(k) ;
    }
    return  ;
}

void KMP(string needle, string haystack, long long int M){
    long long int N = haystack.length() ;
    long long int q = 0 ;
    int flag = 0    ;
    Prefix_Function(needle,M)   ;
    for (long long int i = 0; i < N; i++){
        while (needle[q] != haystack[i]){
            if (!q)
                break   ;
            q = pi[q - 1]   ;
        }
        if (needle[q] == haystack[i])
            q += 1  ;

        if (q == M){
            flag = 1    ;
            cout << i - M + 1 << "\n";
            q = pi[q - 1]   ;
        }
    }
    pi.clear()  ;
    if (flag)
        cout << "\n"   ;
    return ;
}
int main(){
    long long int n ;
    while(scanf("%lld", &n) == 1){
        getline(cin, lesss) ;
        getline(cin, needle);
        getline(cin, haystack)  ;
//        printf("%s %s", needle, haystack)   ;
//        cout << needle << " " << haystack   << endl;
        KMP(needle, haystack , n)   ;

    }
    return 0    ;
}
