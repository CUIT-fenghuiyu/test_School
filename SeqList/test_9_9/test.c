#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SQL sql;
	SQLinit(&sql);
	SQLPushBack(&sql, 1);
	SQLPushBack(&sql, 2);
	SQLPushBack(&sql, 3);
	SQLPushBack(&sql, 4);
	SQLPushBack(&sql, 5);
	SQLPrint(&sql);

	return 0;
}