#include <cstdio>
#define MAX 100005

typedef struct Node
{
    double price;
    int parent;
    int amount;
}Node;

int main(int argc,char *argv[])
{
    int n;
    double p, r;
    Node N[MAX];
    int i, j;
    double ans = 0;
    scanf("%d%lf%lf", &n, &p, &r);
    r = r / 100.0;
    N[0].price = p;
    for (i = 0; i < n; i ++)
    {
        int num;
        scanf("%d", &num);
        N[i].amount = 0;
        if (num == 0)
            scanf("%d", &N[i].amount);
        else
        {
            for (j = 0; j < num; j ++)
            {
                int index;
                scanf("%d", &index);
                N[index].parent = i;
                if (N[i].price != 0)
                    N[index].price = N[i].price * (1 + r);
            }
        }
    }

    // re-compute the price according to its parent
    for (i = 0;i < n; i ++)
    {
        if (N[i].price == 0)
            N[i].price = N[N[i].parent].price * (1 + r);
        if (N[i].amount != 0)
            ans += N[i].price * N[i].amount;
    }
    printf("%.1lf\n",ans);
    
    return 0;
}
