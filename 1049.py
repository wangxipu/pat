#!/usr/bin/env python

# runtime of python version is more than 10 ms 
# because of the implementation 
if __name__ == '__main__':
    string = raw_input()
    n = int(string)
    r = 1
    counts_for_1 = 0
    ret, rem = divmod(n, r)
    while ret != 0:
        left = ret / 10
        current = ret % 10
        right = rem
        if current == 1:
            counts_for_1 += right + 1 + left * r
        elif current > 1:
            counts_for_1 += (left + 1) * r
        else:
            counts_for_1 += left * r
        r *= 10
        ret, rem = divmod(n, r) 
    print counts_for_1
    print r
