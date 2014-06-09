#!/usr/bin/env python

class Customer:
    def __init__(self, processing_time):
        self.processing_time = processing_time
        self.start_serve_time = 0
        self.finish_serve_time = 0
        
if __name__ == '__main__':
    N, M, K, Q = [ int(x) for x in raw_input().split() ]
    customers = [ Customer(int(i)) for i in raw_input().split() ]        
    queries = [ int(x) for x in raw_input().split() ]    
    windows = [ [0] for x in xrange(N) ]
    
    candidate_count = N * M
    for i in xrange(K):
        c = customers[i]
        win_obj = 0
        if i < candidate_count:
            win_obj = i % N
        else:
            # find the shortest window
            li = [ windows[j][1] for j in xrange(N) ]
            win_obj = li.index(min(li))
        tmp = windows[win_obj][-1]
        # the start_time of new one is the end_time of the last one
        windows[win_obj].append(c.processing_time + tmp)
        c.start_serve_time = tmp
        c.finish_serve_time = windows[win_obj][-1]
        if i >= candidate_count:
            windows[win_obj].pop(1)
                
    opening_time = 8 * 60
    expire_time = 17 * 60 - opening_time
    for x in queries:
        s = customers[x - 1].start_serve_time
        e = customers[x - 1].finish_serve_time
        if s >= expire_time:
            print 'Sorry'
        else:
            e = e + opening_time
            h = e / 60
            m = e % 60
            print '%02d:%02d' % (h, m)
