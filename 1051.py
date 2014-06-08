#!/usr/bin/env python

class Stack: 
    def __init__(self): 
        self._items = []
        self._size = 0
         
    def empty(self): 
        return self._size == 0  
     
    def push(self, item): 
        self._items.append(item) 
        self._size += 1
     
    def pop(self): 
        self._items.pop()
        self._size -= 1
    
    def top(self):
        return self._items[-1]
     
    def size(self): 
        return self._size  
    
if __name__ == '__main__':
    li  = [ int(x) for x in raw_input().split() ]
    M = li[0]
    N = li[1]
    K = li[2]

    for i in xrange(K):
        s = Stack()
        flag = True
        cur = 1
        for x in raw_input().split():
            num = int(x)
            if flag:
                while s.empty() or s.top() != num:
                    s.push(cur)
                    if s.size() > M:
                        flag = False
                        break
                    cur += 1
                if flag and s.size() >= 1 \
                        and s.top() == num:
                    s.pop()
        if flag:
            print 'YES'
        else:
            print 'NO'
