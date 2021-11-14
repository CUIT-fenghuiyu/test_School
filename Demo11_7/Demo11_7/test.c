#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"

int main()
{
	int arr[] = {100,2,4,5,7,9,20,3,99,4,28,45,32 };
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
	PrintArrary(arr, sizeof(arr) / sizeof(int));*/

	MergeSort(arr, sizeof(arr) / sizeof(int));
	PrintArrary(arr, sizeof(arr) / sizeof(int));

	
	return 0;
}