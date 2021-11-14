#pragma once
#include<stdio.h>

void Swap(int* p, int*q);

void PrintArrary(int* a, int n);
// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
//ð������
void BubbleSort(int*arr, int n);
//��������-�ݹ�
void QuickSort(int* arr, int left, int right);
//��������-�ǵݹ�
void QuickSortNonR(int* arr, int left, int right);
//�鲢����-�ݹ�
void MergeSort(int* arr, int n);