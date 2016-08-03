import sys
dp = [0]* (10**5+1)
dp[1], dp[2], dp[3] = 1, 2, 3
for i in xrange(4, len(dp)):
    dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4])
def solve(i):
    if i <= 10**5:
        return dp[i]
    return max(i, solve(i / 2)+solve(i / 3)+solve(i / 4))
    
for n in sys.stdin:
    n = int(n.strip())
    if n <= 10**5:
        print dp[n]
    else:
        print solve(n)
    
