#!/usr/bin/env python

def addtomap(map1, idd, key):
    vp = map1.get(key, [])
    vp.append(idd)
    map1[key] = vp

def getfrommap(map1, key):
    v = map1.get(key, [])
    if len(v) == 0:
        print "Not Found"
    else:
        v.sort()
        for x in v:
            print x

if __name__ == '__main__':
    num = int(raw_input())
    title_map = {}
    author_map = {}
    keyword_map = {}
    publiser_map = {}
    year_map = {}
    for i in xrange(num):
        idd = raw_input()
        title = raw_input()
        addtomap(title_map, idd, title)
        author = raw_input()
        addtomap(author_map, idd, author)
        keywords = raw_input().split()
        for k in keywords:
            addtomap(keyword_map, idd, k)

        publiser = raw_input()
        addtomap(publiser_map, idd, publiser)
        year = int(raw_input())
        addtomap(year_map, idd, year)
        
    queries = int(raw_input())
    for j in xrange(queries):
        string = raw_input()
        seq = string[0]
        q = string[3:]
        print string
        if seq == '1':
            getfrommap(title_map, q)
        elif seq == '2':
            getfrommap(author_map, q)
        elif seq == '3':
            getfrommap(keyword_map, q)
        elif seq == '4':
            getfrommap(publiser_map, q)
        elif seq == '5':
            getfrommap(year_map, int(q))
            
