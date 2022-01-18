#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>

typedef struct Node {

	int data;
	struct Node *next;

}node, *LinkList;

void selectSort(LinkList head)
{
	LinkList curNode = head;
	LinkList firstNode;
	LinkList minNode;
	int minInteger,temp;

	while(curNode->next != NULL)
	{
		firstNode = curNode->next;
		minNode = firstNode;
		minInteger = minNode->data;

		while(firstNode->next != NULL)
		{
			firstNode = firstNode->next;
			if (firstNode->data < minInteger) //能够稳定排序
			{
				minNode = firstNode;
				minInteger = minNode->data;
			}
		}

		temp = (curNode->next)->data;
		(curNode->next)->data = minNode->data;
		minNode->data = temp;

		curNode = curNode->next;
	}
}

int main()
{
	int n = 15;
	int arr[15] = {15,92,21,11,8,9,7,35,2,99,87,64,86,11,1};
	LinkList head = (LinkList)malloc(sizeof(node));
	LinkList cur = (LinkList)malloc(sizeof(node));
	head->next = cur;

	printf("原数据: ");
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		cur->data = arr[i];
		if (i < n - 1)
		{
			cur->next = (node*)malloc(sizeof(node));
			cur = cur->next;
		}
	}
	cur->next = NULL;

	selectSort(head);

	printf("选择排序后结果：");
	cur = head->next;
	while (cur!=NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
