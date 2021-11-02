#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
} Node, *pLink;

int CreateLink(pLink *head);
void output(pLink head);
void merge(pLink head1, pLink head2);
void Destroy(pLink head);

int main(void)
{
	pLink l1, l2;

	printf("Input L1(0 for end):");
	if (CreateLink(&l1) < 0)
	{
		return 0;
	}
	printf("L1:");
	output(l1);
	printf("Input L2(0 for end):");
	if (CreateLink(&l2) < 0)
	{
		return 0;
	}
	printf("L2:");
	output(l2);
	merge(l1, l2);
	printf("output:\nmerged:");
	output(l1);
	Destroy(l1);
	Destroy(l2);
	return 0;
}

void output(pLink head)
{
	if (head == NULL)
	{
		return;
	}
	head = head->next;
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int CreateLink(pLink *head)
{
	int temp;
	pLink p;
	pLink s;

	(*head) = (pLink)malloc(sizeof(Node));
	if ((*head) == NULL)
	{
		return -1;
	}
	p = *head;
	p->next = NULL;

	scanf("%d", &temp);
	while (temp != 0)
	{
		s = (pLink)malloc(sizeof(Node));
		if (s == NULL)
		{
			return -1;
		}
		s->data = temp;
		s->next = p->next;
		p->next = s;
		p = s;
		scanf("%d", &temp);
	}
	return 1;
}

void Destroy(pLink head)
{
	pLink p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		free(p);
	}
}

/******start******/
void merge(pLink l1, pLink l2)
{
	pLink l1cur = l1->next;
	pLink l2cur = l2->next;
	pLink l2next;
	if (l1cur == NULL || l2cur == NULL)
		return;
	while (l1cur && l2cur)
	{
		l2next = l2cur->next;
		l2cur->next = l1cur->next;
		l1cur->next = l2cur;
		l1cur = l2cur->next;
		if (l1cur == NULL)
		{
			l2cur->next = l2next;
			l2->next = NULL;
			return;
		}
		l2cur = l2next;
	}
	l2->next = NULL;
	return;

}
/******end******/