#include<bits/stdc++.h>

/*
    Precomputation: O(NlogN)
    Query : O(ROOT(N) * log(N))
    Update : O(ROOT(N))

*/

using namespace std;

vector< int > block_list[320]    ;
int N, Q, BLOCK_SIZE, x, y    ;
int arr[100002]   ;
char query  ;

inline int search(int idx, int val) {
	int lo = -1, hi = block_list[idx].size(), mid;
	while (lo < hi - 1) {
		mid = (lo + hi) / 2;
		if (block_list[idx][mid] <= val)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int main(){

    cin.sync_with_stdio(false)  ;
    cin >> N >> Q   ;
    BLOCK_SIZE = static_cast<int>(sqrt(N))  ;

    for(int i = 0;  i < N ; i++){
        cin >> arr[i]   ;
        block_list[i / BLOCK_SIZE].push_back(arr[i])  ;
    }

    for(int i = 0; i <= (N-1) / BLOCK_SIZE; i++)
        sort(block_list[i].begin(), block_list[i].end())   ;

    for(int query_p = 0; query_p < Q; query_p++){

        cin >> query    ;
        if(query == 'C'){

            int answer = 0  ;
            int k   ;
            cin >> x >> y >> k ;
            x--; y--;
            int x_block = x / BLOCK_SIZE    ;
            int y_block = y / BLOCK_SIZE    ;
            if(x_block == y_block)
                for(int i = x; i <= y; i++)
                    answer += (arr[i] <= k) ? 1 : 0   ;
            else{

                for(int i = x; i < (x_block + 1)*BLOCK_SIZE; i++)
                    answer += (arr[i] <= k) ? 1 : 0   ;

                for(int i = x_block+1; i < y_block; i++)
                    answer += search(i, k) + 1 ;

                for(int i = (y_block)*(BLOCK_SIZE); i <= y; i++)
                    answer += (arr[i] <= k) ? 1 : 0   ;
            }

            cout << answer << "\n"  ;

    }
        else{

            int x, y    ;
            cin >> x >> y ;
            x --    ;
            int x_block = x / BLOCK_SIZE    ;
            block_list[x_block].erase(block_list[x_block].begin() + search(x_block, arr[x]))    ;
            int position = search(x_block, y)   ;
            if(position == -1)
                block_list[x_block].insert(block_list[x_block].begin(), y)  ;
            else
                block_list[x_block].insert(block_list[x_block].begin() + position + 1, y)  ;
            arr[x] = y  ;
        }
    }
    return 0    ;
}
