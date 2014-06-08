#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 0; i < K; ++i)
    {
        stack<int> s;
        bool flag = true;
        int cur = 1;
        for (int j = 0; j < N; ++j)
        {
            int num;
            scanf("%d", &num);
            if (flag)
            {
                while(s.empty() || s.top() != num)
                {
                    s.push(cur);
                    if (s.size() > M)
                    {
                        flag = false;
                        break;
                    }
                    cur++;
                }
                if (flag && s.size() >= 1 && s.top() == num)
                    s.pop();
            }
        }
        if (flag)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
