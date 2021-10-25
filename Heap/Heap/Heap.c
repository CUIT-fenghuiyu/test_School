#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void Swap(int* a, int* b)
{
	assert(a && b);

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 条件：左右子树都是小堆/大堆
void AdJustDown(int* a, int n, int parent)
{
	assert(a);
	
	int	child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}	
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else {
			break;
		}
	}

}

void AdJustup(int* a,int child)
{
	assert(a);
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1 )/ 2;
		}
		else
		{
			break;
		}
	}
}


void CreateHeap(HP* php, int n)
{
	assert(php);
	int i = 0;
	for (i = ((n - 1) - 1 ) / 2; i >= 0; i--)
	{
		AdJustDown(php->a, n, i);
	}
}

void HeapInit(HP* php, int* arr, int n)
{
	assert(php);

	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(php->a, arr, sizeof(HPDataType) * n);
	php->size = n;
	php->capacity = n;
	CreateHeap(php, n);
}

void HeapSort(HP* php, int n)
{
	assert(php);

	int i = n - 1;

	while (i>0)
	{
		Swap(&php->a[0], &php->a[i]);
		i--;
		AdJustDown(php->a, i, 0);
	}
}

void PrintHeap(HP* php)
{
	assert(php);
	assert(!HeapEmpety(php));

	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = (php->capacity)* 2;
		php->a = (HPDataType*)realloc(php->a, newcapacity*sizeof(HPDataType));
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdJustup(php->a, php->size - 1);
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!(HeapEmpety(php)));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdJustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!(HeapEmpety(php)));

	return php->a[0];
}

bool HeapEmpety(HP* php)
{
	assert(php);

	return php->size == 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	assert(!HeapEmpety(php));

	free(php->a);
	php->a = NULL;
	php->size = 0;
}

int HeapSize(HP* php)
{
	return php->size;
}

void TopK(HP* php, int n)
{
	while (n--)
	{
		printf("%d ", HeapTop(php));
		HeapPop(php);
	}
	printf("\n");
}