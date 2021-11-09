#pragma once
#include<stdio.h>

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