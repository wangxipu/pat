#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Cake
{
    double amount;
    double price;
    double profit;
    bool operator()(const Cake& a, const Cake& b) const
    {
        return a.price > b.price;
    }
};

int main()
{
    int n, demand;
    scanf("%d%d", &n, &demand);
    vector<Cake> v;
    v.resize(n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%lf", &v[i].amount);
    }
    for (int i = 0; i < n; i ++)
    {
        scanf("%lf", &v[i].profit);
        if (v[i].amount > 0)
            v[i].price = v[i].profit / v[i].amount;
        else
            v[i].price = 0;
    }
    sort(v.begin(), v.end(), Cake());
    double left_demand = demand;
    double profit = 0;
    for (int i = 0; i < n && left_demand > 0; i ++)
    {
        if (left_demand >= v[i].amount)
        {
            profit += v[i].profit;
            left_demand -= v[i].amount;
        }
        else
        {
            profit += v[i].price * left_demand;
            left_demand = 0;
        }
    }
    printf("%.2f", profit);
    return 0;
}
