#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->_data = 0;
	pHead->_next = pHead;
	pHead->_prev = pHead;

	return pHead;
}

// 判断链表是否为空
bool ListEmpety(ListNode* pHead)
{
	assert(pHead);

	return pHead->_next == pHead;
}

// 双向链表销毁
void ListDestory(ListNode** ppHead)
{
	assert(ppHead);
	if (*ppHead == NULL)
		return;
	
	ListNode* cur = (*ppHead)->_next;
	while (cur != (*ppHead))
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(cur);
	(*ppHead) = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	if (ListEmpety(pHead))
	{
		printf("The Linked List is empety\n");
		return;
	}

	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead, x);
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);

	ListErase(pHead->_prev);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead->_next, x);
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);

	ListErase(pHead->_next);
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	
	if (ListEmpety(pHead))
	{
		return NULL;
	}

	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}

	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* pos_prev = pos->_prev;

	newNode->_data = x;
	pos_prev->_next = newNode;
	newNode->_prev = pos_prev;
	newNode->_next = pos;
	pos->_prev = newNode;

}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);	

	if (pos->_next == pos)
	{
		free(pos);
		return;
	}

	ListNode* cur = pos;
	ListNode* pos_prev = cur->_prev;
	ListNode* pos_next = cur->_next;

	free(cur);
	pos_prev->_next = pos_next;
	pos_next->_prev = pos_prev;
}

