#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct _SeqList
{
	int *elem;
	int length;
	int listsize;
} SeqList, *pSeqList;

int InitList(pSeqList L, int listsize);
int InsertList(pSeqList L, int x, int position);
int FindList(pSeqList L, int pos, int *value);
int Destroy(pSeqList);
void output(SeqList L);
int prime(int n);

int main(void)
{
	int i, n, pos, value;
	SeqList L;

	printf("�����ʼ������˳���ĳ���:");		//����˳���ɷŵ�Ԫ�ظ���
	scanf("%d", &L.listsize);
	if (InitList(&L, L.listsize) <= 0)
	{
		printf("output:\n��ʼ��˳���ʧ��\n");
		return 0;
	}

	printf("������Ҫ���뵽˳����Ԫ�ظ���:");
	scanf("%d", &n);
	//����˳����Ԫ��
	for (i = 0; i < n; i++)
	{
		InsertList(&L, prime(i + 1), i + 1);
	}
	output(L);

	printf("����˳����λ��:");
	scanf("%d", &pos);
	if (FindList(&L, pos, &value) > 0)
	{
		printf("��˳����%d��λ�õ�Ԫ����%d\n", pos, value);
	}
	Destroy(&L);
	return 0;
}

int InitList(pSeqList L, int listsize)
{
	L->elem = (int *)malloc(listsize * sizeof(int));
	if (L->elem == NULL)
	{
		return -1;
	}
	L->length = 0;
	return 1;
}

void output(SeqList L)
{
	int i;
	printf("output:\n");
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int InsertList(pSeqList L, int x, int position)
{
	int i;

	if (position < 1 || position > L->length + 1)
	{
		return -1;
	}
	if (L->length >= L->listsize)
	{
		return -2;
	}
	for (i = L->length; i >= position; i--)
	{
		L->elem[i] = L->elem[i - 1];
	}
	L->elem[i] = x;
	L->length += 1;
	return 1;
}

int Destroy(pSeqList L)
{
	if (L->elem != NULL)
	{
		free(L->elem);
		L->elem = NULL;
		L->length = 0;
		L->listsize = 0;
	}
	return 1;
}

int prime(int n)
{
	int i, j;
	int cnt;
	if (n == 1)
	{
		return 2;
	}
	else if (n == 2)
	{
		return 3;
	}

	cnt = 2;
	for (i = 5; ; i++)
	{
		for (j = 2; j < i / 2; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j >= i / 2)
		{
			cnt++;
			if (cnt == n)
			{
				return i;
			}
		}
	}
	return 0;
}

/******start******/

printf("λ�ò��Ϸ�!\n");

/******end******/