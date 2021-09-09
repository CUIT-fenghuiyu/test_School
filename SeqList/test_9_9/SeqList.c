#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
typedef int SQLDataType;

void SQLinit(SQL* psql)
{
	assert(psql);

	psql->arrary = NULL;
	psql->size = psql->capacity = 0;
}

void SQLdestroy(SQL* psql)
{
	assert(psql);

	free(psql->arrary);
	psql->arrary = NULL;
	psql->size = 0;
	psql->capacity = 0;
}

void SQLCheckCapacity(SQL* psql)
{
	assert(psql);

	if (psql->size == psql->capacity)
	{
		size_t newcapacity = psql->capacity == 0 ? 4 : psql->capacity * 2;
		psql->arrary = realloc(psql->arrary, newcapacity * sizeof(SQLDataType));
		psql->capacity = newcapacity;
	}
}

void SQLPrint(SQL* psql)
{
	assert(psql);

	for (SQLDataType i = 0; i < (psql->size); i++)
	{
		printf("%d\n",psql->arrary[i]);
	}
}


void SQLPushfront(SQL* psql, SQLDataType fate)
{
	assert(psql);
	
	SQLCheckCapacity(psql);
	SQLDataType i;
	for (i = psql->size - 1; i > 0; i--)
	{
		psql->arrary[i] = psql->arrary[i - 1];
	}

	psql->arrary[i] = fate;
	(psql->size)++;
}

void SQLPushBack(SQL* psql, SQLDataType fate)
{
	assert(psql);

	SQLCheckCapacity(psql);
	psql->arrary[psql->size] = fate;
	(psql->size)++;
}

void SQLPopfront(SQL* psql)
{
	assert(psql);

	for (SQLDataType i = 0; i < psql->size - 1; i++)
	{
		assert(psql);
		psql->arrary[i] = psql->arrary[i + 1];
	}
	(psql->size)--;
}

void SQLPopBack(SQL* psql)
{
	assert(psql);

	(psql->size)--;
}
