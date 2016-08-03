'''The Darkest place in the hell are reserved for those who maitain their
neutrality in the time of moral crisis.'''
import sys
dp = [0]*(1000000+1)
K, L, M = map(int, raw_input().split())
array = map(int, raw_input().split())
dp[1] = 'A'
dp[K] = 'A'
dp[L] = 'A'
for i in xrange(2, max(array)+1):
    if i in [K, L]:
        continue
    if dp[i - 1] == 'B' or (i > K and dp[i-K] == 'B') or (i > L and dp[i - L] == 'B'):
        dp[i] = 'A'
    else:
        dp[i] = 'B'
for i in array:
    sys.stdout.write(str(dp[i]))
