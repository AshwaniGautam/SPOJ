import sys
while True:
    N = int(sys.stdin.readline().strip())
    if N == 0:
        sys.exit(0)
    arr = map(int, sys.stdin.readline().strip().split())
    stack1, stack2 = [], []
    start, lent = 1, 0
    for i in xrange(N):
        if arr[i] != start:
            stack2.append(arr[i])
            lent += 1
        else:
            stack1.append(arr[i])
            start += 1
        while lent > 0 and stack2[-1] == start:
            stack2.pop()
            lent -= 1
            start += 1
    j = 0
    flag = 1
    for i in xrange(N, start - 1, -1):
        if stack2[j] != i:
            print "no"
            flag = 0
            break
        j += 1
    if flag:
        print "yes"
