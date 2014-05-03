#!/usr/bin/env python


def HogwartsSum(A, B):
    alist = A.split('.')
    blist = B.split('.')
    Knut = int(alist[2]) + int(blist[2])
    carry, Knut = divmod(Knut, 29)

    Sickle = int(alist[1]) + int(blist[1]) + carry
    carry, Sickle = divmod(Sickle, 17)

    Galleon = int(alist[0]) + int(blist[0]) + carry
    
    print '%d.%d.%d' %(Galleon, Sickle, Knut)

if __name__ == '__main__':
    strings = raw_input().split()
    HogwartsSum(strings[0], strings[1])
