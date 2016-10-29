#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#define MAXN 10004

using namespace std;

vector <int> graph[MAXN], cost[MAXN], edges[MAXN], temp	;
int L[MAXN], parent[MAXN], subtree[MAXN], array[MAXN], location[MAXN], HEAD[MAXN]	;
long long int ST[MAXN << 2]	;	
int ptr = 0, N	;

void build(int pos, int low, int high){

	if (low == high){

		ST[pos] = array[low]	;
		return ;
	}

	int mid = (low + high) / 2	;
	build(2*pos+1, low, mid)	;
	build(2*pos+2, mid+1, high)	;

	ST[pos] = ST[2*pos+1] + ST[2*pos+2]	;
}

long long int query(int i, int j, int low, int high, int pos){

	if(j < low || i > high)
		return 0	;

	if (i <= low && high <= j)
		return ST[pos]	;

	int mid = (low + high) / 2	;
	long long int a = query(i, j, low, mid, 2*pos+1)	;
	long long int b = query(i, j, mid+1, high, 2*pos+2)	;

	return (a+b)	;
}


int LCA(int n, int m){

	while(HEAD[n] != HEAD[m]){

		if (L[HEAD[n]] < L[HEAD[m]])
			m = parent[HEAD[m]]	;
		else
			n = parent[HEAD[n]]	;
	}

	if (L[n] > L[m])
		return m;
	return  n;
}

void  dfs(int v, int pv){

	parent[v] = pv		;
	L[v] = L[pv] + 1 	;
	subtree[v] = 1	;	

	for (int i = 0; i < graph[v].size(); i++){if (graph[v][i] != pv){
			dfs(graph[v][i], v)	;
			subtree[v] += subtree[graph[v][i]]	;
		}
	}
}
void hld(int v, int pv, int value){

	if (HEAD[v] == -1)
		HEAD[v] = v;
	else
		HEAD[v] = HEAD[pv]	;

	location[v] = ptr ;
	array[ptr++] = value 	;

	int Cost;
	int sub = 0	;
	int Special = -1;

	for(int i = 0; i < graph[v].size(); i++){

		if (graph[v][i] != pv){
			if(subtree[graph[v][i]] > sub){

				sub = subtree[graph[v][i]]	;
				Cost = cost[v][i]	;
				Special = graph[v][i]	;
			}
		}
	}

	if (Special != -1){

		hld(Special, v, Cost)	;

		for(int i = 0; i < graph[v].size(); i++){
			if (graph[v][i] != Special && graph[v][i] != pv){
				HEAD[graph[v][i]] = -1	;
				hld(graph[v][i], v, cost[v][i])	;
			}
		}
	}
}

long long int query_up(int a, int lca){

	long long int distance = 0;

	while(1){

		if (a == lca) break;

		if (HEAD[a] == HEAD[lca]){

			distance += query(location[lca]+1, location[a], 0, N-1, 0)	;
			break;
		}

		distance += query(location[HEAD[a]], location[a], 0, N-1, 0)	;
		a = parent[HEAD[a]]	;
	}

	return distance	;
}

int main(){
	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	int t;
	int u, v, value, a, b, k, node;
	char M[15]	;
	scanf("%d", &t)	;
	while(t--){

		ptr = 0	;
		scanf("%d", &N)	;

		for(int i = 0; i < MAXN; i++){

			graph[i].clear();
			cost[i].clear()	;
			edges[i].clear();

		}
		for(int i = 1; i < N; i++){

			scanf("%d %d %d", &u, &v, &value)	;
			graph[v].push_back(u)	;
			graph[u].push_back(v)	;
			cost[v].push_back(value)	;
			cost[u].push_back(value)		;
			edges[i].push_back(u)	;
			edges[i].push_back(v)	;

		}
		
		memset(ST, 0, sizeof(ST))	;
		memset(HEAD, 0, sizeof(HEAD))	;
		HEAD[1] = -1;

		dfs(1, 0)	;	
		hld(1, 0, 0)	;
		build(0, 0, N-1)	;

		while(1){

			scanf("%s", M)	;
			if(M[1] == 'O')
				break;
			scanf("%d %d", &a, &b)	;
			int lca = LCA(a, b)	;
			if (M[0] == 'D'){
				long long int left = query_up(a, lca)	;
				long long int right = query_up(b, lca)	;
				printf("%lld\n", left + right);

			}
			else{

				scanf("%d", &k)	;
				node =  a;
				k--;
				while(a != lca && k != 0){
					a = parent[a]	;
					k--	;
					node = a;
				}
				if (k == 0)
					printf("%d\n", node)	;
				else{

					temp.push_back(b)	;
					while(b != lca){
						b = parent[b]	;
						temp.push_back(b)	;
					}

					printf("%d\n", temp[temp.size() - k-1])	;
					temp.clear();
				}
			}
		}
	}
	return 0	;
}
