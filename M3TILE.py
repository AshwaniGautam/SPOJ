'''The darkest place in the hell are reserved for those who maintain their
neutrality in the time of moral crisis.
'''
t = [0]*35
f = [0]*35
t[0] = 1
f[0] = 0
for i in xrange(1,31):
    t[i] = 3*t[i-2] + 2*f[i-3]
    f[i] = t[i-1] + f[i-2]
while 1:
    n = (int(raw_input()))
    if n != -1:
        print t[n]
    else:
        break
