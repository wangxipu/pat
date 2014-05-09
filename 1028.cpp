#include <iostream>
#include <string>
#include <set>
using namespace std;


struct Student
{
    Student(int col, int id, const string& name, int grade)
    {
        m_col = col;
        m_id = id;
        m_name = name;
        m_grade = grade;        
    }
    Student(const Student& r)
    {
        this->m_col = r.m_col;
        this->m_id = r.m_id;
        this->m_name = r.m_name;
        this->m_grade = r.m_grade;
    }
    Student()
    {
    }
    bool operator()(Student *l, Student* r) const
    {
        if (l->m_col == 1)
        {
            return l->m_id < r->m_id;
        }
        else if (l->m_col == 2)
        {
            return (l->m_name < r->m_name) || (l->m_name == r->m_name && l->m_id < r->m_id);
        }
        else if (l->m_col == 3)
        {
            return (l->m_grade < r->m_grade) || (l->m_grade == r->m_grade && l->m_id < r->m_id);
        }
    }

    int m_col;
    int m_id;
    string m_name;
    int m_grade;
    void to_string() const  
    {
        // cout << m_id << " " << m_name << " " << m_grade <<endl;
        printf("%06d %s %d\n", m_id, m_name.c_str(), m_grade);
    }
};

int main()
{
    int n, col;
    cin >> n >> col;
    set<Student*, Student> students;
    for (int i = 0; i < n; i++)
    {
        int id;
        char name[10];
        int grade;
        // cin >> id >> name >> grade;
        scanf("%d %s %d", &id, name, &grade);
        students.insert(new Student(col, id, name, grade));
    }
    for (set<Student*, Student>::const_iterator it = students.begin();
         it != students.end(); ++ it)
    {
        (*it)->to_string();
        delete *it;
    }
    return 0;
}
