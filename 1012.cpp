#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int c;
    int m;
    int e;
    int a;     // average
    int best;  // best rank
    char bestCourse;
};

bool compA(const Student&l, const Student& r) 
{
    return l.a > r.a;
}

bool compC(const Student&l, const Student& r) 
{
    return l.c > r.c;
}

bool compM(const Student&l, const Student& r) 
{
    return l.m > r.m;
}

bool compE(const Student&l, const Student& r) 
{
    return l.e > r.e;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Student>v;
    v.resize(n);
    
    for (int i = 0; i < n; i ++)
    {
        Student student;        
        scanf("%d%d%d%d", 
              &student.id, &student.c, 
              &student.m, &student.e);
        student.a = (student.c + student.m + student.e) / 3;
        student.best = 1000;
        student.bestCourse = '0';
        v[i] = student;
    }

    // by average
    sort(v.begin(), v.end(), compA);
    int curGrade = 1;
    int curScore = v[0].a;
    for (int i = 0; i < n; i++)
    {
        if (v[i].a < curScore)
        {
            curGrade = i + 1; 
            curScore = v[i].a;
        }
        if (v[i].best > curGrade) 
        {
            v[i].best = curGrade;
            v[i].bestCourse = 'A';
        }
    }
    
    // by c programming
    sort(v.begin(), v.end(), compC);
    curGrade = 1;
    curScore = v[0].c;
    for (int i = 0; i < n; i++)
    {
        if (v[i].c < curScore)
        {
            curGrade = i + 1; 
            curScore = v[i].c;
        }
        if (v[i].best > curGrade) 
        {
            v[i].best = curGrade;
            v[i].bestCourse = 'C';
        }
    }

    // by math
    sort(v.begin(), v.end(), compM);
    curGrade = 1;
    curScore = v[0].m;
    for (int i = 0; i < n; i++)
    {
        if (v[i].m < curScore)
        {
            curGrade = i + 1; 
            curScore = v[i].m;
        }
        if (v[i].best > curGrade) 
        {
            v[i].best = curGrade;
            v[i].bestCourse = 'M';
        }
    }

    // by English
    sort(v.begin(), v.end(), compE);
    curGrade = 1;
    curScore = v[0].e;
    for (int i = 0; i < n; i++)
    {
        if (v[i].e < curScore)
        {
            curGrade = i + 1; 
            curScore = v[i].e;
        }
        if (v[i].best > curGrade) 
        {
            v[i].best = curGrade;
            v[i].bestCourse = 'E';
        }
    }

    while (0 < m--)
    {
        int obj;
        scanf("%d", &obj);
        int i;
        for (i = 0; i < n; i ++)
        {
            if (obj == v[i].id)
            {
                printf("%d %c\n", v[i].best,
                       v[i].bestCourse);
                break;
            }
        }
        // not found
        if(i == n)
        {
            printf("N/A\n");
        }
    }
    return 0;
}
