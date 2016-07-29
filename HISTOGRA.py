import sys

def merge(l, r):
    mid = (l+r) / 2
    m = min(histogram[mid], histogram[mid+1])
    if m == histogram[mid]:
        j = mid
    else:
        j = mid+1 
    sol = 0
    i = j
    while(i <= r and m <= histogram[i]):
        sol += m
        i += 1
    i = j-1
    while(i >= 0 and m <= histogram[i]):
        sol += m
        i -= 1
    return sol
        
def solve(l, r):
    if l == r:
        return histogram[l]
    mid = (l+r) / 2
    a = solve(l, mid)
    b = solve(mid + 1, r)
    c = merge(l, r)
    ans = max(a, b, c)
    return ans
    
while 1:
    histogram = map(int, sys.stdin.readline().strip().split())
    N = len(histogram)
    if (N == 1 and histogram[0] == 0):
        break
    print solve(0, N-1)
