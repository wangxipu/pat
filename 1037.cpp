#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int nc, np;
    scanf("%d", &nc);
    vector<int> coupons(nc);
    for (int i = 0; i < nc; i ++)
    {
        scanf("%d", &coupons[i]);
    }
    sort(coupons.begin(), coupons.end(), greater<int>());
    scanf("%d", &np);
    vector<int> products(np);
    for (int i = 0; i < np; i ++)
    {
        scanf("%d", &products[i]);
    }
    sort(products.begin(), products.end(), greater<int>());
    
    int n = min(nc, np);
    int sum = 0;
    int i, j;
    for (i = 0, j = 0; i < nc && j < np; i ++, j ++)
    {
        if (coupons[i] > 0 && products[j] > 0)
            sum += coupons[i] * products[j];
        else
            break;
    }
    for (i = nc -1, j = np - 1; i >= 0 && j >= 0; i --, j--)
    {
        if (coupons[i] < 0 && products[j] < 0)
        {
            sum += coupons[i] * products[j];     
        }
        else
            break;
    }
    printf("%d", sum);
}
