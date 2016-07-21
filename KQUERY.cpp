/*
Darkest places in the hell are reserved for those who maintain thier neutrality in the time of moral crisis-Bertrand Zobrist
Religion and GOD are the only shit between India and Development.
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int> > data;
int ST[40000]      ;
int result[200009]   ;

void update(int idx, int value, int n){
    for(; idx <= n; idx += idx & -idx)
        ST[idx] += value;
}

int query(int idx){
    int ans = 0   ;
    for(; idx > 0; idx -= idx & -idx)
        ans += ST[idx] ;
    return ans  ;
}

struct query_data{    int L, R, k, pos  ;  }   ;
bool compare(const query_data &a, const query_data &b){
    return a.k < b.k    ;
}

vector<query_data> que;

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0)  ;
    int N, M, dummy        ;
    scanf("%d", &N) ;
    data.push_back(make_pair(0, 0)) ;
    for (int i = 1; i <= N; i++){
        scanf("%d", &dummy) ;
        data.push_back(make_pair(dummy, i)) ;
        }

    scanf("%d", &M)                 ;

    for (int i = 0; i < M; i++){
        query_data a1       ;
        scanf("%d %d %d", &a1.L, &a1.R, &a1.k)  ;
        a1.pos = i    ;
        que.push_back(a1) ;
    }

    sort(data.begin(), data.end())    ;
    sort(que.begin(), que.end(), compare)   ;

    int K = 1   ;
    for (int i = 0; i < M; i++){
        while(K <= N && data[K].first <= que[i].k){
            update(data[K].second, 1, N)  ;
            K++ ;
        }
        result[que[i].pos] = (que[i].R  - que[i].L + 1) - query(que[i].R) + query(que[i].L-1)    ;
    }

    for(int i = 0; i < M; i++)
        printf("%d\n", result[i])   ;
    return 0    ;
}
