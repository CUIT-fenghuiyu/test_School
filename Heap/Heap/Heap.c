#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdJustDown(int* arr, int n, int parent)
{
	int	child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}	
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
		}
		parent = child;
		child = child * 2 + 1;
	}

}

void CreateHeap(int* arr, int n)
{
	int i = 0;
	for (i = ((n - 1) - 1 ) / 2; i >= 0; i--)
	{
		AdJustDown(arr, n, i);
	}
}

void HeapSort(int* arr, int n)
{
	int i = n - 1;

	while (i>0)
	{
		Swap(&arr[0], &arr[i]);
		i--;
		AdJustDown(arr, i, 0);
	}
}

int main()
{
	int arr[] = { 14,23,41,32,1,2,42,33,92,10 };

	CreateHeap(arr, sizeof(arr) / sizeof(arr[0]));
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}