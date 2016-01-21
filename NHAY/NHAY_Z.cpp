#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#define MAX_N 5000000
using namespace std;
string needle	;
string haystack	;
string concat   ;

long long int min(long long int a, long long int b){
	if (a > b)
		return b	;
	return a		;
}
void z_function(string s, long long int n, long long int t){
    long long int z[n]	;
    for(int i = 0; i < n;  i++)
    	z[i] = 0	;
	int s1 ;
    for(long long int i = 1, l = 0,  r = 0; i < n; i++){
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1)  ;
        while(i + z[i] < n && concat[z[i]] == concat[i + z[i]])
            z[i]++ ;
        if (i + z[i] -1 > r){
            l = i   ;
            r = i + z[i] - 1 ;
        }
    }
    s1 = 0	;
    for(long long int i = t + 1; i < concat.length() - t + 1; i++){
                if (z[i] == t){
                    s1 = 1;
                    cout << i - t - 1 << "\n"  ;
            }
        }
    if (s1 == 1)
        cout << "\n\n"  ;
}
int main()  {
    long long int t ;
    while(scanf ("%lld\n",  &t) == 1){
        	cin >> needle >> haystack	;
        	concat = needle + '&' + haystack  ;
        	z_function(concat,concat.length(),t)    ;
    }
}
