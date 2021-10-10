#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Datatype;

typedef struct ListNode
{
	Datatype id;
	struct ListNode* prev;
	struct ListNode* rear;
}ListNode;

//创建节点
ListNode* CreateNode(Datatype id);
//插入节点
void InsertNode(ListNode* phead, Datatype id);
//打印
void PrintList(ListNode* phead);
//创建约瑟夫环
ListNode* CreateJosephRing(int n);
//找出胜利者
Datatype FindWinner(ListNode* phead, int x, int m, int n);