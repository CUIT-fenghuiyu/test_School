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

//�����ڵ�
ListNode* CreateNode(Datatype id);
//����ڵ�
void InsertNode(ListNode* phead, Datatype id);
//��ӡ
void PrintList(ListNode* phead);
//����Լɪ��
ListNode* CreateJosephRing(int n);
//�ҳ�ʤ����
Datatype FindWinner(ListNode* phead, int x, int m, int n);