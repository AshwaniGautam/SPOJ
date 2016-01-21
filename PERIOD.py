import sys

def failure_function(pattern, M):
    k = 0
    pi = [0]*M
    for i in xrange(1, M):
        while pattern[k] <> pattern[i]:
            if not k:
                break
            k = pi[k - 1]
            
        if pattern[k] == pattern[i]:
            k += 1

        pi[i] = k
    #print pi
    return pi

for _ in xrange(int(sys.stdin.readline().strip())):
    N = int(sys.stdin.readline().strip())
    string = (sys.stdin.readline().strip())
    pi = failure_function(string, N)
    print "Test case #%d" %  (_ + 1)
    for i in xrange(N):
        if pi[i] >= (i + 1) / 2:
            lenth = i + 1 - pi[i]
            ans = (i+1)/lenth
            if (i + 1) % lenth == 0 and ans > 1:
                print i+1, ans
    print
