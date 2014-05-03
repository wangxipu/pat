#!/usr/bin/env python

similar_map = {
    '1' : '@',
    '0' : '%',
    'l' : 'L',
    'O' : 'o'
    }

class Info:
    def __init__(self, name, passwd):
        self.name = name
        self.passwd = passwd
        self.modified = False
    def replace(self):
        for i in xrange(len(self.passwd)):
            if self.passwd[i] in similar_map:
                self.passwd[i] = similar_map[self.passwd[i]]
                self.modified = True
    def tostring(self):
        return '%s %s' % (self.name, ''.join(self.passwd))
        
if __name__ == '__main__':
    recoreds = int(raw_input())
    i = 0 
    stus = []
    while i < recoreds:
        st = raw_input().split()
        stus.append(Info(st[0], list(st[1])))
        i += 1
        
    modified_num = 0
    out_list = []
    for i in stus:
        i.replace()
        if i.modified:
            modified_num += 1
            out_list.append(i.tostring())
    if modified_num > 0:
        print modified_num
        print '\n'.join(out_list)
        
    elif recoreds == 1:
        print "There is 1 account and no account is modified"
    else:
        print "There are %s accounts and no account is modified" % recoreds
        
        
