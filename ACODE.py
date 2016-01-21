import sys
while 1:
    string = raw_input()
    if string == '0':
        sys.exit(0)
    dp = [0] * 10000
    k = 2
    dp[0], dp[1] = 1, 1
    for i, j in zip(string, string[1:]) :
        l = int(i + j)
        if i == '0':
            dp[k] = dp[k - 1]
        elif j == '0':
            dp[k] = dp[k - 2]
        else:
            if l > 26:
                dp[k] = dp[k - 1]
            else:
                dp[k] = dp[k - 1] + dp[k - 2]
        k += 1
            
    print dp[len(string)]
