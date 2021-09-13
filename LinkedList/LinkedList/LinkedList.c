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
		*PPHead = Develop_Node(input);
	}
	else
	{
		ListNode* Current_node = (*PPHead);
	}
}

void ListPushBack(ListNode** PPHead, LSTDataType input)
{
	assert(PPHead);

	if (*PPHead == NULL)
	{
		*PPHead = Develop_Node(input);
	}
	else
	{
		ListNode* Current_node = (*PPHead);
		while (Current_node->Next_node != NULL)
		{
			Current_node = Current_node->Next_node;
		}

		ListNode* New_node = Develop_Node(input);
		Current_node->Next_node = New_node;
	}
}
