#include <stdio.h>
#include <math.h>

bool IsPrimer(long n)
{
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) 
            return false;
    return true;
}

int main()
{
    long n;
    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1) 
        printf("%ld", n);
    else
    {
        int i,tmp = n;
        for (i = 2; i<= tmp; i++)
        {
            int k = 0;
            if (IsPrimer(i))
            {
                while (n % i == 0)
                {
                    k ++;
                    n = n / i;
                }
            }
            if (k > 1)
            {
                printf("%d^%d", i, k);
            }
            else if (k == 1) printf("%d", i);
            if( n != 1 && k >= 1) printf("*");
            else if(n == 1) break;
        }
    }
    printf("\n");
    return 0;
}

