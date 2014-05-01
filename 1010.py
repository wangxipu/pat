#!/usr/bin/env python

d = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,
     '9':9,'a':10,'b':11,'c':12,'d':13,'e':14,'f':15,'g':16,'h':17,
     'i':18,'j':19,'k':20,'l':21,'m':22,'n':23,'o':24,'p':25,'q':26,
     'r':27,'s':28,'t':29,'u':30,'v':31,'w':32,'x':33,'y':34,'z':35}

def getRadix(n1, n2, radix):
    v1 = 0
    for i in n1:
        v1 = v1 * radix + d[i]
    lower = d[max(n2)] + 1
    upper = lower if v1 + 1 < lower else v1 + 1
    while lower <= upper:
        mid = (lower + upper) / 2
        v2 = 0
        for j in n2:
            v2 = v2 * mid + d[j]
        if v2 == v1:
            print mid
            break
        elif v2 < v1:
            lower = mid + 1
        else:
            upper = mid - 1
    else: 
      print 'Impossible'
    
def main():
    string = raw_input()
    li = string.split(' ')
    tag = li[2]
    if tag == '1':
        getRadix(li[0], li[1], int(li[3]))
    elif tag == '2':
        getRadix(li[1], li[0], int(li[3]))

if __name__ == '__main__':
    main()
