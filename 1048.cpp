#include <stdio.h>
#include <map>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    map<int, int> coins;
    for (int i = 0; i < n; i++)
    {
        int coin;
        scanf("%d", &coin);
        map<int, int>::iterator it = coins.find(coin);
        if (it == coins.end())
        {
            coins[coin] = 1;
        }
        else
        {
            it->second += 1;
        }
    }
    

    for (map<int, int>::iterator it = coins.begin();
         it != coins.end(); ++ it)
    {
        int diff = m - it->first;
        map<int, int>::iterator fd = coins.find(diff);
        if (fd != coins.end())
        {
            if (fd != it || fd->second != 1)
            {
                printf("%d %d", it->first, diff);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
