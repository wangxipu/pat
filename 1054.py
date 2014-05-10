#!/usr/bin/env python

if __name__ == '__main__':
    li = [ int(x) for x in raw_input().split() ]
    M = li[0]
    N = li[1]
    count_map = {}
    max_count = -1
    index = -1
    for i in xrange(N):
        for x in raw_input().split():
            x = int(x)
            this = count_map[x] = count_map.get(x, 0) + 1
            if this > max_count:
                max_count = this
                index = x
    
    print index
