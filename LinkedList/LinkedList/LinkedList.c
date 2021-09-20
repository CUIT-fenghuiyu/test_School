#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkedList.h"


ListNode* Develop_Node(LSTDataType input)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	assert(Node != NULL);

	Node->data = input;
	Node->Next_node = NULL;

	return Node;
}

void ListPushFront(ListNode** PPHead, LSTDataType input)
{
	assert(PPHead);

	if (*PPHead == NULL)
	{
		*PPHead = Develop_Node(0);
	}

	ListNode* Newnode = Develop_Node(input);
	Newnode->Next_node = (*PPHead)->Next_node;
	(*PPHead)->Next_node = Newnode;

}

void ListPushBack(ListNode** PPHead, LSTDataType input)
{
	assert(PPHead);

	if (*PPHead == NULL)
	{
		*PPHead = Develop_Node(0);
	}

		ListNode* Current_node = (*PPHead);
		while (Current_node->Next_node != NULL)
		{
			Current_node = Current_node->Next_node;
		}

		ListNode* New_node = Develop_Node(input);
		Current_node->Next_node = New_node;
}

void ListPopFront(ListNode** PPHead)
{
	assert(PPHead);
	assert(*PPHead);

	if ((*PPHead)->Next_node == NULL)
	{
		free(*PPHead);
		*PPHead = NULL;
	}

	else
	{
		ListNode* Next_node = (*PPHead)->Next_node;
		free(*PPHead);
		*PPHead = Next_node;
	}
}

void ListPopBack(ListNode** PPHead)
{
	assert(PPHead);
	assert(*PPHead);

	if ((*PPHead)->Next_node == NULL)
	{
		free(*PPHead);
		*PPHead = NULL;
	}

	else
	{
		ListNode* Current_node = *PPHead;
		while ((Current_node->Next_node)->Next_node != NULL)
		{
			Current_node = Current_node->Next_node;
		}

		free(Current_node->Next_node);
		Current_node->Next_node = NULL;
	}
}

void ListPrint(ListNode* PHead)
{
	if (PHead == NULL)
	{
		printf("Á´±íÎª¿Õ!\n");
	}
	else
	{
		ListNode* Current_node = PHead;

		while (Current_node->Next_node != NULL)
		{
			printf("%d->", Current_node->data);
			Current_node = Current_node->Next_node;
		}
		printf("%d\n", Current_node->data);

	}

}

