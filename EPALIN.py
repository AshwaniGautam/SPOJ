__author__ = "Ashwani Gautam"
import sys


def main():
    for line in sys.stdin:
        original = line.strip()
        n = len(original)
        if original == original[::-1]:
            print original
            continue
        c = original[n - 1]
        for i in xrange(1, n):
            if original[i] == c:
                if original[i:] == original[n-1: i-1: -1]:
                    print original + original[i - 1: :-1]
                    break
    


if __name__ == "__main__":
    main()
