#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <set>
#include <string.h>
using namespace std;

const int NUM=10005;
int isVisit[NUM];
int parent[NUM];
vector<int> map[NUM];
int dis[NUM];

int bfs(int x)
{
    queue<int> q;
    memset(isVisit,0,sizeof(isVisit));
    isVisit[x]=1;
    int maxv=0;
    q.push(x);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        int i;
        if(dis[v]>maxv)
            maxv=dis[v];
        for(i=0;i<map[v].size();++i)
            if(!isVisit[map[v][i]]){
                isVisit[map[v][i]]=1;
                dis[map[v][i]]=dis[v]+1;
                q.push(map[v][i]);
            }
    }
    return maxv;
}

int find(int x)
{
    int r=x;
    while(parent[r]!=r){
        r=parent[r];
    }
    return r;
}

void merge(int a, int b)
{
    int x=find(a);
    int y=find(b);
    if(x!=y)
        parent[y]=x;
}

int main()
{
    int a, b, i, sum;
    int n;
    cin>>n;
    for(i=1;i<=n;i++)
        parent[i]=i;
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
        merge(a,b);
    }
    

    sum=0;
    for( i = 1; i <= n; i++)
    {
        // same group
        if(parent[i] == i)
            sum++;
    }

    if(sum>1)
    {
        cout<<"Error: " << sum << " components" << endl;
    } 
    else 
    {
        set<int> ans;
        int maxv = bfs(1);
        int first_ans = -1;
        for (i = 1; i <= n; ++i)
        {
            if (dis[i] == maxv)
            {
                if (first_ans == -1)
                {
                    first_ans = i;
                }
                ans.insert(i);
            }
        }
        maxv = bfs(first_ans);
        for (i = 1; i <= n; ++i)
        {
            if (dis[i] == maxv)
                ans.insert(i);
        }

        for(set<int>::iterator it = ans.begin(); 
            it != ans.end(); ++ it)
            cout << *it << endl;

    }
    return 0;
}
