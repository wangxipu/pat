#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int np, ng;
    scanf("%d %d" , &np, &ng);
    vector<int> mice(np);
    vector<int> r(np);
    for (int i = 0; i < np; i ++)
    {
        scanf("%d", &mice[i]);
    }
    
    queue<int> order;
    for (int j = 0; j < np; j ++)
    {
        int x;
        scanf("%d", &x);
        order.push(x);
    }
    
    while (order.size() != 1)
    {
        int gamecount = order.size() / ng + (order.size() % ng == 0 ? 0 : 1); 
        int curank = gamecount + 1;
        queue<int> tmp;
        for (int i = 0; i < gamecount; i++)
        {
            int max = -1;
            int maxindex = -1;
            for (int j = i*ng; j < i*ng + ng && order.size() != 0; j++)
            {
                int index = order.front();
                order.pop();
                if (mice[index]>max)
                {
                    max = mice[index];
                    if (maxindex != -1)
                    {
                        r[maxindex] = curank;
                    }
                    maxindex = index;
                }
                else
                {
                    r[index] = curank;
                }
            }
            tmp.push(maxindex);
        }
        order = tmp;
    }
    r[order.front()] = 1;
    cout << r[0];
    for (int i = 1; i < np; i++)
    {
        cout << " " << r[i];
    }
    cout << endl;
    return 0;
}

