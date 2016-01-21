#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#define N1 1000
using namespace std;
vector <int> dict (N1,0)   ;

float area(int x1, int y1, int x2, int y2, int x3, int y3){
    float ans  = abs(float(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))) / 2.0    ;
    return ans  ;
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int pa, int pb){
    float area1 = area(pa, pb, x1, y1, x2, y2)  ;
    float area2 = area(pa, pb, x1, y1, x3, y3)  ;
    float area3 = area(pa, pb, x2, y2, x3, y3)  ;
    float total = area(x1, y1, x2, y2, x3, y3)  ;

    if (abs(area1 + area2 + area3  - total) <= 0.000001)
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t, N, F, Xi, Yi, Xd, Yd   ;
    cin >> t    ;
    while(t--){
        int x1[1000], y1[1000], x2[1000], y2[1000], x3[1000], y3[1000]  ;  // i know making array local sucks but i don't want to use memset, don't know its basics and how it works :P
        cin >> N >> F   ;
        cin >> Xi >> Yi >> Xd >> Yd ;

        for (int i = 0; i < N ; i++){
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> x3[i] >> y3[i]   ;
            dict[i] = 0    ;
        }
        long long int count = 0 ;
        for (int i = 0; i < F; i++){
            Xi += Xd    ;
            Yi += Yd    ;
            for (int j = 0; j < N; j++){
                if (check(x1[j], y1[j], x2[i], y2[i], x3[i], y3[i], Xi, Yi) and !dict[j]){
                    count += 1  ;
                    dict[i] ++ ;
                }

            }


        }
        cout << count << "\n"  ;

    }

}
