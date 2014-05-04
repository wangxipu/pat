#!/usr/bin/env python

def isPrime(n):
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if 0 == n % 2:
        return False        
    if any(n % x == 0 for x in xrange(3, int(n ** 0.5) + 1, 2)):     
        return False   
    return True
 
def getPrime(n):
    if isPrime(n):
        return n
    inc = 1
    if n != 1 and n % 2 != 0:
        inc = 2
    x = n + inc
    while 1:
        if isPrime(x):
            break
        x = x + 2
    return x       
 
def insertToHashTale(table, TSize, x):
    original_pos = x % TSize
    for i in xrange(TSize):
        pos = (original_pos + i * i) % TSize
        if table[pos] == -1:
            table[pos] = 1
            return pos
    return -1
        
if __name__ == '__main__':
    MSize, N = [ int(x) for x in raw_input().split() ]
    li = [ int(x) for x in raw_input().split() ]
    TSize = getPrime(MSize)    
    HashTable = [ -1 for x in xrange(TSize + 1) ]
    out_list = []
    for i in xrange(N):
        pos = insertToHashTale(HashTable, TSize, li[i]) 
        if pos != -1:
            out_list.append(str(pos))
        else:
            out_list.append('-')

    print ' '.join(out_list)
    
