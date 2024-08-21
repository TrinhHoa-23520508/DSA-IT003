#include<iostream>
using namespace std;
#define EMPTY 0
#define OCCUPIED 1
#define DELETED -1
#define LOAD 0.7
struct NODE
{
	int key;
	int flag;
};
struct HASHTABLE
{
	int M;
	int n;
	NODE* table;
};
int HF(HASHTABLE ht, int key)
{
	return key % ht.M;
}
int HF_LinearProbing(HASHTABLE ht, int key, int i)
{
	int h = key % ht.M;
	return (h + i) % ht.M;
}
int Insert_HashTable(HASHTABLE& ht, int x)
{
	if (double(ht.n + 1) / ht.M > LOAD)
	{
		return -1;
	}
	else
    {
        int i = 0;
	while (i < ht.M)
	{
		int j = HF_LinearProbing(ht, x, i);
		if (ht.table[j].flag == EMPTY || ht.table[j].flag == DELETED)
		{
			ht.table[j].flag = OCCUPIED;
			ht.table[j].key = x;
			ht.n++;
			return 1;
		}
		if (ht.table[j].flag == OCCUPIED && ht.table[j].key == x)
		{
			return -1;
		}
		i++;
	}
	return -1;
    }
}
int Deleted_HashTable(HASHTABLE& ht, int x)
{
	int i = 0;
	while (i < ht.M)
	{
		int j = HF_LinearProbing(ht, x, i);
		if (ht.table[j].flag == EMPTY || ht.table[j].flag == DELETED)
		{
			return -1;
		}
		if (ht.table[j].flag == OCCUPIED && ht.table[j].key == x)
		{
			ht.table[j].flag = DELETED;
			ht.table[j].key = 0;
			ht.n--;
			return 1;
		}
		i++;
	}
	return -1;
}
void CreateHashTable(HASHTABLE &ht)
{
	cin >> ht.M;
	ht.n = 0;
	ht.table = new NODE[ht.M];
	for (int i = 0; i < ht.M; i++)
	{
		ht.table[i].flag = EMPTY;
		ht.table[i].key = 0;
	}
	int num;
	cin >> num;
	int x;
	while (num-- > 0)
	{
		cin >> x;
		Insert_HashTable(ht, x);
	}
}
void Traverse_HashTable(HASHTABLE ht)
{
	NODE temp;
	for (int i = 0; i < ht.M; i++)
	{
		temp = ht.table[i];
		if (temp.flag == EMPTY) cout << "EMPTY";
		else if (temp.flag == DELETED) cout << "DELETED";
		else cout << temp.key;
		cout << endl;
	}
}
int main()
{
	HASHTABLE ht;
	CreateHashTable(ht);
	Traverse_HashTable(ht);
	return 0;
}
