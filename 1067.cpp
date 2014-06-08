#include <stdio.h>

int findNotOK(int* arr,int begin,int end)
{
    for(int i = begin; i < end; i++)
    {
        if(arr[i] != i)
            return i;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = new int[n];
    int i,t;
    
    for( i = 0; i < n; i++)
    {
        scanf("%d",&t);
        arr[t] = i;
    }
    int tmp = 0;
    int count = 0;
    int firstPos = 1;
    firstPos = findNotOK(arr,firstPos,n);

    while(firstPos)
    {
        if(arr[0] == 0)
        {
            arr[0] = arr[firstPos];
            arr[firstPos] = 0;
            count ++;
        }

        while(arr[0] != 0)
        {
            tmp = arr[0];
            arr[0] = arr[tmp];
            arr[tmp] = tmp;
            count++;
        }
        firstPos = findNotOK(arr,firstPos,n);
    }
    delete []arr;
    printf("%d\n", count);

    return 0;
}
