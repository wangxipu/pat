#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 30;

struct Node
{
    Node* left;
    Node* right;
    int data;
};
int postOrder[N];
int inOrder[N];


void createTree(int b1,int e1,int b2,int e2,Node* &curNode)
{
    if(b1<0 || b2<0 || b1>e1 || b2>e2) 
        return;
    if(NULL == curNode)
        curNode = new Node();
    curNode->left = NULL;
    curNode->right = NULL;
    curNode->data = postOrder[e1];
    int i = 0,j=0;
    
    for(i = e2,j = e1; i >= b2; i--,j--)
        if(inOrder[i] == postOrder[e1])
            break;
    createTree(b1,j-1,b2,i-1,curNode->left);
    createTree(j,e1-1,i+1,e2,curNode->right);
}


void levelOrder(Node* root)
{
    if(NULL == root)
        return;
    queue<Node*> Q;
    Q.push(root);
    bool isFirst = true;
    while(!Q.empty() )
    {
        Node *tmp = Q.front();
        Q.pop();
        if(NULL == tmp)
            return;
        if(isFirst) 
        {
            cout<<tmp->data;
            isFirst = false;
        }
        else
            cout<<" "<<tmp->data;

        if(tmp->left)
            Q.push(tmp->left);
        if(tmp->right)
            Q.push(tmp->right);
        
        delete tmp;        
    }
    cout<<endl;
}

int main()
{
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>postOrder[i];
    for(i=0; i<n; i++)
        cin>>inOrder[i];
    Node *root = NULL;
    createTree(0,n-1,0,n-1,root);
    levelOrder(root);
    return 0;
}
