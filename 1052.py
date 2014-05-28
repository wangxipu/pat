#!/usr/bin/env python
import sys
class Node:
    def __init__(self, key, next):
        self.key = key
        self.next = next
    def tostring(self):
        print '%05d %d' %(self.next, self.key),

if __name__ == '__main__':
    li = raw_input().split()
    n = int(li[0])
    head = int(li[1])
    nodes = []
    node_map = {}
    for i in xrange(n):
        li = [ int(x) for x in raw_input().split() ]
        node = Node(li[1], li[2])
        node_map[li[0]] = node
        
    addr = head
    while addr != -1:
        v = node_map.get(addr, None)
        if v == None:
            break
        else:
            node = Node(v.key, addr)
            nodes.append(node)
            addr = v.next

    nodes_len = len(nodes)
    if nodes_len == 0:
        print '0 -1'
        sys.exit(1)
    nodes.sort(cmp = lambda a, b : cmp(a.key, b.key))
    print '%d %05d' %(nodes_len, nodes[0].next)
    for i in xrange(nodes_len):
        nodes[i].tostring()
        if nodes_len - i >= 2:
            print '%05d' %(nodes[i + 1].next)
        else:
            print -1
