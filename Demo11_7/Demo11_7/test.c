#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"

int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5,12,10,0 };
	/*InsertSort(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int));
	
	ShellSort(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int));
	
	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int));
	
	HeapSort(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int));
	
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int));

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	PrintArrary(arr, sizeof(arr) / sizeof(int));
	
	QuickSortNonR(arr, 0, sizeof(arr) / sizeof(int) - 1);
	PrintArrary(arr, sizeof(arr) / sizeof(int));

	MergeSort(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int));*/

	PrintArrary(arr, sizeof(arr) / sizeof(int));
	MergeSortNonR(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int)); 

	return 0;
}