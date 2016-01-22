def main():
    N, Q = map(int, raw_input().split())
    BIT = [0] * (N + 1)
    for _ in xrange(Q):
        arr = raw_input().split()
        if arr[0] == 'find':
             L, R, Left, Right = int(arr[1]) - 1, int(arr[2]), 0, 0 
             while R > 0:
                 Right += BIT[R]
                 R = R - (-R & R)
             while L > 0:
                 Left += BIT[L]
                 L = L - (-L & L)
             print (Right - Left)
        else:
            index, value = int(arr[1]), int(arr[2])
            while index <= N:
                BIT[index] += value
                index = index + (-index & index)
if __name__ == "__main__":
    main()
