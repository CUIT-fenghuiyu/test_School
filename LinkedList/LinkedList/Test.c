#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkedList.h"

int main()
{
	ListNode* PHead = NULL;
	ListPushBack(&PHead, 1);
	ListPrint(PHead);
	ListPushBack(&PHead, 2);
	ListPrint(PHead);
	ListPushBack(&PHead, 3);
	ListPrint(PHead);
	ListPushFront(&PHead, 4);
	ListPrint(PHead);
	ListPushFront(&PHead, 5);
	ListPrint(PHead);
	ListPushFront(&PHead, 6);

	return 0;
}