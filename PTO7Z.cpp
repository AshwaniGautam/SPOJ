#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

#define N 10000

using namespace std;

int node	;
int max_level;
vector <int> tree[N]	;
int level[10000]    ;

void dfs(int v, int pv){

    level[v] = level[pv] + 1    ;
    if (level[v] > max_level){
        max_level = level[v]    ;
        node = v    ;
    }
	for (int i = 0; i < tree[v].size(); i++){
		if (tree[v][i] != pv){
			dfs(tree[v][i], v)	;
		}
	}
}
int main(){

	int n, x, y 	;
	cin >> n;
	for (int i = 1; i < n; i++){

		cin >> x >> y	;
		tree[x].push_back(y)	;
		tree[y].push_back(x)	;

	}

	level[0] = -1   ;
	dfs(1, 0);
	max_level = 0	;
	level[0] = -1   ;
	dfs(node, 0) ;
	cout << max_level << "\n";

	return 0	;
}
