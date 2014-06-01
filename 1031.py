#!/usr/bin/env python

if __name__ == '__main__':
    string = raw_input()
    n = len(string)
    n1 = (n + 2) / 3
    n2 = n + 2 - 2 * n1
    space = ' ' * (n2 - 2)
    for i in xrange(n1 - 1):
        print '%c%s%c' %(string[i], space, string[n - 1 - i])
    print string[n1 - 1:n1 + n2 -1]
        
