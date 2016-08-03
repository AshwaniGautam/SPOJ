'''The darkest places in the hell are reserved for those who maintain their
neutrality in the time of moral crisis.
'''
for _ in xrange(int(raw_input())):
    A = raw_input()
    B = raw_input()
    N, M = len(A), len(B)
    dp = [[0]* (N+1) for i in xrange(M+1)]
    for i in xrange(M+1):
        dp[i][0] = i
    for j in xrange(N+1):
        dp[0][j] = j
    for i in xrange(1, M+1):
        for j in xrange(1,N+1):
            if A[j-1] == B[i-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
    print dp[-1][-1]
