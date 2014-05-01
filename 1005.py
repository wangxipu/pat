#!/usr/bin/env python
eng_map = {
        '0' : "zero",
        '1' : "one",
        '2' : "two",
        '3' : "three",
        '4' : "four",
        '5' : "five",
        '6' : "six",
        '7' : "seven",
        '8' : "eight",
        '9' : "nine"
        }
def getEnglish(i):
    return eng_map[i]

if __name__ == '__main__':
    string = raw_input()
    num = 0
    for i in xrange(len(string)):
        num += int(string[i])
    string = str(num)
    out_list = []
    for i in xrange(len(string)):
        out_list.append(getEnglish(string[i]))
    print ' '.join(out_list)
