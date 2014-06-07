#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(Node* _l = NULL,Node* _r = NULL,int k = -1)
        :key(k),left(_l),right(_r)
    {}
};

void InsertTree(Node* &tree,int key)
{
    Node **p = &tree; 
    while((*p) != NULL)
    {
        if(key < (*p)->key)
            p = &(*p)->left;
        else
            p = &(*p)->right;
    }
    (*p) = new Node;
    (*p)->key = key;
}

// pre-order
void TravelRootLR(Node* tree, std::vector<int>& v)  
{  
    if(tree == NULL) return;  
    v.push_back(tree->key);  
    TravelRootLR(tree->left, v);  
    TravelRootLR(tree->right, v);  
}  

void TravelRootRL(Node* tree, std::vector<int>& v)  
{  
    if(tree == NULL) return;  
    v.push_back(tree->key);  
    TravelRootRL(tree->right, v);  
    TravelRootRL(tree->left, v);  
}  

// post-order
void TravelLRRoot(Node* tree, std::vector<int>& v)  
{  
    if(tree == NULL) return;  
    TravelLRRoot(tree->left, v);  
    TravelLRRoot(tree->right, v);  
    v.push_back(tree->key);  
}  

void TravelRLRoot(Node* tree, std::vector<int>& v)  
{  
    if(tree == NULL) return;  
    TravelRLRoot(tree->right, v);  
    TravelRLRoot(tree->left, v);  
    v.push_back(tree->key);  
}  

void ReleaseTree(Node* tree)  
{  
    std::queue<Node*> q;  
    q.push(tree);  
    while(!q.empty())  
    {  
        Node* p = q.front();  
        q.pop();  
        if(p)  
        {  
            q.push(p->left);  
            q.push(p->right);  
            delete p;  
        }  
    }  
}

int main()  
{  
    int n;  
    while(scanf("%d", &n) != EOF)  
    {  
        std::vector<int> inputVec(n);  
        for(int i = 0; i < n; ++i)  
            scanf("%d",&inputVec[i]);  
   
        Node* tree = NULL;  
        for(int i = 0; i < n; ++i)  
            InsertTree(tree, inputVec[i]);
   
        std::vector<int> t1, t2, t3;  
        TravelRootLR(tree, t1);  
        TravelRootRL(tree, t2);  
          
        if(inputVec == t1)
        {  
            printf("YES\n");  
            TravelLRRoot(tree, t3);  
            int size = (int)t3.size();  
            for(int i = 0; i < size-1; ++i)  
                printf("%d ", t3[i]);  
            printf("%d\n", t3[size-1]);  
        }  
        else if(inputVec == t2)
  
        {  
            printf("YES\n");  
            TravelRLRoot(tree, t3);  
            int size = (int)t3.size();  
            for(int i = 0; i < size-1; ++i)  
                printf("%d ", t3[i]);  
            printf("%d\n", t3[size-1]);  
        }  
        else   
        {  
            printf("NO\n");  
        }  
        ReleaseTree(tree);  
    }  
    return 0;  
}  
