#!/usr/bin/env python
from decimal import *

if __name__ == '__main__':
    out_list = []
    product = 1
    result = ['W', 'T', 'L']
    for i in xrange(3):
        li = [ Decimal(x) for x in raw_input().split() ]
        max_odds = li[0]
        index = 0
        for j in xrange(1, 3):
            if li[j] > max_odds:
                max_odds = li[j]
                index = j
        out_list.append(result[index])
        product *= max_odds

    f = ((product * Decimal('0.65')) - 1) * 2
    print ' '.join(out_list),
    print '%.2f' % f
        
    
