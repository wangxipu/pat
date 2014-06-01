#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

struct Person
{
    char name[9];
    int age;
    int worth;
};

bool cmp(Person *a,  Person *b)
{
    if (a->worth != b->worth)
    {
        return a->worth > b->worth;
    }
    else
    {
        if (a->age != b->age)
            return a->age < b->age;
        else
        {
            return strcmp(a->name, b->name) < 0;
        }
    }
}

void findOnes(const vector<Person*>&v, int b[], 
              int len, int num, 
              int amin, int amax)
{
    bool found = false;
    int sz = len;
    for (int i = 0; i < sz && num > 0; i ++)
    {
        if (v[b[i]]->age <= amax && v[b[i]]->age >= amin)
        {
            printf("%s %d %d\n", 
                   v[b[i]]->name, v[b[i]]->age, v[b[i]]->worth);
            found = true;
            num --;
        }
    }
    if (!found)
    {
        printf("None\n");
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<Person*> v;
    v.reserve(n);
    for (int i = 0; i < n; i ++)
    {
        Person *p = new Person;
        scanf("%s %d %d", p->name, &p->age, &p->worth);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    int len, i;
    int count[205];
    int Less100Person[20005];
    for (len = i = 0; i < n; ++i)
    {
        if (count[v[i]->age] <= 100)
        {
            Less100Person[len ++] = i;
            count[v[i]->age]++;
        }
    }

    for (int j = 0; j < k; j ++)
    {
        int num, amin, amax;
        scanf("%d %d %d", &num, &amin, &amax);
        printf("Case #%d:\n", j + 1);
        findOnes(v, Less100Person, len, num, amin, amax);
    }
    for (vector<Person*>::iterator it = v.begin(); it != v.end();
         ++ it)
    {
        delete *it;
    }
}

