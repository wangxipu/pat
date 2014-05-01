#!/usr/bin/env python

if __name__ == '__main__':
    string = raw_input()
    digits = set()
    for i in string:
        digits.add(i)

    double_it = str(2 * int(string))
    digits2 = set()
    for i in double_it:
        digits2.add(i)

    if digits == digits2:
        print 'Yes'
    else:
        print 'No'

    print double_it
    

    
