#include <bits/stdc++.h>
#include <utility>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


#define mod 1000000007
#define maxs 10005
#define array_size_limit 5000005
#define mins 1005
#define eps 0.000000000001
#define imax 2000000200
#define llmax 1000000002000000000ll


#define LL long long int
#define pb push_back
#define gc getchar_unlocked
#define iosbase ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pair<int,int>,int>
#define ppl pair<pll,ll>
#define vi vector<LL>
#define sc scanf
#define pr printf
#define lld I64d
#define F first
#define S second
#define siter set<int>::iterator
#define p_pq priority_queue
#define ub upper_bound
#define lb lower_bound
#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))

int arr1 [1000005]  ;

int main()
{
	int t;
	cin>>t;
    int n;
	int arr[t]={0};
	for (int i = 0; i < t; i++) {
	    cin>>arr[i];
	}
	multiset<int>set1;
	std::multiset<int>::iterator it,it2;
	//set1.clear();

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        set1.insert(arr[i]);
        arr1[arr[i]] += 1   ;
    }

     vector<int> myvec;
     it=set1.end();
     it--;
     myvec.pb((*it));

        for (int i = n; i < t; i++)
        {
            if (arr1[arr[i - n]] == 1)
                set1.erase(arr[i-n]);
            arr1[arr[i - n]] -= 1   ;
            set1.insert(arr[i]);
            arr1[arr[i]] += 1   ;

             it2=set1.end();
             it2--;
             myvec.pb((*it2));

        }

for (int w = 0; w <myvec.size() ; w++) {
	    cout<<myvec[w] << " ";
	}
	return 0;
}
