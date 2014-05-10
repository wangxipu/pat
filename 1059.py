#!/usr/bin/env python

def isPrime(n):
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if 0 == n % 2:
        return False
    if any(n % x == 0 for x in xrange(3, int(n ** 0.5) + 1, 2)):
        return False
    return True

# not TLE
if __name__ == '__main__':
    n = int(raw_input())
    out_string = '%d=' % n
    if n == 1:
        print '%s%d' %(out_string, n)
        import sys
        sys.exit(0)
    else:
        out_list = []
        out_list.append(out_string)
        temp = n
        i = 2
        while i <= temp:
            k = 0
            if isPrime(i):
                while n % i == 0:
                    k += 1
                    n = n / i
            if k > 1:
                out_list.append('%d^%d' % (i, k))
            elif k == 1:
                out_list.append('%d' % i)
            if n != 1 and k >= 1:
                out_list.append('*')
            if n == 1:
                break
            if i == 3:
                i += 2
            else:
                i += 1
    print ''.join(out_list)
            
