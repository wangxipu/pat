#include <stdio.h>

int main()
{
    int seq1_len, seq2_len;
    scanf("%d", &seq1_len);
    int seq1[1000001], seq2[1000001];
    int i, j, k;
    for (i = 0; i < seq1_len; i ++)
    {
        scanf("%d", &seq1[i]);
    }
    scanf("%d", &seq2_len);
    for (i = 0; i < seq2_len; i ++)
    {
        scanf("%d", &seq2[i]);
    }
    i = j = k = 0;
    int mid_index = (seq1_len + seq2_len - 1) / 2;
    while (i < seq1_len && j < seq2_len)
    {
        if (seq1[i] < seq2[j])
        {
            if (mid_index == k)
            {
                printf("%d\n", seq1[i]);
                return 0;
            }
            i ++;
        }
        else if (seq1[i] > seq2[j])
        {
            if (mid_index == k)
            {
                printf("%d\n", seq2[j]);
                return 0;
            }
            j ++;
        }        
        else
        {
            if (mid_index == k || mid_index - 1 == k)
            {
                printf("%d\n", seq1[i]); 
                return 0;
            }
            k ++;
            i ++;
            j ++;
        }
        k ++;
    }
    if (i < seq1_len)
    {
        printf("%d\n", seq1[mid_index - seq2_len]);
    }
    else
    {
        printf("%d\n", seq2[mid_index - seq1_len]);
    }

    return 0;
}
