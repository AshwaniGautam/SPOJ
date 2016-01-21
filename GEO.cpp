#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int t   ;
    int a, b, c ;
    long long int x_intercept, y_intercept    ;
    long long int area  ;
    cin >> t    ;
    while (t--){
        cin >> a >> b >> c  ;
        x_intercept = c / b ;
        y_intercept = c / a ;
        area = (x_intercept * y_intercept) / 2  ;
        if (area < 0)
            area *= -1  ;
        cout << area << "\n"    ;
    }

}
