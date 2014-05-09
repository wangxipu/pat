#!/usr/bin/env python
INF = 0x6fffffff  
class Customer:
    def __init__(self, arriving_time, processing_time):
        self.arriving_time = arriving_time
        self.processing_time = processing_time
        self.start_serve_time = 0

def my_cmp(a, b):
    return cmp(a.arriving_time, b.arriving_time)

def to_second(string):
    li = [ int(x) for x in string.split(':') ]
    return li[0] * 3600 + li[1] * 60 + li[2] 
        

if __name__ == '__main__':
    N, K = [ int(x) for x in raw_input().split() ]
    open_time = 8 * 3600
    close_time = 17 * 3600
    customers = []
    windows = [ open_time for x in xrange(K) ]
    m = N
    for i in xrange(N):
        li = raw_input().split()
        arriving_time = to_second(li[0])
        # can't serve the customer arrived after off-duty time
        if arriving_time > close_time:
            m -= 1
            continue
        processing_time = int(li[1]) * 60 # second
        customer = Customer(arriving_time, processing_time)
        customers.append(customer)

    customers.sort(cmp = my_cmp)
    wait_time = 0
    for i in xrange(m):
        minx = INF
        index = -1
        # find the available window
        for j in xrange(K):
            if minx > windows[j]:
                minx = windows[j]
                index = j
        customers[i].start_serve_time = max(windows[index], customers[i].arriving_time)
        windows[index] = customers[i].start_serve_time + customers[i].processing_time
        wait_time += customers[i].start_serve_time - customers[i].arriving_time

    # compute the average waiting time
    if wait_time > 0:
        print '%.1f' % (wait_time / 60.0 / m)
    else:
        print '0.0'
    
