#!/usr/bin/env python

if __name__ == '__main__':
    num = int(raw_input())
    input_list = []
    min_len = 2 ** 10
    for i in xrange(num):
        line = raw_input()[::-1]
        input_list.append(line)
        line_len = len(line)
        if line_len < min_len:
            min_len = line_len 
    
    out_list = []
    for i in xrange(min_len):
        break_it = False
        ch = input_list[0][i]
        for j in xrange(1, num):
            if input_list[j][i] != ch:
                break_it = True
                break
        if break_it:
            break
        out_list.append(ch)
        
    if len(out_list) == 0:
        print 'nai'
    else:
        out_list.reverse()
        print ''.join(out_list)
   

