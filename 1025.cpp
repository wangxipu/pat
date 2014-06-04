#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct Testee
{
public:
    char reg[14];
    int location_req;
    int score;
    int local_rank;
    int final_rank;
};

bool cmp(const Testee& a, const Testee& b)
{
    if (a.score != b.score)
    {
        return a.score > b.score;
    }
    else
    {
        return strcmp(a.reg, b.reg) < 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Testee> all;
    for (int i = 0; i < n; i ++)
    {
        int m;
        scanf("%d", &m);
        vector<Testee> v(m);
        for (int j = 0; j < m; j ++)
        {
            scanf("%s %d", v[j].reg, &v[j].score);
            v[j].location_req = i + 1;
        }
        sort(v.begin(), v.end(), cmp);
        v[0].local_rank = 1;
        size_t sz = v.size();
        for (size_t k = 1; k < sz; k ++)
        {
            if (v[k].score == v[k - 1].score)
                v[k].local_rank = v[k - 1].local_rank;
            else
            {
                v[k].local_rank = k + 1;
            }
        }
        all.insert(all.end(), v.begin(), v.end());
    }
    
    sort(all.begin(), all.end(), cmp);
    size_t sz = all.size();
    printf("%zd\n", sz);
    all[0].final_rank = 1;
    printf("%s %d %d %d\n", all[0].reg, all[0].final_rank, 
           all[0].location_req, all[0].local_rank);
    for (size_t i = 1; i < sz; i ++)
    {
        if (all[i].score == all[i - 1].score)
        {
            all[i].final_rank = all[i - 1].final_rank;
        }
        else
        {
            all[i].final_rank = i + 1;
        }
        printf("%s %d %d %d\n", all[i].reg, all[i].final_rank,      
               all[i].location_req, all[i].local_rank);

    }
    return 0;
}
