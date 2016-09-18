	#include <stdio.h>
	#include <iostream>
	#include <vector>
	#include <queue>
	#include <string.h>

	#define N 10000
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
		int n, t, m, child, u, v, q, ans, test = 1	;
		cin >> t;
		while(t--){

			memset(H, 0, sizeof(H))	;
			memset(E, 0, sizeof(E))	;
			memset(level, 0, sizeof(level))	;
			memset(L, 0, sizeof(L))	;
			memset(done, 0, sizeof(done))	;
			pos = 1	;

			cout << "Case " << test << ":" << "\n";
			test ++	;
			cin >> n;	
			
			for (int i = 1; i <= n; i++){
				cin >> m 	;
				tree[i].clear()	;
				for (int j = 0; j < m; j++){
					cin >> child	;
					tree[i].push_back(child)	;
					tree[child].push_back(i)	;
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
				int m = 99999999	;
				for (int i = min(H[u], H[v]); i <= max(H[u], H[v]); i++){
					if (level[i] < m){
						m = level[i]	;
						ans = i 	;
					}	
				}
				cout << E[ans] << "\n"	;
			}
		}
		return 	0;
	}
