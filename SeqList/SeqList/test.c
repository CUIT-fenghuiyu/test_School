#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SListNode* Phead = NULL;
	Phead = BuySListNode(0);
	SListPrint(Phead);
	SListPushBack(&Phead, 1);
	SListPrint(Phead);
	SListPushBack(&Phead, 2);
	SListPrint(Phead);
	SListPushBack(&Phead, 3);
	SListPrint(Phead);
	SListPushBack(&Phead, 4);
	SListPrint(Phead);
	SListPushFront(&Phead, 5);
	SListPrint(Phead);
	SListNode* aim = SListFind(Phead, 1);
	SListPrint(aim);
	SListInsertAfter(aim, 6);
	SListPrint(Phead);
	SListPopBack(&Phead);
	SListPrint(Phead);
	SListPopFront(&Phead);
	SListPrint(Phead);
	SListDestory(&Phead);
	SListPrint(Phead);

	return 0;
}