#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <memory>
using namespace std;

int weight[101] = {0};
int parent[101] = {0};
int childNum[101] = {0};
int sum[101] = {0};
int linkNode[101][101] = {0};

void print(int pa)
{
    stack<int> st;
    while (pa != -1)
    {
        st.push(weight[pa]);
        pa = parent[pa];
    }
    cout<<st.top();
    st.pop();
    while (!st.empty())
    {
        cout<<' '<<st.top();
        st.pop();
    }
    cout<<endl;
}

void DFS(int cur, int s)
{
    int next;
    for(int i = 0; i < childNum[cur]; i++)
    {
        next = linkNode[cur][i];
        sum[next] = sum[cur] + weight[next];
        if(sum[next] == s)
        {
            if(childNum[next] == 0)
            {
                print(next);
            }
            else
            {
                continue;
            }
        }else if(sum[next] < s)
        {
            DFS(next,s);
        }else{
            continue;
        }

    }
}

bool cmp(const int& aa, const int& bb)
{
    return weight[aa] > weight[bb];
}

int main()
{
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    int i,j;
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    int nonleaf, num, leaf;
    parent[0] = -1;
    for(i = 0; i < m;i++)
    {
        scanf("%d %d", &nonleaf, &num);
        childNum[nonleaf] = num;
        for(j = 0; j < num; j++)
        {
            scanf("%d", &leaf);
            linkNode[nonleaf][j] = leaf;
            parent[leaf] = nonleaf;
        }
        sort(linkNode[nonleaf], linkNode[nonleaf] + num, cmp);
    }
    if(m == 0)
    {
        if(weight[0] == s)
            cout<<weight[0]<<endl;
        return 0;
    }
    memcpy(sum, weight, n * sizeof(int));
    DFS(0,s);    
    return 0;
}
