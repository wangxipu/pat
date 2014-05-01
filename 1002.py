#!/usr/bin/env python 

MAX_P = 1001
def getPolylist():
    line1 = raw_input()
    li1 = line1.split(' ')
    max_exp = len(li1)
    poly1 = [ 0 for i in xrange(MAX_P) ]
    i = 1
    while i < max_exp:
        poly1[int(li1[i])] = float(li1[i + 1])
        i += 2
    return poly1

if __name__ == '__main__':
    poly1 = getPolylist()
    poly2 = getPolylist()
    poly3 = [ 0 for i in xrange(MAX_P) ]   
    exp = 0
    for i in xrange(MAX_P):
        poly3[i] = poly1[i] + poly2[i]
        if poly3[i] != 0:
            exp += 1
    output = "%d" % exp 
    for i in xrange(MAX_P - 1, -1, -1):
        if poly3[i] != 0:
            output += " %d %.1f" %(i, poly3[i])
    print  output

