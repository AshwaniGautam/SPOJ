'''The darkest places in the hell are reserved for those who maintain their
neutrality in the time of moral crisis.
Religion and GOD are the only shit between development and India'''

def sol(n, k):
    if n == 0:
        return 0
    if k == 0:
        return 1
    if dp[n][k] != -1:
        return dp[n][k]
    val, i = 0, 0
    while i < n and k-i >=0 :
        val += sol(n-1, k-i)
        i+=1
    dp[n][k] = val
    return val
    
for _ in xrange(int(raw_input())):
    N, K = map(int, raw_input().split())
    dp = [[-1]*(K+1) for i in xrange(N+1)]
    print sol(N, K)
    #print dp
    
