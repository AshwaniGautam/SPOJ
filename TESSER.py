import sys


def Convert(array, N):
    s = []
    for i in xrange(1, N):
        if array[i] > array[i - 1]:
            s.append('G')
        elif array[i] < array[i - 1]:
            s.append('L')
        else:
            s.append('E')
    return ''.join(s)

def KMP(pattern, text,  N, M):
        pi = Prefix_Function(pattern, M)
        q = 0
        flag = 0
        for i in xrange(N - 1):
            while pattern[q] <> text[i]:
                if q == 0:
                    break
                q = pi[q - 1]
                
            if pattern[q] == text[i]:
                q += 1

            if q == M:
                print "YES"
                return
        print "NO"
        return 
                
def Prefix_Function(pattern, M):
        pi = [0] * M
        k = 0
        for i in xrange(1, M):
            while pattern[k] <> pattern[i]:
                if k == 0:
                    break
                k = pi[k - 1]
                
            if pattern[k] == pattern[i]:
                k += 1
                
            pi[i] = k
        return pi

def main():
    
    for _ in xrange(int(sys.stdin.readline().strip())):
        N = int(sys.stdin.readline().strip())
        array = map(int, sys.stdin.readline().strip().split())
        string = sys.stdin.readline().strip()
        text = Convert(array, N)
        M = len(string)
        KMP(string, text, N - 1, M)
        
if __name__ == "__main__":
    main()
