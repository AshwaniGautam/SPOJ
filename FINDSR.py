__author__ = "Ashwani Gautam"

import sys

def main():
    for line in sys.stdin:
        if line == "*\n":
            sys.exit(0)
        string = line.strip()
        N = len(string)
        flag = 0
        possible = []
        for i in xrange(1, int(N**0.5) + 1):
            if N % i == 0:
                possible.append(N / i)
                if (string[:i] * (N / i)) == string:
                    print N / i
                    flag = 1
                    break
        if flag == 0:
            for i in reversed(possible):
                if (string[:i] * (N / i)) == string:
                    print N / i
                    flag = 1
                    break
        if flag == 0:
            print 1

    
if __name__ == "__main__":
    main()
