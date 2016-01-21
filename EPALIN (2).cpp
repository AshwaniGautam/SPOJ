#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<string.h>
using namespace std ;
#define mod 1000000007
string original  ;
string rev  ;
vector <int> original_hash, rev_hash  ;

long long int binary_exp(int base, int exp){
    if (exp == 0)
        return 1    ;
    long long int res = binary_exp(base, exp/2) ;
    if (exp % 2)
        return (base %mod * (res % mod * res % mod)% mod)%mod ;
    return (res % mod * res % mod) % mod    ;
}

void original_func (int n){
    original_hash.push_back(rev[0]) ;
    int b = 101	;
    for (int i = 1; i < n; i++)
        original_hash.push_back( (original_hash[i - 1] + rev[i] * binary_exp(b, i))% mod )   ;
}


void rev_func (int n){
    rev_hash.push_back(rev[0])  ;
    long long int b = 101	;
    for(int i = 1; i < n; i++)
        rev_hash.push_back( (rev_hash[i - 1] * (b)  + rev[i])% mod )  ;

}



int main(){
    ios_base::sync_with_stdio(false)    ;   cin.tie()   ;
    while(!cin.eof()){
        cin >> original ;

        rev.clear() ;
        original_hash.clear()	;
        rev_hash.clear()	;

        int lenth = original.length()   ;

        for (int i = lenth - 1; i >= 0; --i)
            rev += original[i]  ;

        if (original == rev){
            cout << original<< "\n" ;
            continue;
        }

        original_func(lenth);
        rev_func(lenth) ;


		int g;
		for(int i = lenth - 1; i >= 0; i--){
			if (original_hash[i] == rev_hash[i]){
				g = i	;
				break;
			}
		}
		cout << original;
		for(g = lenth - 2- g; g >= 0; g-- )
			cout << original[g]	;
		cout << "\n"	;

    }
    return 0    ;
}
