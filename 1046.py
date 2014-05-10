#!/usr/bin/env python

if __name__ == '__main__':
    summ = 0
    nodes = []
    nodes.append(0)
    for i, x in enumerate(raw_input().split()):
        if i == 0:
            continue
        x = int(x)
        summ += x
        nodes.append(nodes[i - 1] + x)

    exit_pair_count = int(raw_input())
    for i in xrange(exit_pair_count):
        li = [ int(x) for x in raw_input().split() ]
        a = li[0]
        b = li[1]
        if a > b:
            a, b = b, a
        total = nodes[b - 1] - nodes[a - 1]
        
        print min(total, summ - total)
        
                         
                         
