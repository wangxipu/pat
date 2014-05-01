#!/usr/bin/env python


import os

if __name__ == '__main__':
    num = raw_input();
    
    i = 0
    while i < int(num):
        numbers = raw_input().strip()
        li = numbers.split(' ')

        if int(li[0]) + int(li[1]) > int(li[2]):
            print "Case #%d: %s" %(i + 1, 'true')
        else:
            print "Case #%d: %s" %(i + 1, 'false')
        
        i = i + 1
