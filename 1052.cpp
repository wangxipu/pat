#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct Node
{
    int key;
    int next;
    Node()
    {}
    Node(int addr,int k)
    {
        key = k;
        next = addr;
    }
};

int cmp(const void* A,const void* B)
{
    Node* aa = (Node*)A;
    Node* bb = (Node*)B;
    return aa->key - bb->key;
}

int main()
{
    int n;
    int head,addr;
    cin >> n >> head;
    map<int, Node> m;
    vector<Node> v;
    Node* node = new Node[n];
    int i;
    for (i = 0; i < n; i ++)
    {
        cin >> addr >> node[i].key >> node[i].next;
        m[addr] = node[i];
    }
    int findKey = head;
    while (findKey != -1)
    {
        map<int,Node>::const_iterator map_it = m.find(findKey);
        if (map_it != m.end())
        {
            Node newNode(findKey, map_it->second.key);
            v.push_back(newNode);
            findKey = map_it->second.next;
        }
        else
        {
            break;
        }
    }
    
    size_t size = v.size();
    if (size == 0)
    {
        cout <<"0 -1"<<endl;
        delete []node;
        return 0;
    }
    
    qsort(&*v.begin(), size, sizeof(Node), cmp);
    cout << size << " " << setw(5) << setfill('0') << v.begin()->next << endl;
    
    for (i = 0; i < size; i ++)
    {
        cout << setw(5) << setfill('0') << v[i].next << ' ' << v[i].key << ' ';
        if (i != size-1)
        {
            cout << setw(5) << setfill('0') << v[i+1].next << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    delete []node;
    return 0;
}
