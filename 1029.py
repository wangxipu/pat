#!/usr/bin/env python

if __name__ == '__main__':
    seq1 = [ int(x) for i, x in enumerate(raw_input().split()) if i > 0 ]
    seq2 = [ int(x) for i, x in enumerate(raw_input().split()) if i > 0 ]
    
    i = 0
    j = 0
    k = 0
    seq1_len = len(seq1)
    seq2_len = len(seq2)
    mid_index = (seq1_len + seq2_len - 1) / 2
    while i < seq1_len and j < seq2_len:
        if seq1[i] < seq2[j]:
            if mid_index == k:
                print seq1[i]
                import sys
                sys.exit(0)
            i += 1
        elif seq1[i] > seq2[j]:
            if mid_index == k:
                print seq2[j]
                import sys
                sys.exit(0)
            j += 1
        else: # == 
            if mid_index == k or mid_index - 1 == k:
                print seq1[i]
                import sys
                sys.exit(0)
            k += 1
            i += 1
            j += 1
        k += 1

    if i < seq1_len:
        print seq1[mid_index - seq2_len]
    if j < seq2_len:
        print seq2[mid_index - seq1_len]

