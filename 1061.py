#!/usr/bin/env python

week = {
    'A' : 'MON',
    'B' : 'TUE',
    'C' : 'WED',
    'D' : 'THU',
    'E' : "FRI",
    'F' : 'SAT',
    'G' : 'SUN'}

hour = {
    '0' : 0, '1' : 1, '2' : 2, '3' : 3, '4' : 4, 
    '5' : 5, '6' : 6, '7' : 7, '8' : 8, '9' : 9,
    'A' : 10, 'B' : 11, 'C' : 12, 'D' : 13, 'E' : 14,
    'F' : 15, 'G' : 16, 'H' : 17, 'I' : 18, 'J' : 19,
    'K' : 20, 'L' : 21, 'M' : 22, 'N' : 23
     }
def getDay(str1, str2):
    day = ''
    hr = ''
    if len(str1) > len(str2):
        str_small, str_big = str2, str1
    else:
        str_small, str_big = str1, str2
    
    for i in xrange(len(str_small)):
        if 'A' <= str_small[i] <= 'G' \
                and str_small[i] == str_big[i]:
            day = week[str_small[i]]
            break
    for j in xrange(i + 1, len(str_small)):
        if ('A' <= str_small[j] <= 'N' or '0' <= str_small[j] <= '9') and \
                str_small[j] == str_big[j]:
            hr = hour[str_small[j]]
            break
    return day, hr

def getMin(str1, str2):
    if len(str1) > len(str2):
        str_small, str_big = str2, str1
    else:
        str_small, str_big = str1, str2
    
    for i in xrange(len(str_small)):
        if str_small[i].isalpha() and str_small[i] == str_big[i]:
            return i

if __name__ == '__main__':
    string1 = raw_input()
    string2 = raw_input()
    string3 = raw_input()
    string4 = raw_input()
    d, hr = getDay(string1, string2)
    m = getMin(string3, string4)
    print '%s %02d:%02d' % (d, hr, m)
