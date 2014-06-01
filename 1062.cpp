#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int LL, HH;
struct Person
{
    int id;
    int talent;
    int virtue;
    int total;
    
    bool sage() const
    {
        return talent >= HH && virtue >= HH;
    }
    bool nobleman() const
    {
        return talent < HH && virtue >= HH;
    }
    bool foolman() const
    {
        return talent < HH && virtue < HH && virtue >= talent;
    }
    bool other() const
    {
        return talent < HH && virtue < HH && virtue < talent;
    }
};

bool commonCmp(const Person& a, const Person& b)
{
    if (a.total == b.total)
    {
        if (a.virtue != b.virtue)
        {
            return a.virtue > b.virtue;
        }
        else
        {
            return a.id < b.id;
        }
    }
    else
    {
        return a.total > b.total;
    }
}    

bool cmp(const Person& a, const Person& b)
{
    if (a.sage() && b.sage())
    {
        return commonCmp(a, b);
    }
    else if (a.sage() || b.sage())
    {
        return a.sage() > b.sage();
    }
    if (a.nobleman() && b.nobleman())
    {
        return commonCmp(a, b); 
    }
    else if (a.nobleman() || b.nobleman())
    {
        return a.nobleman() > b.nobleman();
    }
    if (a.foolman() && b.foolman())
    {
        return commonCmp(a, b); 
    }
    else if (a.foolman() || b.foolman())
    {
        return a.foolman() > b.foolman();
    }
    return commonCmp(a, b);
}

int main()
{
    int n, L, H;
    scanf("%d%d%d", &n, &L, &H);
    LL = L;
    HH = H;
    vector<Person> v;
    for (int i = 0; i < n; i ++)
    {
        int d, v1, t;
        scanf("%d%d%d", &d, &v1, &t);
        if (v1 < LL || t < LL)
        {
            continue;
        }
        Person p;
        p.id = d;
        p.virtue = v1;
        p.talent = t;
        p.total = v1 + t;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    
    size_t sz = v.size();
    printf("%d\n", sz);
    for (size_t i = 0; i < sz; i ++)
    {
        printf("%08d %d %d\n", v[i].id, v[i].virtue, v[i].talent);
    }
}
