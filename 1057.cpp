#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

struct BinTree
{
    static const int MAXN = 100010;
    vector<int> a;

    BinTree()
    {
        a = vector<int>(MAXN,0);
    }

    int lowbit(int t)
    {
        return t&(-t);
    }

    void update(int t, int d)
    {
        while (t <= MAXN)
        {
            a[t] += d;
            t += lowbit(t);
        }
    }

    int getsum(int t)
    {
        int sum(0);
        while (t > 0)
        {
            sum += a[t];
            t -= lowbit(t);
        }
        return sum;
    }
    int find(int val, int l = 0, int h = MAXN - 1)
    {
        if (l == h)
            return l;
        int mid = (l + h) / 2;
        if (getsum(mid) < val)
        {
            return find(val, mid + 1, h);
        }
        else
        {
            return find(val, l, mid);
        }
    }
};

BinTree tree;
int main()
{
    int N(0);
    scanf("%d",&N);
    char str[20];
    int n(0);
    stack<int> stk;
    while (N--)
    {
        scanf("%s", &str);
        switch (str[1])
        {
        case 'o':
            if (stk.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                n = stk.top();
                printf("%d\n", n);
                stk.pop();
                tree.update(n, -1);
            }
            break;
        case 'u':
            scanf("%d", &n);
            stk.push(n);
            tree.update(n, 1);
            break;
        case 'e':
            if (stk.empty())
                printf("Invalid\n");
            else
            {
                printf("%d\n", tree.find((stk.size() + 1) / 2));
            }
            break;
        }
    }
    return 0;
}
