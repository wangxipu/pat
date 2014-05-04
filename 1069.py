#!/usr/bin/env python

def getMaxAndMin(str1):
    li = list(str1)
    li.sort(reverse = True)
    str_max = ''.join(li)
    str_min = str_max[::-1]
    return str_max, str_min

if __name__ == '__main__':
    string = raw_input()
    if len(string) < 4:
        # such as 111, padding with '0'
        string = '0' * (4 - len(string)) + string
    if len(set(list(string))) == 1:
        print '%s - %s = 0000' %(string, string)
        import sys
        sys.exit(0)
    while 1:
        this_max, this_min = getMaxAndMin(string)
        diff = int(this_max) - int(this_min)
        diff = '%04d' % diff
        print '%s - %s = %s' %(this_max, this_min, diff)
        if diff == '6174':
            break
        else:
            string = diff

