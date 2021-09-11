#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

int removeElement(int* nums, int numsSize, int val)
{
	assert(nums);
	if (numsSize == 0)
		return 0;

	size_t slow = 0;
	size_t fast = 0;

	while (fast < numsSize)
	{
		if (nums[fast] != val)
		{
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}

	return slow;
}

int removeDuplicates(int* nums, int numsSize) {
	assert(nums);
	if (numsSize == 0)
		return 0;
	size_t slow = 1;
	size_t fast = 1;
	
	while (fast < numsSize)
	{
		if (nums[fast] != nums[fast - 1])
		{
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}

	return slow;
}

int main()
{
	int nums[] = { 1,2,2,2,2,3,3,4,4 };
	int lenth = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));
	
	for (int i = 0; i < lenth; i++)
	{
		printf("%d\n",nums[i]);
	}
}