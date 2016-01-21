import sys

for _ in xrange(int(sys.stdin.readline().strip())):
    N = int(sys.stdin.readline().strip())
    arr = map(int, sys.stdin.readline().strip().split())
    arr.sort()
    test = arr[0]
    count = 1
    another, counter = [], []
    for i in xrange(1,N):
        if test == arr[i]:
            count += 1
        else:
            another.append( count )
            count = 1
            test = arr[i]
    another.append(count)
    counter.append(another[0]**2)
    for i in xrange(1, len(another)):
        counter.append(((another[i] + another[i-1]) * another[i]) + counter[i-1])
        another[i] += another[i - 1]
    print counter[-1]
