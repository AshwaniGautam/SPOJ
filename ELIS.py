'''The darkest place in the hell are reserved for those who maintain their
neutrality in the time of moral crisis.
'''
N = int(raw_input())
array = map(int, raw_input().split())
lis = [array[0]]
for i in array[1:]:
    if i > lis[-1]:
        lis.append(i)
    elif i == lis[-1]:
        continue
    else:
        for j in xrange(len(lis)):
            if lis[j] == i:
                break
            if lis[j] > i:
                lis[j] = i
                break
print len(lis)
