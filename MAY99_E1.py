from collections import *
string = raw_input()
d = defaultdict(int)
for i in string:
    d[i] += 1
j, value = '\x96', 0
for i in d:
    print i, d[i]
    if d[i] >= value and ord(i) < ord(j):
        value = d[i]
        j = i
print j
