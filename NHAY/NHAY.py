__author__ = "Ashwani Gautam"

import sys


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
        start = -1
        if haystack.find(needle) == -1:
            continue
        while 1:
            if haystack.find(needle, start + 1) == -1:
                break
            else:
                start = haystack.find(needle, start + 1)
                print start
        print
        print

if __name__ == "__main__":
    main()
