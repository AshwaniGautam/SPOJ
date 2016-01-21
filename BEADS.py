import sys
def main():
    for _ in xrange(int(raw_input())):
        string = (sys.stdin.readline().strip()) * 2
        N = len(string) / 2
        current = 0
        old = string[: N]
        for i in xrange(1, N):
            if string[i: N + i] < old:
                old = string[i: N + i]
                current = i
        print current + 1
        
if __name__ =="__main__":
    main()
