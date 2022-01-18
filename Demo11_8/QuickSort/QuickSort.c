#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void PrintArr(int*arr, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}

void Swap(int*p, int*q)
{
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;

	return;
}

int GetMidIndex(int* arr, int left , int right)
{
	int mid = (left + right) / 2;
	if (arr[left] > arr[mid])
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if (arr[right] > arr[left])
		{
			return left;
		}
		else
			return right;
	}
	else
	{
		if (arr[left] > arr[right])
		{
			return left;
		}
		else if (arr[right] > arr[mid])
		{
			return mid;
		}
		else
			return right;
	}
}

//hoare·¨
int PartSort1(int* arr, int left, int right)
{
	int keyi = GetMidIndex(arr,left,right);

	while (left < right)
	{
		while (left < right && arr[right] > arr[keyi])
		{
			--right;
		}
		while (left < right && arr[left] <= arr[keyi])
		{
			++left;
		}
		
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[keyi], &arr[right]);

	return right;
}


//ÍÚ¿Ó·¨
int PartSort2(int* arr, int left, int right)
{
	int hole = GetMidIndex(arr, left, right);
	int key = arr[hole];
	while (left < right)
	{
		while (left < right && arr[right] > key)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;

	return hole;
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyi = PartSort1(arr, left, right);

	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);

	return;
}

int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArr(a, sizeof(a) / sizeof(int));

	return 0;
}