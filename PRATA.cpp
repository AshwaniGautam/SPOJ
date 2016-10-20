// Hopelessly plagiarised from https://github.com/arpitbbhayani/spoj/blob/master/PRATA.cpp  :)

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#define N 1000

using namespace std;

int ranks[N], array[N], fact[N]	;
int guess	;

int main(){

	int t	;
	scanf("%d", &t)	;
	while(t--){
		priority_queue <int, vector<int>, greater<int> > pq ;
		int solution = 	0	;
		int order, chef	;
		scanf("%d %d", &order, &chef)	;
		for (int i = 0; i < chef; i++){
			scanf("%d", &ranks[i])	;
			array[i] = ranks[i]	;
			fact[i] = 1	;	
			pq.push(ranks[i])	;
		}

		int time = 	0	;
		while(order > 0){
			time = pq.top()	;
			while(!pq.empty() and pq.top() == time)
				pq.pop()	;

			for (int i = 0;  i < chef; i++){

				if (time == array[i]){

					order--	;
					fact[i]++	;
					array[i] += ranks[i] * fact[i]	;
					pq.push(array[i])	;

				}
			}
		}

		printf("%d\n", time)	;

	}
	return 0	;
}