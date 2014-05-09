#!/usr/bin/env python

# Palindromic Number
def itoa(x, base):
    li = []
    quo, rem = divmod(x, base)
    li.append(str(rem))
    while quo != 0:
        x = quo
        quo, rem = divmod(x, base)
        li.append(str(rem))
    return li[::-1]

if __name__ == '__main__':
    li = raw_input().split()
    n = int(li[0])
    base = int(li[1])
    li = itoa(n, base)
    i = 0
    j = len(li) - 1
    while i <= j and li[i] == li[j]:
        i += 1
        j -= 1

    # even or odd number of digits
    if i - j == 1 or i - j == 2:
        print 'Yes'
    else:
        print 'No'    
    print ' '.join(li)
