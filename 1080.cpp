#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Applicant
{
    int index;
    int ge;
    int gi;
    int final;
    int choice[6];
    int rank;
};

bool cmp(const Applicant& a, const Applicant &b)
{
    if (a.final == b.final)
    {
        return a.ge > b.ge;
    }
    else
    {
        return a.final > b.final;
    }
}

int main()
{
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);
    vector<int> school_quota(m);
    vector<int> mm[m];
    vector<Applicant> applicants(n);
    vector<int> lastRank(m);
    for (int i = 0; i < m; i ++)
    {
        scanf("%d", &school_quota[i]);
        mm[i].clear();
    }

    for (int i = 0; i < n; i ++)
    {
        applicants[i].index = i;
        scanf("%d %d", &applicants[i].ge, &applicants[i].gi);
        applicants[i].final = applicants[i].ge + applicants[i].gi;
        for (int j = 0; j < k; j ++)
        {
            scanf("%d", &applicants[i].choice[j]);
        }
    }

    sort(applicants.begin(), applicants.end(), cmp);
    if (n >= 1)
        applicants[0].rank = 0;
    for (int i = 1; i < n; i ++)
    {
        if (applicants[i].final == applicants[i - 1].final
            && applicants[i].ge == applicants[i - 1].ge)
        {
            applicants[i].rank = applicants[i - 1].rank;
        }
        else
        {
            applicants[i].rank = i;
        }
    }
    
    for (int i = 0; i < n; i ++)
    {
        int current_student_id = applicants[i].index;
        for (int j = 0; j < k; j ++)
        {
            int school_id = applicants[i].choice[j];
            if (mm[school_id].size() < school_quota[school_id])
            {
                mm[school_id].push_back(current_student_id);
                lastRank[school_id] = applicants[i].rank;
                break;
            }
            else if (mm[school_id].size() > 0)
            {
                if (applicants[i].rank == lastRank[school_id])
                {
                    mm[school_id].push_back(current_student_id);
                    break;
                }
            }
        }
    }


    for(int i = 0; i < m; i++)
    {
        if (mm[i].size() == 0)
            printf("\n");
        else
        {
            sort(mm[i].begin(), mm[i].end());
            for(int j = 0; j < mm[i].size(); j ++)
            {
                if(j == 0) printf("%d",mm[i][j]);
                else printf(" %d",mm[i][j]);
            }
            printf("\n");
        }
    }
}
