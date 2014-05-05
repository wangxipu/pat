#!/usr/bin/env python 

import re
def wordCount(string):
    count = 0
    max_word = ''
    word_occ = {}
    word_list = re.findall('[0-9a-zA-Z]+', string)
    for word in word_list:
        this = word_occ[word] = word_occ.get(word, 0) + 1
        if this > count:
            count = this
            max_word = word
    return max_word, count

if __name__ == '__main__':
    string = raw_input().lower()
    
    print '%s %d' % (wordCount(string))
