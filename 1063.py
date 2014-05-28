#!/usr/bin/env python

if __name__ == '__main__':
    n = int(raw_input())
    v = []
    for i in xrange(n):
        li = [ int(x) for x in raw_input().split() ]
        li = li[1:]
        v.append(li)

    nq = int(raw_input())
    similarity_cache = {}
    set_cache = {}
    for i in xrange(nq):
        string = raw_input()
        if string in similarity_cache:
            res = similarity_cache[string]
        else:
            li = string.split() 
            index_a = int(li[0]) - 1
            index_b = int(li[1]) - 1
            if index_a in set_cache:
                a = set_cache[index_a]
            else:
                a = set(v[index_a])
                set_cache[index_a] = a
            if index_b in set_cache:
                b = set_cache[index_b]
            else:
                b = set(v[index_b])
                set_cache[index_b] = b
            res = '%.1f%%' % (len(a&b) * 100.0 / len(a|b))
            similarity_cache[string] = res
            similarity_cache[' '.join(li[::-1])] = res
        print res
