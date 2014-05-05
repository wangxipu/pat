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

def reverseNumWithRadix(num, D):
    li = []
    quo, rem = divmod(num, D)
    while quo != 0:
        li.append(str(rem))
        quo, rem = divmod(quo, D)
        
    li.append(str(rem))
    return int(''.join(li), D)

if __name__ == '__main__':
    while 1:
        string = raw_input()
        if string[0] == '-':
            break
        N, D = [ int(x) for x in string.split() ]
        try:
            if isPrime(N) and \
                isPrime(reverseNumWithRadix(N, D)):
                print 'Yes'
            else:
                print 'No'
        except:
            print 'No'
