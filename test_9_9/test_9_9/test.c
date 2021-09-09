#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SeqList sql;
	SeqListInit(&sql);
	SeqListPushBack(&sql, 1);
	SeqListPushBack(&sql, 2);
	SeqListPushBack(&sql, 3);
	SeqListPushBack(&sql, 4);
	SeqListPushBack(&sql, 5);
	SeqListPrint(&sql);

	printf("%d\n",SeqListFind(&sql, 3) );

	SeqListInsert(&sql, 2, 9);
	SeqListPrint(&sql);

	SeqListErase(&sql, 1);
	SeqListPrint(&sql);


	return 0;
}