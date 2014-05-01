#!/usr/bin/env python
if __name__ == '__main__':
    input_string = raw_input()
    li = input_string.split(' ')
    
    sum1 = int(li[0]) + int(li[1])
    sum1 = str(sum1)
    
    i = len(sum1) - 1
    x = 0

    new_string = []
    while i >= 0:
        if x == 3:
            if sum1[i] != '-':
                new_string.append(',')
            else:  # this is minus char
                new_string.append(sum1[i])
                i = i - 1
            x = 0
        else:
            new_string.append(sum1[i])
            i = i - 1
            x = x + 1

    
    print ''.join(new_string[::-1])

        
