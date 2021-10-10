#define _CRT_SECURE_NO_WARNINGS 1

#include"Joseph.h"

ListNode* CreateNode(Datatype id)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
		return NULL;

	node->id = id;
	node->prev = node;
	node->rear = node;

	return node;
}

void InsertNode(ListNode* phead, Datatype id)
{
	assert(phead);
	assert(id > 0);

	ListNode* NewNode = CreateNode(id);
	NewNode->id = id;
	phead->prev->rear = NewNode;
	NewNode->prev = phead->prev;
	phead->prev = NewNode;
	NewNode->rear = phead;

	return;
}
void PrintList(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead;
	while (cur->rear != phead)
	{
		printf("%d ", cur->id);
		cur = cur->rear;
	}
	printf("%d\n", cur->id);

	return;
}
ListNode* CreateJosephRing(int n)
{
	assert(n > 0);
		
	ListNode* phead = CreateNode(1);
	for (int i = 1; i < n; i++)
	{
		InsertNode(phead, i + 1);//i+1：节点所对应的编号
	}

	return phead;
}
Datatype FindWinner(ListNode* phead, int x, int m, int n)
{
	assert(phead);
	assert(m > 0);
	assert(x > 0 && x < n);//开始报数的编号X要小于约瑟夫环的总人数

	ListNode* cur = phead;
	
	while (cur->id != x)
	{
		cur = cur->rear;
	}

	while (cur->rear != cur)
	{
		for (int i = 1; i < m; i++)
		{
			cur = cur->rear;
		}
		ListNode* del = cur;
		cur->prev->rear = cur->rear;
		cur->rear->prev = cur->prev;
		cur = cur->rear;
		free(del);
	}

	return cur->id;
}