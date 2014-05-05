#!/usr/bin/env python

d = {                                                                            
    0 : '0', 1 : '1', 2 : '2', 3 : '3', 4 : '4',                                     
    5 : '5', 6 : '6', 7 : '7', 8 : '8', 9 : '9',                                     
    10 : 'A', 11 : 'B', 12 : 'C' }

def getColorinMars(num):
    li = []
    D = 13
    quo, rem = divmod(num, D)
    while quo != 0:
        li[:0] = [ d[rem] ]
        quo, rem = divmod(quo, D)
        
    li[:0] = [ d[rem] ]
    return '0' * (2 - len(li)) + ''.join(li)

if __name__ == '__main__':
    r, g, b = [ int(x) for x in raw_input().split() ]
    print '#%s%s%s' % (getColorinMars(r), 
                       getColorinMars(g), 
                       getColorinMars(b)) 
