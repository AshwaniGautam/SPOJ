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
int ST[150000]      ;
int result[50000]   ;

void update(int index, int low, int high, int pos){

    if (index > high || index < low)
        return ;
    if (low == high){
        ST[pos] += 1   ;
        return ;
    }

    int mid  = (low+high) / 2   ;
    update(index, low, mid, 2*pos+1)    ;
    update(index, mid+1, high, 2*pos+2)    ;

    ST[pos] = ST[2*pos+1] + ST[2*pos+2] ;
    return ;
}

int query(int i, int j, int low, int high, int pos){
    if (low > j || high < i)    return 0    ;
    if (i <= low && high <= j)        return ST[pos]  ;
    int mid = (low+high) / 2    ;
    return (query(i, j, low, mid, 2*pos+1) + query(i, j, mid+1, high, 2*pos+2))  ;
}

struct query_data{    int L, R, k, pos  }   ;
bool compare(const query_data &a, const query_data &b){
    return a.k < b.k    ;
}

vector<query_data> que;

int main(){
    int N, M, dummy        ;
    scanf("%d", &N) ;
    for (int i = 0; i < N; i++){
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

    int K = 0   ;
    for (int i = 0; i < M; i++){
        while(K < N && data[K].first < que[i].k){
            //cout << data[K].second << data[K].first << que[i].k << endl;
            update(data[K].second, 0, N-1, 0)  ;
            K++ ;
        }
        result[que[i].pos] = (que[i].R  - que[i].L + 1) - query(que[i].L-1, que[i].R-1, 0, N-1, 0)    ;
    }

    for(int i = 0; i < M; i++)
        printf("%d\n", result[i])   ;
    return 0    ;
}
