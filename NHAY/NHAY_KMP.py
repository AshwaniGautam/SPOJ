__author__ = "Ashwani Gautam"

import sys

def main():
    def Prefix_Function(needle, M):
        pi = [0] * M
        k = 0
        for i in xrange(1, M):
            while needle[k] <> needle[i]:
                if k == 0:
                    break
                k = pi[k - 1]
                
            if needle[k] == needle[i]:
                k += 1
                
            pi[i] = k
        print pi
        return pi

    def KMP(needle, haystack, M):
        N = len(haystack)
        pi = Prefix_Function(needle, M)
        q = 0
        flag = 0
        for i in xrange(N):
            while needle[q] <> haystack[i]:
                if q == 0:
                    break
                q = pi[q - 1]
                
            if needle[q] == haystack[i]:
                q += 1

            if q == M:
                flag = 1
                print i - M + 1
                q = pi[q - 1]
        if flag:
            print "\n"
    

    flag = 0
    for line in sys.stdin:
        if flag == 0:
            M = int(line.strip())
            flag = 1
            continue
        elif flag == 1:
            needle = line.strip()
            flag = 2
            continue
        else:
            haystack = line.strip()
            flag = 0
        KMP(needle, haystack, M)
if __name__ == "__main__":
    main()
