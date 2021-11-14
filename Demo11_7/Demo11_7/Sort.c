#pragma once
#include<stdio.h>
#include"Sort.h"
#include"Stack.h"

void PrintArrary(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p, int*q)
{
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

//插入排序
void InsertSort(int* a, int n)
{
	int end;
	int tmp;
	for (int i = 0; i < n - 1; i++)
	{
		end = i;
		tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//shell排序 
void ShellSort(int* a, int n)
{
	int end;
	int tmp;
	int gap = n/3 + 1;
	while(gap >1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			end = i;
			tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n-1;
	int mini, maxi,i;
	while (begin < end)
	{
		mini = begin;
		maxi = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}
}

//堆排序向下调整
void AdjustDwon(int* a, int n, int root)
{
	
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[root] < a[child])
		{
			Swap(&a[root], &a[child]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
	
}

//堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while(end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

void BubbleSort(int*arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] >= arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void BubbleSort2(int* a, int n)
{
	for (int end = n; end > 0; --end)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}
}


void PrintArr(int*arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}


int GetMidIndex(int* arr, int left, int right)
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

//hoare法
int PartSort1(int* arr, int left, int right)
{
	int midi = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[midi]);

	int keyi = left;

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


//挖坑法
int PartSort2(int* arr, int left, int right)
{
	int midi = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[midi]);

	int hole = left;
	int key = arr[left];
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

//前后指针法
int PartSort3(int* arr, int left, int right)
{
	int midi = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[midi]);

	int prev = left;//后指针
	int cur = left + 1;//前指针
	int keyi = left;//关键位置
	while (cur <= right)
	{
		//后指针遍历数组,当cur的值比key值小并且prev+1之后就在cur的位置,则不进行交换
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[prev], &arr[keyi]);
	keyi = prev;

	return keyi;
}

//快速排序递归法
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyi = PartSort2(arr, left, right);

	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);

	return;
}

//快速排序非递归法
void QuickSortNonR(int* arr, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(arr, begin, end);
		
		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}

		if (keyi - 1 > begin)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
	}
	StackDestroy(&st);
}


void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	
	//将数组分解为1个1个的
	_MergeSort(arr,left, mid,tmp);
	_MergeSort(arr,mid + 1, right,tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1];
			begin1++;
		}

		else 
		{
			tmp[index++] = arr[begin2];
			begin2++;
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}

//归并排序
void MergeSort(int* arr,int n)
{
	int * tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}