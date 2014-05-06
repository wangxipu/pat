#include <iostream>
using namespace std;

int main()
{
    int addr_start1, addr_start2, addr, n, next;
    char ch;
    int node_map[100000];
    int mark_map[100000];
    
    cin >> addr_start1 >> addr_start2 >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> addr >> ch >> next;
        node_map[addr] = next;
    }

    while (addr_start1 != -1)
    {
        mark_map[addr_start1] = 1;
        addr_start1 = node_map[addr_start1];
    }

    while (addr_start2 != -1)
    {
        if (mark_map[addr_start2] == 1)
        {
            cout.width(5);
            cout.fill('0');
            cout.setf(ios::right);
            cout << addr_start2 << endl;
            return 0;
        }
        addr_start2 = node_map[addr_start2];
    }
    cout << -1 << endl;

    return 0;
}
