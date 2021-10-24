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
void AdJustDown(int* a, int n, int parent);
void AdJustup(int* a, int child);
void CreateHeap(HP* hp, int n);
void HeapInit(HP* hp, int* arr, int n);
void HeapSort(HP* hp, int n);
void PrintHeap(HP* hp, int n);
void HeapPush(HP* hp, HPDataType x);
void HeapPop(HP* hp);
bool HeapEmpety(HP* hp);
HPDataType HeapTop(HP* hp);