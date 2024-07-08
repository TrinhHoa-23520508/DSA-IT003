#include<iostream>
using namespace std;
int LinearSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) return i;
	}
	return -1;

}
int BinarySearch(int a[], int left, int right, int x)//Tìm kiếm trên mảng đã sắp xếp tăng dần
{
	if (left <= right)
	{
		int middle = (left + right) / 2;
		if (a[middle] == x) return middle;
		if (a[middle] < x) return BinarySearch(a, middle + 1, right, x);
		else return BinarySearch(a, left, middle - 1, x);
	}
	return -1;
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[index]) index = j;
		}
		if (index != i) swap(a[i], a[index]);
	}
}
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int pos = i - 1;
		int temp = a[i];
		while (pos >= 0 && a[pos] > temp)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = temp;
	}
}
void Heapify(int a[], int n, int i)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<n && a[left]>a[max])
	{
		max = left;
	}
	if (right<n && a[right]>a[max])
	{
		max = right;
	}
	if (max != i)
	{
		swap(a[max], a[i]);
		Heapify(a, n, max);
	}

}
void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)//BuildHeap
	{
		Heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)//Hoán đổi giá trị max về cuối mảng đang xét và hiệu chỉnh lại cây Heap
	{
		swap(a[i], a[0]);//Đưa max về cuối mảng đang xét
		Heapify(a, i, 0);
	}
}
void QuickSort(int a[], int left, int right)
{
	int pivot = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < right) QuickSort(a, i, right);
	if (left < j) QuickSort(a, left, j);
}
void Copy(int a[], int* b, int left, int right)
{
	int nb = right - left + 1;
	for (int i = 0; i < nb; i++)
	{
		b[i] = a[left + i];
	}
}
void Merge(int a[], int left, int right)
{
	int* b;
	int nb = right - left + 1;
	b = new int[nb];
	Copy(a, b, left, right);
	int middle = (nb - 1) / 2;
	int i0 = 0;
	int i1 = middle + 1;
	for (int i = left; i <= right; i++)
	{
		if (i0 <= middle && (i1 >= nb || b[i0] < b[i1]))
		{
			a[i] = b[i0++];
		}
		else a[i] = b[i1++];
	}


}
void MergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		MergeSort(a, left, middle);
		MergeSort(a, middle + 1, right);
		Merge(a, left, right);
	}
}
void Nhap(int a[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{

}
