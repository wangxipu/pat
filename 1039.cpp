#include <stdio.h>
#include <vector>
using namespace std;

int my_hash(char *name)
{
    return (name[0] - 'A') * 26 * 26 * 10 + 
        (name[1] - 'A') * 26 * 10 + 
        (name[2] - 'A') * 10 + (name[3] - '0');
}

int main()
{
    int student_count, course_count;
    vector<int> name2course[26*26*26*10];
    scanf("%d%d", &student_count, &course_count);
    vector<vector<char*> > courses_list(course_count + 1);

    for (int i = 0; i < course_count; i ++)
    {
        int course_index, student_this_course;
        scanf("%d%d", &course_index, &student_this_course);
        courses_list[course_index].resize(student_this_course);
        for (int j = 0; j < student_this_course; j ++)
        {
            char *name = new char[5];
            scanf("%s", name);
            courses_list[course_index][j] = name;
        }
    }

    for (int i = 1; i <= course_count; i ++)
    {
        for (int j = 0; j < courses_list[i].size(); j ++)
        {
            char *name = courses_list[i][j];
            int index = my_hash(name);
            name2course[index].push_back(i);
        }
    }

    // sort these course index
    for (int i = 0; i < student_count; ++i)
    {
        char name[5];
        scanf("%s",name);
        printf("%s", name);
        int index = my_hash(name);
        size_t name2course_index_size = name2course[index].size();
        printf(" %d", name2course_index_size);
        for (int j = 0; j < name2course_index_size; ++j)
        {
            printf(" %d", name2course[index][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < courses_list.size(); i ++)
    {
        for (int j = 0; j < courses_list[i].size(); j ++)
        {
            delete []courses_list[i][j];
        }
    }
    return 0;
}
