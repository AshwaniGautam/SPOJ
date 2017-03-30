#include<bits/stdc++.h>
int arr[1000005];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    std::sort(arr, arr+n+1);
    long long sum = m;
    for (int i=n; ; i--) {
        sum -= (arr[i]-arr[i-1])*1ll*(n+1-i);
        if (sum>0)
            continue;
        printf("%d\n", arr[i-1] + (-sum)/(n+1-i));
        return 0;
    }
}
