#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SListNode* Phead = NULL;
	Phead = BuySListNode(0);
	SListPrint(Phead);
	SListPushBack(&Phead, 1);
	SListPrint(Phead);
	SListFind(Phead, 1);

	return 0;
}