#include <stdio.h>  
#define N 100001  
#define M 100000001  
  
int main()  
{  
    int n, m, i, j;  
    int a[N];  
    int sum, tmp, cnt, jmp;  
    int b[N][2];  
  
    if (scanf("%d%d", &n, &m) != EOF)  
    {  
        for (i = 1; i <= n; i++)  
        {  
            scanf("%d", &a[i]);  
        }  
  
        sum = M;  
        cnt = 0;  
        jmp = 0;  
        for (i = 1; i <= n; i++)  
        {  
            tmp = 0;  
            for (j = i + jmp; j <= n; j++)  
            {  
                tmp += a[j];  
                if (tmp >= m)  
                {  
                    if (tmp < sum)  
                    {  
                        cnt = 0;  
                        sum = tmp;  
                        b[cnt][0] = i;  
                        b[cnt][1] = j;  
                        cnt++;  
                    }  
                    else if (tmp == sum)  
                    {  
                        b[cnt][0] = i;  
                        b[cnt][1] = j;  
                        cnt++;  
                    }  
  
                    if (tmp == m && j - i > 1)  
                    {  
                        jmp = j - i - 1;  
                    }  
                    else   
                    {  
                        jmp = 0;  
                    }  
                    break;  
                }  
            }  
  
            if (tmp == m && j == n)  
                break;  
        }  
  
        for (i = 0; i < cnt-1; i++)  
        {  
            printf("%d-%d\n", b[i][0], b[i][1]);  
        }  
        printf("%d-%d", b[i][0], b[i][1]);  
    }  
  
    return 0;  
}  
