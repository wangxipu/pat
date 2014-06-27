#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    char name[11];
    char id[11];
    int score;
    bool operator()(const Student& lhs, const Student& rhs) const 
    {
        return lhs.score > rhs.score;
    }
};

int main()
{
    int count;
    scanf("%d", &count);
    
    vector<Student> records;
    records.resize(count);
    for (int i = 0; i < count; i ++)
    {
        scanf("%s %s %d", records[i].name, 
              records[i].id, &records[i].score);
    }
    
    int min_score, max_score;
    scanf("%d %d", &min_score, &max_score);
    
    sort(records.begin(), records.end(), Student());
    bool None = true;
    for (int i = 0; i < count; i ++)
    {
        if (records[i].score >= min_score && records[i].score <= max_score)
        {
            printf("%s %s\n", records[i].name, records[i].id);
            None = false;
        }
    }

    if (None)
    {
        printf("NONE\n");
    }
    return 0;
}
