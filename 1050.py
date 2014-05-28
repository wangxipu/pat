#!/usr/bin/env python
# TLE
import sys
if __name__ == '__main__':
    S1 = raw_input()
    S2 = raw_input()
    b_set = set(S2)
    out = []
    for x in S1:
        if x in b_set:
            continue
        else:
            out.append(x)
    print ''.join(out)
            
