#!/usr/bin/env python


if __name__ == '__main__':
    string = raw_input()
    li = string.split(' ')
    li = [int(x) for x in li ]

    li[0] = 0
    
    total_time = 0
    for i in xrange(1, len(li)):
        diff = li[i] - li[i - 1]
        if diff > 0:
            total_time += diff * 6 + 5
        else:
            total_time += -diff * 4 + 5

    print total_time
