#include <string>
#include <iostream>
#include <set>
using namespace std;

int main()
{
    string a, b;  
    getline(cin, a);    
    getline(cin, b);    
    size_t len_a = a.size();
    size_t len_b = b.size();
    set<char> b_set;
    for (int i = 0; i < len_b; i ++)
    {
        b_set.insert(b[i]);
    }
    for (int j = 0; j < len_a; j ++)
    {
        if (b_set.find(a[j]) == b_set.end())
        {
            printf("%c", a[j]);
        }
    }
}
