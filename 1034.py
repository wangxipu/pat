#!/usr/bin/env python

idx = 0
allWeight = 0
st = ''

def dfs(x, flag, weight, link):
    global idx
    global allWeight
    global st
    flag[x] = True
    w = weight[x]
    allWeight += w
    if w > weight[st]:
        st = x

    for i in link[x]:
        if not flag[i]:
            dfs(i, flag, weight, link)
    idx += 1

if __name__ == '__main__':
    li = [ int(x) for x in raw_input().split() ]
    n = li[0]
    threshold = li[1]

    weight = {}
    link = {}
    # was this node visited?
    flag = {}
    out = {}
    for i in xrange(n):
        li = raw_input().split()
        aname = li[0]
        bname = li[1]
        w = int(li[2])
        weight[aname] = weight.get(aname, 0) + w
        weight[bname] = weight.get(bname, 0) + w
        if aname not in link:
            li = []
            li.append(bname)
            link[aname] = li
        else:
            link[aname].append(bname)
        if bname not in link:
            li = []
            li.append(aname)
            link[bname] = li
        else:
            link[bname].append(aname)
            
        flag[aname] = False
        flag[bname] = False

    for k, v in flag.iteritems():
        if not v:
            idx = 0
            allWeight = 0
            st = k
            dfs(k, flag, weight, link)
            if idx > 2 and allWeight / 2 > threshold:
                out[st] = idx

    
    print len(out)
    li = sorted(out.keys())
    for x in li:
        print '%s %d' % (x, out[x])
