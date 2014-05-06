#!/usr/bin/env python

class Student:
    def __init__(self, name, idd, grade):
        self.name = name
        self.idd = idd
        self.grade = grade

if __name__ == '__main__':
    num = int(raw_input())
    min_grade_student_M = Student('no_this_record', '-1', 101)
    max_grade_student_F = Student('no_this_record', '-1', -1)
    for i in range(num):
        string = raw_input()
        li = string.split()
        grade = int(li[3])
        if li[1] == 'M':
            if grade < min_grade_student_M.grade:
                min_grade_student_M = Student(li[0], li[2], grade)
        else: # F
            if grade > max_grade_student_F.grade:
                max_grade_student_F = Student(li[0], li[2], grade)

    missing_one = False
    if max_grade_student_F.idd != '-1':
        print '%s %s' % (max_grade_student_F.name, max_grade_student_F.idd)
    else:
        missing_one = True
        print 'Absent'
    
    if min_grade_student_M.idd != '-1':
        print '%s %s' % (min_grade_student_M.name, min_grade_student_M.idd)
    else:
        missing_one = True
        print 'Absent'

    if not missing_one:
        print max_grade_student_F.grade - min_grade_student_M.grade
    else:
        print 'NA'
    
