#include<iostream>
using namespace std;
struct NODE
{
	int key;
	NODE* pNext;
};
struct LIST
{
	NODE* pHead;
	NODE* pTail;
};
void CreateEmptyList(LIST& L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}
NODE* CreateNode(int x)
{
	NODE* p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST& L, NODE* p)
{
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else
	{
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void AddHead(LIST& L, NODE* p)
{
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}
void AddAfterQ(LIST& L, NODE* p, NODE* Q)
{
	if (Q)
	{
		p->pNext = Q->pNext;
		Q->pNext = p;
		if (L.pTail == Q)
		{
			L.pTail = p;
		}
	}
	else
		AddHead(L, p);
}
void CreateList(LIST& L)
{
	int n;
	cin >> n;
	int x;
	while (n-- > 0)
	{
		cin >> x;
		AddTail(L, CreateNode(x));
	}
}
bool RemoveHead(LIST& L)
{
	if (L.pHead)
	{
		NODE* p;
		p = L.pHead;
		L.pHead = L.pHead->pNext;
		if (L.pHead == NULL)
		{
			L.pTail = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
bool RemoveAfterQ(LIST& L, NODE* Q)
{
	if (Q)
	{
		NODE* p;
		p = Q->pNext;
		if (p)
		{
			if (p == L.pTail)
				L.pHead = Q;
			Q->pNext = p->pNext;
			delete p;
			return 1;

		}

	}
	else
		return RemoveHead(L);
}
bool RemoveTail(LIST& L)
{
	NODE* p;
	p = L.pHead;
	while (p->pNext->pNext != NULL)
	{
		p = p->pNext;
	}
	return RemoveAfterQ(L, p);
}
NODE* SearchNode (LIST L, int x)
{
	NODE* p;
	p = L.pHead;
	while (p != NULL && p->key != x)
	{
		p = p->pNext;
	}
	return p;
}
void PrintList(LIST L)
{
	NODE* p;
	if (L.pHead)
	{
		p = L.pHead;
		while (p)
		{
			cout << p->key << " ";
			p = p->pNext;
		}
	}
	else cout << "Danh sach rong";
	cout << endl;
}
NODE* SeparateHead(LIST& L)
{
	NODE* p = L.pHead;
	if (p == NULL) return NULL;
	L.pHead = L.pHead->pNext;
	if (L.pHead == NULL)
		L.pTail = NULL;
	p->pNext = NULL;
	return p;
}
void SelectionSort_List(LIST& L)
{
	NODE* p, * q, * min;
	p = L.pHead;
	while (p != L.pTail)
	{
		min = p;
		q = p->pNext;
		while (q)
		{
			if (min->key > q->key) min = q;
			q = q->pNext;
		}
		if (p != min) swap(p->key, min->key);
		p = p->pNext;
	}
}
void MergeSplit(LIST& L, LIST& L1, LIST& L2)
{
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	while (L.pHead)
	{
		AddTail(L1, SeparateHead(L));
		if (L.pHead) AddTail(L2, SeparateHead(L));
	}
}
void Merge(LIST& L, LIST& L1, LIST& L2)
{
	CreateEmptyList(L);
	while (L1.pHead != NULL || L2.pHead != NULL)
	{
		if (L1.pHead != NULL && (L2.pHead == NULL || L1.pHead->key < L2.pHead->key))
			AddTail(L, SeparateHead(L1));
		else AddTail(L, SeparateHead(L2));
	}
}
void MergeSort(LIST& L)
{
	if (L.pHead != L.pTail)
	{
		LIST L1, L2;
		MergeSplit(L, L1, L2);
		MergeSort(L1);
		MergeSort(L2);
		Merge(L, L1, L2);
	}
}
void Partition(LIST& L, LIST& L1, NODE*& pivot, LIST& L2)
{
	if (L.pHead == NULL) return;
	pivot = SeparateHead(L);
	NODE* p;
	while (L.pHead)
	{
		p = SeparateHead(L);
		if (p->key < pivot->key) AddTail(L1, p);
		else AddTail(L2, p);

	}
}
void Join(LIST& L, LIST& L1, NODE* pivot, LIST& L2)
{
	while (L1.pHead)
	{
		AddTail(L, SeparateHead(L1));
	}
	AddTail(L, pivot);
	while (L2.pHead)
	{
		AddTail(L, SeparateHead(L2));
	}
}
void QuickSort(LIST& L)
{
	LIST L1, L2;
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	NODE* pivot;
	Partition(L, L1, pivot, L2);
	if (L1.pHead != L1.pTail)
		QuickSort(L1);
	if (L2.pHead != L2.pTail)
		QuickSort(L2);
	Join(L, L1, pivot, L2);


}
int main()
{
	LIST L;
	CreateEmptyList(L);
	CreateList(L);
	PrintList(L);
	QuickSort(L);
	PrintList(L);
	return 0;
}

