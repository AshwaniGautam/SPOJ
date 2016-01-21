import sys


def z_function(string, z, lenth):

    left = 0
    right = 0

    for i in xrange(1, lenth):
        if i <= right:
             z[i] = min(z[i - left], right - i + 1)
        while i + z[i] < lenth and string[z[i]] == string[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > right:
            right = i + z[i] - 1
            left = i


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

        string = needle + '&' + haystack
        string = "BABB"

        lenth = len(string)
        z = [0] * lenth
        z_function(string, z, lenth)
        s = 0
        print z
        for i in xrange(n + 1, lenth - n + 1):
            if z[i] == n:
                s = 1
                print i - n - 1
        if s == 1:
            sys.stdout.write("\n\n")

if __name__ == "__main__":
    main()
