#!/usr/bin/env python

if __name__ == '__main__':
    li = [ int(x) for x in raw_input().split() ]
    students_num = li[0]
    courses_num = li[1]
    courses = [ [] for x in xrange(courses_num) ]
    for i in xrange(students_num):
        li = raw_input().split()
        name = li[0]
        n = int(li[1])
        for k in xrange(n):
            courses[int(li[k + 2]) - 1].append(name)

    for i in xrange(len(courses)):
        n = len(courses[i])
        print i + 1, n
        courses[i].sort()
        for k in courses[i]:
            print k
        

