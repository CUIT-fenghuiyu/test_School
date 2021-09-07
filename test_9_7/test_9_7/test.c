//#include<stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,9,7,10,8 };
//	int i, j, n = 10;
//	int temp;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		int exchange = 0;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				exchange = 1;
//			}
//			if (exchange = 1)
//				break;
//		}
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9};
	int key = 0;

	int min = 0;
	int max = 9;
	int mid = 0;

	scanf("%d", &key);
	while (min <= max)
	{
		mid = (min + max) >> 1;

		if (arr[mid] > key)
			max--;
		else if (arr[mid] < key)
			min++;
		else
		{
			printf("%d",arr[mid]);
			return 0;
		}
	}

	printf("No find");
	return 0;
}