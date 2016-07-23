import sys
for _ in xrange(int(sys.stdin.readline().strip())):
    N = int(sys.stdin.readline().strip())
    a, b = [], []
    for i in xrange(N):
        p, q = map(int, sys.stdin.readline().strip().split())
        a.append(p)
        b.append(q)
    a.sort()
    b.sort()
    i, j = 0, 0
    maximum = 0
    ans = 0
    while(i < N):
        while(i < N and a[i] < b[j]):
            maximum += 1
            i += 1
        ans = max(ans, maximum)
        if (i == N):
            break
        while(j < N and b[j] < a[i]):
            maximum -= 1
            j += 1
    print ans
