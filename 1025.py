#!/usr/bin/env python

def Append(a, x):
    a.append(x)
    a.sort(key = lambda x:x[0])
    a.sort(key = lambda x:x[2],reverse = True)
if __name__ == '__main__':
    # reg, location_seq, score, local_rank, final_rank
    final_list = []
    locations = int(raw_input())
    for i in xrange(locations):
        testees = int(raw_input())
        local_list = []
        for j in xrange(testees):
            test_list = raw_input().split()
            l = [test_list[0], i, int(test_list[1]), 0, 0]
#            local_list.append(l)
            Append(local_list, l)
        #local_list.sort(key = lambda x:x[0])
        #local_list.sort(key = lambda x:x[2],reverse = True)
        now_score = -1
        now_rank = -1
        for t in xrange(0, len(local_list)):
            if local_list[t][2] == now_score:
                local_list[t][3] = now_rank
            else:
                now_score = local_list[t][2]
                now_rank = t
                local_list[t][3] = t
        final_list.extend(local_list)
   
    final_list.sort(key = lambda x:x[0])
    final_list.sort(key = lambda x:x[2],reverse = True)
    now_score = -1
    now_rank = -1
    for t in xrange(0, len(final_list)):
        if final_list[t][2] == now_score:
            final_list[t][4] = now_rank
        else:
            now_score = final_list[t][2]
            now_rank = t
            final_list[t][4] = t

    print len(final_list)
    for (reg, location_seq, score, local_rank, final_rank) in final_list:
        print "%s %d %d %d" % (reg, final_rank + 1, location_seq + 1, local_rank + 1)
