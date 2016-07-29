'''The darkest places in the hell are reserved for those who maintain their
neutrality in the time of moral crisis.
Religion and GOD are the only shit between development and India.
'''
MOD = 1000000007
for _ in xrange(int(raw_input())):
    string = raw_input()
    dicti = {}
    array = [2]
    dicti[string[0]] = 1
    for i in string[1:]:
        if i in dicti.keys():
            array.append((array[-1] + array[-1] - dicti[i]) % MOD)
        else:
            array.append((2*array[-1]) % MOD)
        dicti[i] = array[-2]
    print array[-1]
