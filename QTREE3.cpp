#include <stdio.h>
#include <iostream>
#include <vector>
#define INF 1 << 30
#define MAXN 100009
using namespace std;

vector<int> graph[MAXN]	;
int parent[MAXN], subtree[MAXN], L[MAXN], location[MAXN], array[MAXN], HEAD[MAXN];
int ptr = 0, N	;

struct node
{
	int value, ans;
	
};

node ST[MAXN << 2]	;

void build(int pos, int low, int high){

	if(low == high){

		ST[pos].value = 0	;
		ST[pos].ans = INF	;
		return;
	}

	int mid = (low+high) / 2	;
	build(2*pos+1, low, mid)	;
	build(2*pos+2, mid+1, high)	;

	ST[pos].ans = INF	;
}

void update(int i, int low, int high, int pos, int val){

	if(i < low || i > high)
		return;

	if (low == high){	
		ST[pos].value = (ST[pos].value + 1) % 2	;

		if(ST[pos].value)
			ST[pos].ans = val	;
		else
			ST[pos].ans = INF	;

		return ;
	}

	int mid = (low+ high) / 2	;
	update(i, low, mid, 2*pos+1, val)	;
	update(i, mid+1, high, 2*pos+2, val)	;
	
	ST[pos].ans = min(ST[2*pos+1].ans, ST[2*pos+2].ans);
}

int query(int i, int j, int low, int high, int pos){

	if(j < low || i > high)
		return INF;

	if(i <= low && high <= j)
		return ST[pos].ans	;

	int mid = (low + high) / 2	;
	return min( query(i, j, low, mid, 2*pos+1), query(i, j, mid+1, high, 2*pos+2) )	;
	
}

int dfs(int v, int pv){

	parent[v] = pv	;
	L[v] = L[pv] + 1	;
	subtree[v] = 1	;

	for(int i = 0; i < graph[v].size(); i++){
		if(graph[v][i] != pv){

			dfs(graph[v][i], v)	;
			subtree[v] += subtree[graph[v][i]]	;
		}
	}
}


int hld(int v, int pv){

	if(HEAD[v] == -1)
		HEAD[v] = v 	;
	else
		HEAD[v] = HEAD[pv]	;


	location[v] = ptr ;
	array[ptr++] = v;

	int sc = -1	;
	int sub = 0;

	for(int i = 0; i < graph[v].size(); i++){

		if(graph[v][i] != pv && subtree[graph[v][i]] > sub){

			sub = subtree[graph[v][i]]	;
			sc = graph[v][i]	;

		}

	}


	if (sc != -1){

		hld(sc, v)	;
		for(int i = 0; i < graph[v].size(); i++){

			if (sc != graph[v][i] && graph[v][i] != pv){

					HEAD[graph[v][i]] = -1	;
					hld(graph[v][i], v)	;
			}
		}
	}
}


int query_up(int i){

	int minimum = INF	;
 
	while(1){

		if (HEAD[i] == 1){

			minimum = min(minimum, query(0, location[i], 0, N-1, 0))	;
			break;

		}

		minimum = min(minimum, query(location[HEAD[i]], location[i], 0, N-1, 0))	;
		i = parent[HEAD[i]]	;
	}

	return minimum;
}

int main(){

	ios_base::sync_with_stdio(false);   cin.tie(0)  ;
	int Q, u, v, a, b	;
	scanf("%d %d", &N, &Q)	;
	for(int i = 1; i < N; i++){
		scanf("%d %d", &u, &v)	;
		graph[v].push_back(u)	;
		graph[u].push_back(v)	;	

	}

	HEAD[1] = -1	;
	dfs(1, 0)	;
	hld(1, 0)	;
	build(0, 0, N-1)	;

	while(Q--){

		scanf("%d %d", &a, &b)	;

		if (a){

			int answer = query_up(b)	;

			if (answer != INF)
				printf("%d\n", answer)	;
			else
				printf("-1\n")	;
		}
		else{
			update(location[b], 0, N-1, 0, b)	;
		}
	}
}