__author__ = "Ashwani Gautam"

import sys


def search(pat, txt, q, M, d):
    N = len(txt)
    i = 0
    j = 0
    p = 0    
    t = 0    
    h = 1
    for i in xrange(M-1):
        h = (h * d) % q
    if N >= M: 
        for i in xrange(M):
            p = (d*p + ord(pat[i]))%q
            t = (d*t + ord(txt[i]))%q
        flag = 0
        for i in xrange(N-M+1):
            if p == t:
                flag = 1
                print i
            if i < N-M:
                t = (d*(t-ord(txt[i])*h) + ord(txt[i+M]))%q
                if t < 0:
                    t = t+q
        if flag :
            print "\n"


def main():
    flag = 0
    for line in sys.stdin:
        if flag == 0:
            n = int(line.strip())
            flag = 1
            continue
        elif flag == 1:
            needle = line.strip()
            flag = 2
            continue
        else:
            haystack = line.strip()
            flag = 0
        base = 101
        mod = int((1e9)+7)
        search(needle, haystack, mod, n, base)
if __name__ == "__main__":
    main()
