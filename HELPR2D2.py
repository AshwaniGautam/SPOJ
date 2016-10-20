ans = 0
MAX = 100000

def update(low, high, pos, value):
    global ans
    global K
    global waste
    if (low == high):
        if ST[pos] == K:
            ans += 1
            waste += K
        ST[pos] -= value
        waste -= value
        return
    
    mid = (low + high) / 2
    if ST[2*pos+1] >= value:
        update(low, mid, 2*pos+1, value)
    else:
        update(mid+1, high, 2*pos+2, value)
    ST[pos] = max(ST[2*pos+1], ST[2*pos+2])


    
for _ in xrange(int(raw_input())):
    global K
    global waste
    ans = 0
    K = int(raw_input())
    ST = [K] * 400001
    q = int(raw_input())
    count = 0
    waste = 0
    while(count < q):
        inp = raw_input()
        if inp[0] != 'b':
            update(0, MAX-1, 0, int(inp))
            count += 1
        else:
            inp = inp.split()
            for ___ in xrange(int(inp[1])):
                update(0, MAX-1, 0, int(inp[2]))
            count += int(inp[1])
    print ans, waste
