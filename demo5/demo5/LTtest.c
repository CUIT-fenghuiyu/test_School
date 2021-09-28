#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

int main()
{
	ListNode* pHead = ListCreate();
	ListPrint(pHead);
	ListInsert(pHead, 1);
	ListInsert(pHead, 2);
	ListInsert(pHead, 3);
	ListInsert(pHead, 4);
	ListPrint(pHead);

	ListPushFront(pHead, 5);
	ListPushFront(pHead, 6);
	ListPushFront(pHead, 7);
	ListPushFront(pHead, 8);
	ListPrint(pHead);

	ListPushBack(pHead, 9);
	ListPushBack(pHead, 10);
	ListPushBack(pHead, 11);
	ListPushBack(pHead, 12);
	ListPrint(pHead);
	
	ListErase(pHead->_next);
	ListPrint(pHead);

	ListPopFront(pHead);
	ListPrint(pHead);

	ListPopBack(pHead);
	ListPopBack(pHead);

	ListPrint(pHead);
	return 0;
}