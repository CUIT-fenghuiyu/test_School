#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void Swap(int* a, int* b)
{
	assert(a && b);

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdJustDown(int* a, int n, int parent)
{
	assert(a);
	
	int	child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}	
		if (a[child] < a[parent])
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
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = child - 1 / 2;
		}
		else
		{
			break;
		}
	}
}


void CreateHeap(HP* hp, int n)
{
	assert(hp);
	int i = 0;
	for (i = ((n - 1) - 1 ) / 2; i >= 0; i--)
	{
		AdJustDown(hp->a, n, i);
	}
}

void HeapInit(HP* hp, int* a, int n)
{
	assert(hp);

	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memset(hp->a, a, sizeof(a));
	hp->size = n;
	hp->capacity = n;
	CreateHeap(hp->a, n);
}

void HeapSort(HP* hp, int n)
{
	assert(hp);

	int i = n - 1;

	while (i>0)
	{
		Swap(&hp->a[0], &hp->a[i]);
		i--;
		AdJustDown(hp->a, i, 0);
	}
}

void PrintHeap(HP* hp, int n)
{
	assert(hp);

	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void HeapPush(HP* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = (hp->capacity)* 2;
		hp->a = (HPDataType*)realloc(hp->a, newcapacity*sizeof(HPDataType));
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdJustup(hp->a, hp->size, hp->size - 1);
}

void HeapPop(HP* hp)
{
	assert(hp);
	assert(!(HeapEmpety(hp)));
	Swap(&hp->a[0], &hp->a[hp->size]);
	hp->size--;
	AdJustDown(hp, sizeof(hp->a) / sizeof(HPDataType), 0);
}

HPDataType HeapTop(HP* hp)
{
	assert(hp);
	assert(!(HeapEmpety(hp)));

	return hp->a[0];
}

bool HeapEmpety(HP* hp)
{
	assert(hp);

	return hp->size == 0;
}
