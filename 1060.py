#!/usr/bin/env python

def get_digits(x, n):
    x_origin = x
    i = 0 # position of the first non-zero digit 
    j = 0 # beginning of the dot
    # 0.025
    # 00.025
    # trim the leading 0's
    while i < len(x):
        if x[i] == '0':
            i += 1
        elif x[i] == '.':
            j = i
            i += 1
        else:
            break
        
    if i != 0:
        x = x[i:]

    x = x.replace('.', '')
    x_no_leading_0s_no_dot = x
    # padding with 0's if less than demanded significant digits
    x_len = len(x)
    if x_len < n:
        x += '0' * (n - x_len)
    else:
        x = x[0:n]

    x_float = float(x_origin)
    x_int = int(x_float)
    x_str = str(x_int)
    # 0.00
    # 0.005
    if x_int == 0 and x_no_leading_0s_no_dot != '':
        k = -(i - j - 1)
    else:
        # 0.25
        # 925.6
        k = len(x_str) if x_str != '0' else 0
    return '0.%s*10^%d' % (x, k)
    
if __name__ == '__main__':
    li = [ x for x in raw_input().split() ]
    N = int(li[0])
    A = li[1]
    B = li[2]
    A_format = get_digits(A, N)
    B_format = get_digits(B, N)
    if A_format != B_format:
        print 'NO %s %s' % (A_format, B_format)
    else:
        print 'YES %s' % (A_format)
        
