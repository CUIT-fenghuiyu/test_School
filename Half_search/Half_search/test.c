#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int HalfSeach(int arr[], int n, int key)//n为数组大小，key为待查找元素
{

	int begin = 0, end = n-1, mid; //begin作为查找范围的开头，end作为查找范围的结尾，mid作为把区间折半的元素下标
	while (begin <= end) //二分查找进行的条件
	{
		mid = (begin+end) / 2;
		if (arr[mid] == key)
		{
			return 1; // 查找成功，返回1
		}
		else if(key < arr[mid])
		{
			end = mid - 1;
		}
		else if (key > arr[mid])
		{
			begin = mid + 1;
		}
	}

	return 0; //如果执行到这一步说明查找失败，返回0
}

int main()
{
	int arr[21];
	int key;

	printf("按从小到大的顺序依次输入21个数：");
	for(int i=0; i<21; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("输入你要查找的值key: ");
	scanf("%d", &key);

	if (HalfSeach(arr, 21, key))
	{
		printf("查找成功");
	}
	else
	{
		printf("查找失败");

	}

	return 0;
}