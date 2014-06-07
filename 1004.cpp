#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    vector<int> children;
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Node nodes[n + 1];
    int count[n + 1];
    for (int i = 1; i <= n; i ++)
        count[i] = -1;
    for (int i = 0; i < m; i ++)
    {
        int id, k;
        scanf("%d %d", &id, &k);
        nodes[id].children.resize(k);
        for (int j = 0; j < k; j ++)
        {
            scanf("%d", &nodes[id].children[j]);
        }
    }

    queue<int> q;
    q.push(1);
    for (int i = 1; i <= n; i ++)
    {
        if (!q.empty())
            count[i] = 0;
        queue<int> tempq;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            size_t sz = nodes[top].children.size();
            if (sz == 0)
            {
                count[i] ++;
            }
            else
            {
                for (int j = 0; j < sz; j ++)
                {
                    tempq.push(nodes[top].children[j]);
                }
            }
        }
        q = tempq;
        if (count[i] != -1 && i == 1)
            printf("%d", count[i]);
        else if (count[i] != -1)
            printf(" %d", count[i]);
    }
}
