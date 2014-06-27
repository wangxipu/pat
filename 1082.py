#!/usr/bin/env  python

import sys

punct = [
'', 'Shi', 'Bai', 'Qian', "Wan", "Shi", "Bai", "Qian", "Yi"
]

digit_pinyin = {
    '0' : 'ling',
    '1' : 'yi',
    '2' : 'er',
    '3' : 'san',
    '4' : 'si',
    '5' : 'wu',
    '6' : 'liu',
    '7' : 'qi',
    '8' : 'ba',
    '9' : 'jiu'
}

if __name__ == '__main__':
    string = raw_input()
    out_list = [] 
    if string == '0':
        print digit_pinyin[string]
        sys.exit(0)

    if string[0] == '-':
        print 'Fu',
        string = string[1:]
        
    digits = string[::-1]    
    digits_len = len(digits) 
    
    e = 0
    while e < digits_len and digits[e] == '0':
        e += 1
    if e == 8:
        print '%s Yi' % digit_pinyin[digits[e]]
        sys.exit(0)
        
    i = e
    res = []
    if e > 4:
        res.append('Wan')

    while i < digits_len:
        if i != 0:
            if digits[i] != '0' or i == 4 or i == 8:
                res.append(punct[i])
        res.append(digit_pinyin[digits[i]])
        i += 1
        
    res_len = len(res)
    i = res_len - 1
    while i >= 0:
        if i != res_len - 1:
            pass
        cnt = 0
        while i >= 0 and res[i] == 'ling':
            i -= 1
            cnt += 1
        if cnt == 0:
            print res[i],
        elif cnt < 4: # 100000001
            if res[i] != 'Wan':
                print 'ling',
            print res[i],
        i -= 1
