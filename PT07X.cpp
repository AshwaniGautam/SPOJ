#include <iostream>
#include <stdio.h>
#include <vector>
#define N 1000007
using namespace std;

vector <int> tree[100007]	;
int level[N]	;

void dfs(int v, int pv){

	level[v] = level[pv] + 1	;
	for (int i = 0; i < tree[v].size(); i++){
		if (tree[v][i] != pv)
			dfs(tree[v][i], v)	;
	}
}

int main(){

	int n, u, v	;
	scanf("%d", &n)	;
	if (n == 1){
        printf("1\n")   ;
        return 0    ;
    }
	for (int i = 1; i < n; i++){

		scanf("%d %d", &u, &v)	;
		tree[u].push_back(v)	;
		tree[v].push_back(u)	;

	}

	dfs(1, 0)	;
	int min1 = 0	;
	int min2 = 0	;
	for (int i = 1; i <=n ;i++){

		if(level[i] % 2)
			min1++	;
		else
			min2++	;
	}
	printf("%d\n", min(min1, min2))	;

	return 0	;
}
