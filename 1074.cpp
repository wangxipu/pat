#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int node[100002][2];

int main()
{
    int list[100002];
    int i;
    int st, k;
    int n;
    cin >> st >> n >> k;
    for (i = 0; i<n; i++)
    {
        int add, data, next;
        cin >> add >> data >> next;
        node[add][0] = data;
        node[add][1] = next;
    }
    int cnt = 0;
    int cur = st;
    //  this list keeps the order
    while (cur != -1)
    {
        list[cnt++] = cur;
        cur = node[cur][1];
    }
    
    i = 0;
    // sublist
    while (i + k <= cnt)
    {
        reverse(list + i, list + i + k);
        i += k;
    }
    for (i = 0; i < cnt - 1; i++)
    {
        printf("%05d %d %05d\n", list[i], node[list[i]][0], list[i+1]);
    }
    printf("%05d %d -1\n", list[i], node[list[i]][0]);
    return 0;
}
