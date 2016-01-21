for _ in xrange(int(raw_input())):
    N, M  = raw_input().split()
    result = str(int(N[::-1]) + int(M[::-1]))
    i = 0
    result = result[::-1]
    while result[i] == '0':
        i += 1
    print result[i:]
    
    
