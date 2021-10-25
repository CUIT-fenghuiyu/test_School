#pragma once

#include"Heap.h"

int main()
{
	int arr[] = { 14,23,41,32,1,2,42,33,92,10 };

	HP hp;
	HeapInit(&hp, arr, sizeof(arr) / sizeof(int));
	PrintHeap(&hp);
	TopK(&hp, 3);
	/*HeapPop(&hp);
	PrintHeap(&hp);
	HeapPush(&hp, 99);
	PrintHeap(&hp);
	printf("%d\n", HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	HeapPush(&hp, 100);
	PrintHeap(&hp);
	HeapPush(&hp, 1);
	PrintHeap(&hp);
	HeapPush(&hp, 0);
	PrintHeap(&hp);
	printf("%d\n", HeapSize(&hp));*/

	return 0;

}