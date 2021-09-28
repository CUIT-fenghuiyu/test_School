#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->_data = 0;
	pHead->_next = pHead;
	pHead->_prev = pHead;

	return pHead;
}

// �ж������Ƿ�Ϊ��
bool ListEmpety(ListNode* pHead)
{
	assert(pHead);

	return pHead->_next == pHead;
}

// ˫����������
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
// ˫�������ӡ
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
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead, x);
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);

	ListErase(pHead->_prev);
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead->_next, x);
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);

	ListErase(pHead->_next);
}
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
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

