#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const char *a, const char*b)
{
    return strcmp(a, b) < 0;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<char*> > course_list;
    vector<char*>gc;
    gc.resize(n);
    course_list.resize(k);
    for (int i = 0; i < n; i ++)
    {
        char *name = new char[5];
        int course;
        scanf("%s%d", name, &course);
        gc[i] = name;
        for (int j = 0; j < course; j ++)
        {
            int index;
            scanf("%d", &index);
            course_list[index - 1].push_back(name);
        }
    }
    for (vector<vector<char* > >::iterator it = course_list.begin();
         it != course_list.end(); ++ it)
    {
        size_t sz = (*it).size();
        vector<char*> &member = *it;
        sort(member.begin(), member.end(), cmp);
        printf("%d %d\n", 1 + it - course_list.begin(), sz);
        for (vector<char*>::iterator it1 = member.begin(); 
             it1 != member.end(); ++it1)
        {
            printf("%s\n", (*it1));
        }
    }
    
    for (vector<char*>::iterator it = gc.begin();
         it != gc.end(); ++ it)
    {
        delete [](*it);
    }
    return 0;
}
