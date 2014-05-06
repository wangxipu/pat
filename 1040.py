#!/usr/bin/env python 


def getSymLen(str1, pos, str1_len):
    # aba
    count1 = 0
    low = pos - 1
    high = pos + 1
    while low >= 0 and high < str1_len and str1[low] == str1[high]:
        count1 += 1
        low -= 1
        high += 1
    len1 = 2 * count1 + 1
    
    # abba
    low = pos
    high = pos + 1
    count2 = 0
    while low >= 0 and high < str1_len and str1[low] == str1[high]:
        count2 += 1
        low -= 1
        high += 1
    len2 = 2 * count2
    return max(len1, len2)

if __name__ == '__main__':
    string = raw_input()
    string_len = len(string)
    max_len = 0
    for i in xrange(string_len):
        len_this = getSymLen(string, i, string_len)
        if len_this > max_len:
            max_len = len_this
    print max_len
            

