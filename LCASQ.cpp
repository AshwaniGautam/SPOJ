	#include <stdio.h>
	#include <iostream>
	#include <vector>
	#include <queue>
	#include <string.h>

	#define N 1009
	using namespace std;

	int E[2*N]	    ;
	int L[N]	    ;
	int level[2*N]	;
	int H[2*N]	    ;
	int done[N]	    ;
	int pos	= 1	    ;

	vector <int> tree [N]	;

	void ETT(int v, int pv){

		E[pos] = v 	;
		pos ++	;
		L[v] = L[pv] + 1;
		for(int i = 0; i < tree[v].size(); i++){
            if (tree[v][i] != pv){

                ETT(tree[v][i], v)	;
                E[pos] = v	;
                pos ++	;

            }
		}
	}

	int main(){
		int n, t, m, child, u, v, q, ans, test = 1	;
		ios_base::sync_with_stdio(false);   cin.tie(0)  ;

		scanf("%d", &t) ;

		while(t--){

			memset(H, 0, sizeof(H))	;
			memset(E, 0, sizeof(E))	;
			memset(level, 0, sizeof(level))	;
			memset(L, 0, sizeof(L))	;
			memset(done, 0, sizeof(done))	;
			pos = 1	;

			//cout << "Case " << test << ":" << "\n";
			printf("Case %d:\n", test)    ;
			test ++	;
			scanf("%d", &n) ;
			L[0] = -1;

			for (int i = 1; i <= n; i++){

				scanf("%d", &m) ;
				tree[i].clear()	;
				for (int j = 0; j < m; j++){

					scanf("%d", &child);
					tree[i].push_back(child)	;
					tree[child].push_back(i)	;

				}
			}


			ETT(1, 0)	;

			for (int i = 1; i <= 2*n-1; i++)
				level[i] = L[E[i]]	;

			for(int i = 1; i <= 2*n - 1; i++)
				if (!H[E[i]])
					H[E[i]] = i	;

			scanf("%d", &q) ;
			while(q--){

				scanf("%d %d", &u, &v)  ;
				int m = 99999999	;
				for (int i = min(H[u], H[v]); i <= max(H[u], H[v]); i++){
					if (level[i] < m){
						m = level[i]	;
						ans = i 	;
					}
				}
				printf("%d\n", E[ans])  ;
			}
		}
		return 	0;
	}
