/*
The darkest places in the hell are reserved for those who maintain thier neutrality in time of moral crisis- Bertrand Zobrist.
Religion and GOD are the only shit between India and Development
*/
#include<stdio.h>
#include<iostream>
#include<bitset>
#include<math.h>
#include<string.h>
using namespace std;
int array[20005], solution[20005]   ;
bitset <31> bin[20005]  ;
bitset <31> sol[20005]   ;
int main(){
    int T, N, K, ans ;
    scanf("%d", &T)    ;
    while(T--){
        ios_base::sync_with_stdio(false);   cin.tie(0)  ;
        scanf("%d %d", &N, &K)   ;
        for(int i = 0; i < N; i++){
            scanf("%d", &array[i]) ;
            for(int j = 0; j < 31; j++)
                bin[i][j] = array[i] & 1 << j   ;
            }
        K = min(K, N / 2)   ;
        int zeroes    ;
        for(int i = 0; i < 31; i++){
            zeroes = 0;
            for(int j = 0; j < 2*K+1; j++){
                if (bin[j][i] == 0)
                    zeroes++;
            }
            for (int k = 0; k < N; k++){
                if (!zeroes)
                    sol[(K+k)%N][i] = 1  ;
                else
                    sol[(K+k)%N][i] = 0  ;

                if (bin[k][i] == 0)
                    zeroes--;

                if(bin[(2*K+1+k)%N][i] == 0)
                    zeroes++;
            }
        }
        for (int i = 0; i < N; i++){
            ans = 0 ;
            for(int j = 0; j < 31; j++){
                ans += sol[i][j] * (pow(2,j)) ;
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
    return  0;
}
