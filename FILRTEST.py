import sys

def failure_function(pattern, M):
    k = 0
    pi = [0] * M
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

def main():
    while 1:
        N, string = sys.stdin.readline().strip().split()
        if N == "-1":
            sys.exit(0)
        N = int(N)
        M = len(string)
        if N < M:
            print 0
            continue
        pi = failure_function(string, M)
        key = M - pi[M - 1]
        rem = N - M
        extra = rem / key
        print extra + 1


if __name__ == "__main__":
    main()
