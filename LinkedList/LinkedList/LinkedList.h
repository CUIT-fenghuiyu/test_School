#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LSTDataType;

typedef struct LinkListNode
{
	LSTDataType data;
	struct LinkListNode* Next_node;
}ListNode;

ListNode* Develop_Node(LSTDataType input);
void ListPushFront(ListNode** PPHead, LSTDataType input);
void ListPushBack(ListNode** PPHead, LSTDataType input);
void ListPopFront(ListNode** PPHead);
void ListPopBack(ListNode** PPHead);
void ListPrint(ListNode* PHead);

