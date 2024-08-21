#include <iostream>
using namespace std;
#define M 100

struct NODE {
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void AddTail(NODE* &head, int x) {
	NODE *p=CreateNode(x);
    if (head == NULL) head = p;
	else {
        NODE* i=head;
        while(i->pNext!=NULL){
            i=i->pNext;
        }
        i->pNext=p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }
void CreateHashTable(HASHTABLE &ht, int &numbucket)
{
    cin>>numbucket;
    for(int i = 0; i<numbucket; i++)
    {
        ht[i] = NULL;
    }
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        else
        {
            int i = HF(numbucket, x);
        AddTail(ht[i], x);
        }
    }
}
void Traverse(HASHTABLE ht, int numbucket)
{
    for(int i = 0; i<numbucket; i++)
    {
        cout<<i;
        NODE* temp = ht[i];
        while(temp!=NULL)
        {
            cout<<" --> "<<temp->key;
            temp = temp->pNext;
        }
        cout<<endl;
    }
}
int main(){
    HASHTABLE H;
    int numbucket;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    return 0;
}
