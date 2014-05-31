#include <cstdio>
#include <algorithm>

const int N = 10001;
const int K = 5;

typedef struct
{
    int no;
    int score;
    bool ispassed;
    int problems[K];
    int perfect;
    int rank;
} student;

bool cmp(const student &a, const student &b)
{
    if (a.ispassed == b.ispassed)
    {
        if (a.ispassed)
        {
            if (a.score != b.score)
            {
                return a.score > b.score;
            }
            if (a.perfect != b.perfect)
            {
                return a.perfect > b.perfect;
            }
            else
            {
                return a.no < b.no;
            }
        }
        else
        {
            return a.no < b.no;
        }
    }
    else
    {
        if (a.ispassed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    student pat[N];
    int per[K];
    int n, k, m;

    scanf("%d %d %d", &n, &k, &m);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            pat[i].problems[j] = -2;
        }
        pat[i].score = 0;
        pat[i].ispassed = false;
        pat[i].perfect = 0;
        pat[i].no = i;
    }

    for (int i = 0; i < k; ++i)
    {
        scanf("%d", per+i);
    }

    // read the submit list
    while(m --)
    {
        int j, i, l;
        scanf("%d %d %d", &j, &i, &l);
        if (l > pat[j].problems[i-1])
        {
            pat[j].problems[i-1] = l;
        }
    }

    // cal the total score
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (pat[i].problems[j] >= 0)
            {
                pat[i].ispassed = true;
                pat[i].score += pat[i].problems[j];
                if (pat[i].problems[j] == per[j])
                    ++pat[i].perfect;
            }
        }
    }

    // sort
    std::sort(pat+1, pat+n+1, cmp);

    for (int i = 1; i <= n && pat[i].ispassed; ++i)
    {
        if (i == 1)
        {
            pat[i].rank = 1;
        }
        else
        {
            if (pat[i].score == pat[i-1].score)
            {
                pat[i].rank = pat[i-1].rank;
            }
            else
            {
                pat[i].rank = i;
            }
        }
        printf("%d %05d %d", pat[i].rank, pat[i].no, pat[i].score);
        for (int j = 0; j < k; ++j)
        {
            if (pat[i].problems[j] == -1)
            {
                printf(" 0");
            }
            else if (pat[i].problems[j] == -2)
            {
                printf(" -");
            }
            else
            {
                printf(" %d", pat[i].problems[j]);
            }
        }
        printf("\n");
    }

    return 0;
}



