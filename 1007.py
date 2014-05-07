#!/usr/bin/env python

class Node:
    def __init__(self, num, start, summ):
        self.num = num
        self.start = start
        self.summ = summ

if __name__ == '__main__':
    num = int(raw_input())
    Nodes = [ Node(int(x), -1, -1) for x in raw_input().split() ]
    
    Nodes[0].summ = Nodes[0].num
    Nodes[0].start = 0
    mmax = Nodes[0].summ
    index = 0
    for i in xrange(1, num):
        if Nodes[i - 1].summ >= 0:
            Nodes[i].summ = Nodes[i - 1].summ + Nodes[i].num
            Nodes[i].start = Nodes[i - 1].start
        else:
            Nodes[i].summ = Nodes[i].num
            Nodes[i].start = i
        if mmax < Nodes[i].summ:
            index = i
            mmax = Nodes[i].summ

    if mmax < 0:
        print '0 %d %d' % (Nodes[0].num, Nodes[num - 1].summ)
    else:
        print '%d %d %d' % (Nodes[index].summ, 
                            Nodes[Nodes[index].start].num, 
                            Nodes[index].num)
