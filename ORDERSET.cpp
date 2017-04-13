/*
    All operation takes O(logMAX) time
*/

#include<bits/stdc++.h>
#define MAX 200002
using namespace std;

int Q, ST[200002<<2]   ;
char op ;
vector <pair<int, int> > queries;
set<int> myset  ;
unordered_map <int, int> mymap, reverse_map  ;

inline void update(int  idx, int low, int high, int pos, int value){

    if(idx < low || idx > high)
        return ;
    if(low == high){
        ST[pos] = value ;
        return ;
    }

    int mid = (low + high) / 2  ;
    update(idx, low, mid, 2*pos+1, value)  ;
    update(idx, mid+1, high, 2*pos+2, value)   ;

    ST[pos] = ST[2*pos+1] + ST[2*pos+2] ;
}

inline int query(int i, int j, int low, int high, int pos){

    if(j < low || i > high)
        return  0   ;
    if(i <= low && high <= j)
        return ST[pos]  ;
    int mid = (low + high) / 2  ;
    return query(i, j, low, mid, 2*pos+1) + query(i, j, mid+1, high, 2*pos+2)   ;
}

inline int bin_search(int low, int high, int pos, int k){

    if(ST[pos] < k)
        return -1;

    if(low == high)
        return low  ;

    int mid = (low + high) / 2  ;
    if(ST[2*pos+1] >= k)
        bin_search(low, mid, 2*pos+1, k)    ;
    else
        bin_search(mid+1, high, 2*pos+2, k-ST[2*pos+1]) ;
}

int main(){

    cin.sync_with_stdio(0);
    cin >> Q    ;

    for(int i = 0; i < Q; i++){
        int x ;
        cin >> op >> x ;
        queries.push_back({op, x})  ;
        if(op != 'K')
            myset.insert(x) ;
    }

    int j = 0   ;
    for(auto i : myset){
        mymap[i] = j  ;
        reverse_map[j++] = i  ;
    }

    for(auto i : queries){

        if(i.first == 'I')
            update(mymap[i.second], 0, MAX, 0, 1)  ;

        else if(i.first == 'D')
            update(mymap[i.second], 0, MAX, 0, 0)   ;

        else if(i.first == 'C')
            cout << query(0, mymap[i.second]-1, 0, MAX, 0) << "\n" ;

        else{

            int result = bin_search(0, MAX, 0, i.second)    ;
            if(result == -1)
                cout << "invalid\n" ;
            else
                cout << reverse_map[result] << "\n"  ;
            }
    }
    return  0;
}
