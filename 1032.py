#!/usr/bin/env python

# timeout for the last case
# whether or not using dict 

if __name__ == '__main__':
    li = raw_input().split()
    addr_start1 = li[0]
    addr_start2 = li[1]
    node_count = int(li[2])
    
    if addr_start1 == addr_start2:
        print addr_start1
        import sys
        sys.exit(0)

    node_map = {}
    for i in xrange(node_count):
        li = raw_input().split() 
        addr = li[0]
        node_map[addr] = li[2]

    mark_list = {}
    st = addr_start1
    pos = '0'
    while st != '-1':
        mark_list[st] = '1'
        st = node_map[st]

    st = addr_start2
    while st != '-1':
        if mark_list.get(st, '-1') == '1':
           pos = st
           break
        st = node_map[st]

    if pos == '0':
        print -1
    else:
        print pos
