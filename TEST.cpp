#include<stdio.h>
#include<iostream>
#include<string>
using namespace std ;
string one  ;
string two  ;
char str[100]   ;
int main(){
    getline(cin, one)   ;
    scanf("%s", str)    ;
    getline(cin, two)   ;
    printf("%s", str)   ;
    cout << "1" << one << "1";
    cout << "2" << two << "2";
    return 0    ;
}

