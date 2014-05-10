#include <stdio.h>

void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int node_count;
    scanf("%d", &node_count);
    int nodes[node_count + 1];
    int sum = 0;
    nodes[0] = 0;
    for (int i = 1; i < node_count + 1; i++)
    {
        int d;
        scanf("%d", &d);
        nodes[i] = nodes[i - 1] + d;
        sum += d;
    }
    
    int pair_count;
    scanf("%d", &pair_count);
    for (int i = 0; i < pair_count; i ++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        if (a > b)
            swap(&a, &b);
        int total = nodes[b - 1] - nodes[a - 1];
        if (sum - total < total)
            total = sum - total;
        printf("%d\n", total);
    }        
}
