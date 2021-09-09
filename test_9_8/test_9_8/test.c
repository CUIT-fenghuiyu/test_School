#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int missingNumber(int* nums, int numsSize)
{
	int n = 0;//������ʧ����
	int i;
	//�Ⱥ������������������
	for (i = 0; i < numsSize; i++)
	{
		n ^= nums[i];
	}
	//�ٺ�0��n����������������n������ʧ������
	for (i = 0; i <= numsSize; i++)
	{
		n ^= i;
	}

	return n;
}

//�ߵ�ָ�������е���
void reverse(int* nums, int n)
{
	int begin = 0;
	int end = n - 1;
	int temp;

	while (begin < end)
	{
		temp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = temp;

		begin++;
		end--;
	}
}


void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
	if (k)
	{

		reverse(nums, numsSize - k);//�ߵ�ǰ�漸����
		reverse(nums+numsSize-k, k);//�ߵ����漸����
		reverse(nums, numsSize);//�ߵ����������е���
	}

	return 0;
}

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	int n = 0;
	int i;
	int pos = 0;
	int num1 = 0;
	int num2 = 0;
	int* str = (int*)malloc(sizeof(int) * 2);
	
	for (i = 0; i < numsSize; i++)
	{
		n ^= nums[i];
	}

	for (i = 0; i < 32; i++)
	{
		if ((n >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}

	for (i = 0; i < numsSize; i++)
	{
		if ((nums[i] >> pos) & 1)
		{
			num1 ^= nums[i];
		}
		else
		{
			num2 ^= nums[i];
		}
	}

	str[0] = num1;
	str[1] = num2;
	*returnSize = 2;

	return str;
}

int main()
{
	int nums[] = { 4,1,4,6 };
	int returnSize = 0;
	int *str;

	str = singleNumbers(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
	
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n",*(str+i));
	}

	return 0;
}