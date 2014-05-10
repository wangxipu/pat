#!/usr/bin/env python 

class Pos:
    def __init__(self, pos, count):
        self.pos = pos
        self.count = count

if __name__ == '__main__':
    li = raw_input().split()
    bets = {}
    for index, x in enumerate(li):
        # ignore the first count number
        if index == 0:
            continue
        if x not in bets:
            bets[x] = Pos(index, 0)
        else:
            bets[x].count += 1

    if len(bets) > 0:
        min_pos = len(li) + 1
        for k, v in bets.iteritems():
            if v.count == 0:
                if min_pos > v.pos:
                    min_pos = v.pos
            
        if min_pos == len(li) + 1:
            print 'None'
        else:
            print li[min_pos]
    else:
        print 'None'

