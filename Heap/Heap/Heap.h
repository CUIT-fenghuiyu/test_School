#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void Swap(int* a, int* b);
// 条件：左右子树都是小堆/大堆
void AdJustDown(int* a, int n, int parent);
void AdJustup(int* a, int child);
void CreateHeap(HP* php, int n);
void HeapInit(HP* php, int* arr, int n);
void HeapSort(HP* php, int n);
void PrintHeap(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
bool HeapEmpety(HP* php);
HPDataType HeapTop(HP* php);
void HeapDestroy(HP* php);
int HeapSize(HP* php);
void TopK(HP* php, int n);
