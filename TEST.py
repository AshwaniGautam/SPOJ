def Prefix_Function(needle, M):
    pi = [0] * M
    k = 0
    print needle ,M
    for i in xrange(1, M):
        while needle[k] <> needle[i]:
            print "hi", i, k
            if k == 0:
                break
            k = pi[k - 1]
            
        if needle[k] == needle[i]:
            k += 1
            
        pi[i] = k
        print pi
    print  pi
    return pi

def KMP(needle, haystack, M):
    N = len(haystack)
    pi = Prefix_Function(needle, M)
    q = 0   
    for i in xrange(N):
        while needle[q] <> haystack[i]:
            if q == 0:
                break
            q = pi[q - 1]
            
        if needle[q] == haystack[i]:
            q += 1

        if q == M:
            print i - M + 1
            q = pi[q - 1]

needle = 'abcabcabcabc'
haystack = 'barfoobarfoobarfoobarfoobarfoo'
KMP(needle, haystack, len(needle))
