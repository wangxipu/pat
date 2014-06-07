#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#define N 1001
int a[N],tree[N];
int idx;

void LRR(int i,int n)
{
    int l=2*i,r=2*i+1;
    if(i>n)
        return;
    LRR(l,n);
    tree[i]=a[idx++];
    if(r<=n)
        LRR(r,n);
}

int main()
{
    int n,tmp,i,j;
    scanf("%d",&n);
    for(j=0;j<n;j++)
        scanf("%d",&a[j]);
    sort(a,a+n);
    idx=0;
    LRR(1,n);
    for(i=1;i<n;i++)
        printf("%d ",tree[i]);
    printf("%d\n",tree[i]);
    return 0;
}
