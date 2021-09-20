#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* new = (SListNode*)malloc(sizeof(SListNode));
	assert(new != NULL);
	
	new->data = x;
	new->next = NULL;

	return new;
}

void SListPrint(SListNode* plist)
{
	if (plist == NULL)
	{
		return;
	}

	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* next = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = next;
	}
	else
	{
		SListNode* cur = *pplist;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = next;
	}
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* new = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = new;
	}
	else
	{
		new->next = (*pplist)->next;
		(*pplist)->next = new;
	}

}

void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}

	else
	{
		SListNode* cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}

		free(cur->next);
		cur->next = NULL;
	}
}

void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}

	else
	{
		SListNode* next = (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist != NULL);
	
	SListNode* cur = plist;
	while (cur->data != x)
	{		
		cur = cur->next;
	}

	return cur;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);

	if (pos->next == NULL)
	{
		SListPushBack(&pos, x);
	}
	else
	{
		SListNode* cur = pos;
		SListNode* next = cur->next;
		SListNode* new = BuySListNode(x);
		cur->next = new;
		new->next = next;
	}
	
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	
	SListNode* next = pos->next;
	while (next != NULL)
	{
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}

void SListDestory(SListNode* plist)
{

}