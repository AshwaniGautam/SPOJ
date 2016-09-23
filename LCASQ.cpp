	#include <stdio.h>
	#include <iostream>
	#include <vector>
	#include <queue>
	#include <string.h>

	#define N 100000
	using namespace std;

	int E[2*N]	;
	int L[N]	;
	int level[2*N]	;
	int H[2*N]	;
	int done[N]	;
	int pos	= 1	;
	vector <int> tree [N]	;

	void bfs(){

		queue <int> que 	;
		que.push(1)	;
		done[1] = 1	;
		int len = 1	;
		while(len){
			int u = que.front()	;
			que.pop()	;
			len --	;
			for (int i = 0; i < tree[u].size(); i++){
				if (!done[tree[u][i]]){
					L[tree[u][i]] = L[u] + 1	;
					done[tree[u][i]] = 1	;
					que.push(tree[u][i])	;
					len ++	;
				}
			}
		}
	}

	void ETT(int v, int pv){

		E[pos] = v 	;
		pos ++	;
		for(int i = 0; i < tree[v].size(); i++){

			int u = tree[v][i]	;
			if (pv == u)
				continue		;

			ETT(u, v)	;
			E[pos] = v	;
			pos ++	;
		}

	}

	int main(){
		int n, t, m, child, u, v, q, ans	;
		cin >> n;	

		for (int i = 1; i <= n; i++){
			cin >> m 	;
			tree[i].clear()	;
			for (int j = 0; j < m; j++){
				cin >> child	;
				tree[i].push_back(child+1)	;
				tree[child+1].push_back(i)	;
			}
		}

		bfs()	;
		ETT(1, 0)	;

		for (int i = 1; i <= 2*n-1; i++)
			level[i] = L[E[i]]	;

		for(int i = 1; i <= 2*n - 1; i++)
			if (!H[E[i]])
				H[E[i]] = i	;

		cin >> q 	;
		while(q--){

			cin >> u >> v 	;
			u += 1	;
			v += 1	;
			int m = 99999999	;
			for (int i = min(H[u], H[v]); i <= max(H[u], H[v]); i++){
				if (level[i] < m){
					m = level[i]	;
					ans = i 	;
				}	
		}

		cout << E[ans] - 1 << "\n"	;
	}

	return 	0;
}
