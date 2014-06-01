#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int dp[10005][105] = {0};
    bool flag[10005][105] = {0};
    int *coins = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &coins[i]);
    }
    
    sort(coins + 1, coins + 1 + n, greater<int>());
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (j < coins[i] 
                || dp[i - 1][j - coins[i]] + coins[i] < dp[i - 1][j])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j - coins[i]] + coins[i];
                flag[i][j] = true;
            }
        }
    }
    
    if (dp[n][m] != m)
        printf("No Solution");
    else
    {
        bool first = true;
        for (int i = n; i >= 1 && m > 0; i --)
        {
            if (flag[i][m])
            {
                if (first)
                {
                    printf("%d", coins[i]);
                    first = false;
                }
                else
                    printf(" %d", coins[i]);
                m -= coins[i];
            }
        }
    }
    printf("\n");
    delete []coins;
}
