#!/usr/bin/env python

import re
class Stack:
    def __init__(self):
        self.items = []
    def push(self, x):
        self.items.append(x)
    def pop(self):
        if len(self.items) > 0:
            return self.items.pop()
        else:
            return 'Invalid'
    def empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)

MAXN = 100010
class BinTree:
    def __init__(self):
        self.a = [ 0 for x in xrange(MAXN) ]
    def lowbit(self, x):
        return x &(-x)
    
    def update(self, t, d):
        while t <= MAXN:
            self.a[t] += d
            t += self.lowbit(t)
    def getsum(self, t):
        sum1 = 0
        while t > 0:
            sum1 += self.a[t]
            t -= self.lowbit(t)
        return sum1

    def find(self, val, l = 0, h = MAXN - 1):
        if l == h:
            return l
        mid = (l + h) / 2
        if self.getsum(mid) < val:
            return self.find(val, mid + 1, h)
        else:
            return self.find(val, l, mid)


if __name__ == '__main__':
    num = int(raw_input())
    s = Stack()
    tree = BinTree()
    for i in xrange(num):
        string = raw_input()
        m = re.match('([a-zA-Z]+)([ ]?)([0-9]*)', string)
        cmd = m.group(1)
        if cmd == 'Push':
            element = int(m.group(3))
            s.push(element)
            tree.update(element, 1)
        elif cmd == 'Pop':
            if s.empty():
                print 'Invalid'
            else:
                n = s.pop()
                print n
                tree.update(n, -1)
        elif cmd == 'PeekMedian':
            if s.empty():
                print 'Invalid'
            else:
                print tree.find((s.size() + 1) / 2)
        else:
            print 'Invalid'    
