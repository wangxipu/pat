#!/usr/bin/env python

def is_palindromic_number(r):
    a = str(r)
    b = a[::-1]
    if a == b:
        return True
    else:
        return False

def get_it(n, k):
    for i in xrange(k):
        if is_palindromic_number(n):
            print n 
            print i
            break
        n = int(n) + int(str(n)[::-1])
    else:
        print n
        print i + 1
    
if __name__ == '__main__':
    li = raw_input().split() 
    n = li[0]
    k = int(li[1])
    get_it(n, k)
