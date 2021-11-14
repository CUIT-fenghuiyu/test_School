#pragma once
#include<stdio.h>

void Swap(int* p, int*q);

void PrintArrary(int* a, int n);
// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
//√∞≈›≈≈–Ú
void BubbleSort(int*arr, int n);
//øÏÀŸ≈≈–Ú-µ›πÈ
void QuickSort(int* arr, int left, int right);
//øÏÀŸ≈≈–Ú-∑«µ›πÈ
void QuickSortNonR(int* arr, int left, int right);
//πÈ≤¢≈≈–Ú-µ›πÈ
void MergeSort(int* arr, int n);