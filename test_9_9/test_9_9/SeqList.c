#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListInit(SeqList* psql)
{
	assert(psql);

	psql->a = NULL;
	psql->size = psql->capacity = 0;
}

void SeqListDestory(SeqList* psql)
{
	assert(psql);

	free(psql->a);
	psql->a = NULL;
	psql->size = 0;
	psql->capacity = 0;
}

void SQLCheckCapacity(SeqList* psql)
{
	assert(psql);

	if (psql->size == psql->capacity)
	{
		size_t newcapacity = psql->capacity == 0 ? 4 : psql->capacity * 2;
		psql->a = realloc(psql->a, newcapacity * sizeof(SLDateType));
		psql->capacity = newcapacity;
	}
}

void SeqListPrint(SeqList* psql)
{
	assert(psql);

	for (SLDateType i = 0; i < (psql->size); i++)
	{
		printf("%d ", psql->a[i]);
	}
	printf("\n");
}


void SeqListPushFront(SeqList* psql, SLDateType fate)
{
	assert(psql);

	SQLCheckCapacity(psql);
	SLDateType i;
	for (i = psql->size - 1; i > 0; i--)
	{
		psql->a[i] = psql->a[i - 1];
	}

	psql->a[i] = fate;
	(psql->size)++;
}

void SeqListPushBack(SeqList* psql, SLDateType fate)
{
	assert(psql);

	SQLCheckCapacity(psql);
	psql->a[psql->size] = fate;
	(psql->size)++;
}

void SeqListPopFront(SeqList* psql)
{
	assert(psql);

	for (SLDateType i = 0; i < psql->size - 1; i++)
	{
		assert(psql);
		psql->a[i] = psql->a[i + 1];
	}
	(psql->size)--;
}

void SeqListPopBack(SeqList* psql)
{
	assert(psql);

	(psql->size)--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i + 1;
	}
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);

	SQLCheckCapacity(ps);
	ps->size++;

	for (int i = ps->size - 1; i > pos - 1; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos - 1] = x;

}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);


	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	ps->size--;
}