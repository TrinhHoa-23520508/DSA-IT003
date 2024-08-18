#include<iostream>
using namespace std;
struct TNODE
{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;
TNODE* CreateTNode(int x)
{
    TNODE* p;
    p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
int Insert_TREE_recursion(TREE &T, int x)
{
    if(T)
    {
        if(T->key==x) return 0;
        if(T->key<x) return Insert_TREE_recursion(T->pRight, x);
        else return Insert_TREE_recursion(T->pLeft, x);
    }
    T = CreateTNode(x);
    return 1;
}
int Insert_TREE(TREE &T, int x)
{
    if(T==NULL) T = CreateTNode(x);
    TREE temp = T;
    while(temp){
        if(temp->key==x) return 0;
        if(temp->key<x)
        {
            if(temp->pRight==NULL) temp->pRight = CreateTNode(x);
            else temp = temp->pRight;
        }
        else
        {
            if(temp->pLeft==NULL) temp->pLeft = CreateTNode(x);
            else temp = temp->pLeft;
        }
    }
    return 1;
}
void CreateTree(TREE& T)
{
    cout<<"Nhap vao so not n = ";
    int n, x;
    cin>>n;
    while(n-->0)
    {
        cin>>x;
        Insert_TREE_recursion(T, x);
    }
}
void inorder(TREE T)
{
    if(T)
    {
        inorder(T->pLeft);
        cout<<T->key<<" ";
        inorder(T->pRight);
    }
}
void preorder(TREE T)
{
    if(T)
    {
        cout<<T->key<<" ";
        preorder(T->pLeft);
        preorder(T->pRight);
    }
}
void postorder(TREE T)
{
    if(T)
    {
        postorder(T->pLeft);
        postorder(T->pRight);
        cout<<T->key<<" ";
    }
}
TNODE* Search(TREE T, int x)
{
    if(T)
    {
        if(T->key==x) return T;
        if(T->key<x) return Search(T->pRight, x);
        else return Search(T->pLeft, x);
    }
    return NULL;
}
void ThayThe(TNODE* p, TNODE* T)
{
    if(T->pRight!=NULL)
    {
        ThayThe(p, T->pRight);
    }
    p->key = T->key;
    p = T;
    T = T->pLeft;

}
void DeleteTNode(TREE &T, int x)
{
    if(T!=NULL){
        if(T->key<x) DeleteTNode(T->pRight, x);
        else
        {
            if(T->key>x) DeleteTNode(T->pLeft, x);
            else
            {
                TREE p = T;
                if(T->pLeft==NULL) T = T->pRight;
                else
                {
                    if(T->pRight==NULL) T = T->pLeft;
                    else ThayThe(p, T->pLeft);
                }
                delete p;
            }
        }
    }
}
int Height(TNODE* T)
{
    if(T==NULL) return -1;
    else
    {
        return max(Height(T->pLeft), Height(T->pRight))+1;

    }

}

int main()
{


}
