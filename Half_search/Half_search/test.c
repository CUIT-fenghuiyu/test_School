#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int HalfSeach(int arr[], int n, int key)//nΪ�����С��keyΪ������Ԫ��
{

	int begin = 0, end = n-1, mid; //begin��Ϊ���ҷ�Χ�Ŀ�ͷ��end��Ϊ���ҷ�Χ�Ľ�β��mid��Ϊ�������۰��Ԫ���±�
	while (begin <= end) //���ֲ��ҽ��е�����
	{
		mid = (begin+end) / 2;
		if (arr[mid] == key)
		{
			return 1; // ���ҳɹ�������1
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

	return 0; //���ִ�е���һ��˵������ʧ�ܣ�����0
}

int main()
{
	int arr[21];
	int key;

	printf("����С�����˳����������21������");
	for(int i=0; i<21; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("������Ҫ���ҵ�ֵkey: ");
	scanf("%d", &key);

	if (HalfSeach(arr, 21, key))
	{
		printf("���ҳɹ�");
	}
	else
	{
		printf("����ʧ��");

	}

	return 0;
}