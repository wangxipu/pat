#!/usr/bin/env python 

def myCmp(a, b):
    return cmp(''.join([a, b]), ''.join([b, a]))

if __name__ == '__main__':
    li = raw_input().split()
    del li[0]
    li.sort(cmp = myCmp)
    str1 = li[0]
    str1_len = len(str1)
    i = 0
    while i < str1_len:
        if str1[i] == '0':
            i += 1
        else:
            break
    # strip the leading 0's
    if i < str1_len:
        li[0] = str1[i:]
    else:
        li[0] = ''

    for x in li[1:]:
        if int(x) != 0:
            print ''.join(li)
            import sys
            sys.exit(0)
    # if all 0's
    print '0'
    
