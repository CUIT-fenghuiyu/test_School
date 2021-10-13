#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define LISTSIZE 100

typedef int elemtype;

typedef struct _seq
{
	elemtype *data;
	int length;
} Seq;

int initseq(Seq *list);
int create(Seq *list, int n);
void destroy(Seq list);
void output(Seq list);
int function(Seq s, Seq t, int *value, int *position);

int main(void)
{
	int n;
	int value, position;

	Seq s = { 0 }, t = { 0 };

	if (initseq(&s) <= 0)
	{
		return 0;
	}
	if (initseq(&t) <= 0)
	{
		destroy(s);
		return 0;
	}

	printf("Input s's number:");
	scanf("%d", &n);
	create(&s, n);
	printf("s: ");
	output(s);

	printf("Input t's number:");
	scanf("%d", &n);
	create(&t, n);
	printf("t: ");
	output(t);

	printf("Output:\n");
	if (function(s, t, &value, &position) == 1)
	{
		printf("Result Value: %d, Position: %d\n", value, position);
	}
	else
	{
		printf("Not Find!\n");
	}
	destroy(s);
	destroy(t);
	return 0;
}

int initseq(Seq *list)
{
	list->data = (elemtype *)malloc(sizeof(elemtype) * LISTSIZE);
	if (list->data == NULL)
	{
		return -1;
	}
	list->length = 0;
	return 1;
}

int create(Seq *list, int n)
{
	int i;
	elemtype temp;

	for (i = 0; i < n && i < LISTSIZE; i++)
	{
		scanf("%d", &temp);
		list->data[i] = temp;
	}
	list->length = i;
	return 1;
}

void output(Seq list)
{
	int i;
	for (i = 0; i < list.length; i++)
	{
		printf("%d ", list.data[i]);
	}
	printf("\n");
}

void destroy(Seq list)
{
	if (list.data != NULL)
	{
		free(list.data);
	}
}

/******start******/
int function(Seq s, Seq t, int *value, int *position)
{
	if (s.length <= 0 || t.length <= 0)
	{
		return 0;
	}
	for (int i = 0; i <s.length; i++)
	{
		int index = 0;
		for (int j = 0; j < t.length; j++)
		{
			if (s.data[i] == t.data[j])
			{
				index = 1;
				break;
			}
		}
		if (index == 0)
		{
			*value = s.data[i];
			*position = i;
			return 1;
		}
	}
	return 0;
}
/******end******/