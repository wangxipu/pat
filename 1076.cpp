#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 1005  
bool flag[MAX];
struct Node
{
    int num;
    int level;
};

queue<Node> q;

int bfs(const vector<vector<int> >& followed, int k, int level)
{
    for(; !q.empty();) q.pop();  
    Node node;
    node.num = k;
    node.level = 0;
    q.push(node);
    memset(flag, false, sizeof(flag));
    flag[k] = true;
    int count = 0;
    for (; !q.empty(); )
    {
        Node top = q.front();
        q.pop();
        size_t sz = followed[top.num].size();
        for (int i = 0; i < sz; i ++)
        {
            int t = followed[top.num][i];
            node.num = t;
            node.level = top.level + 1;
            if (!flag[t] && node.level <= level)
            {
                q.push(node);
                flag[t] = true;
                count ++;
            }
            
        }
    }
    

    return count;
}

int main()
{
    int n, level;
    scanf("%d %d", &n, &level);
    vector<vector<int> > followed(n);
    for (int i = 0; i < n; i++)
    {
        int f;
        scanf("%d", &f);
        for (int j = 0; j < f; j ++)
        {
            int x;
            scanf("%d", &x);
            x --;
            followed[x].push_back(i);
        }
        flag[i] = false;
    }
    
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i ++)
    {
        int q;
        scanf("%d", &q);
        q --;
        printf("%d\n", bfs(followed, q, level));

    }
}
