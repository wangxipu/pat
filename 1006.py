#!/usr/bin/env python

import time
def getTimeStamp(string):
    return int(time.mktime(time.strptime(string, '%Y %H:%M:%S')))

if __name__ == '__main__':
    num = int(raw_input())
    id_first = ''
    id_last = ''
    time_first = getTimeStamp('2015 23:59:59')
    time_last = 0

    for i in xrange(num):
        li = raw_input().split()
        idd = li[0]
        sign_in_time = getTimeStamp('2014 %s' % li[1])
        sign_out_time = getTimeStamp('2014 %s' % li[2])
        if sign_in_time < time_first:
            time_first = sign_in_time
            id_first = idd
        if sign_out_time > time_last:
            time_last = sign_out_time
            id_last = idd
    
    print '%s %s' % (id_first, id_last)
