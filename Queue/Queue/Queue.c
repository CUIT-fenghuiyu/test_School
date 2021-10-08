#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QueueInit(Queue* Pq)
{
	//检查参数
	assert(Pq);

	Pq->phead =Pq->ptail = NULL;
}
void QueueDestory(Queue* Pq)
{
	//检查参数
	assert(Pq);
	assert(!(QueueEmpty(Pq)));

	QueueNode* cur = Pq->phead;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	Pq->phead = Pq->ptail = NULL;

	return;
}
void QueuePush(Queue* Pq, QDataType x)
{
	//检查参数
	assert(Pq);
	
	QueueNode* newQnode = (QueueNode*)malloc(sizeof(QueueNode));
	newQnode->data = x;
	newQnode->next = NULL;
	
	if (QueueEmpty(Pq))
	{
		Pq->phead = Pq->ptail = newQnode;
	}
	else
	{
		Pq->ptail->next = newQnode;
		Pq->ptail = newQnode;
	}
	
	return;
}
void QueuePop(Queue* Pq)
{
	//检查参数
	assert(Pq);
	assert(!QueueEmpty(Pq));

	if (Pq->phead->next == NULL)
	{
		free(Pq->phead);
		Pq->phead = Pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = Pq->phead->next;
		free(Pq->phead);
		Pq->phead = next;
	}

}
int QueueSize(Queue* Pq)
{
	//检查参数
	assert(Pq);

	int n = 0;
	QueueNode* cur = Pq->phead;

	while (cur)
	{
		n++;
		cur = cur->next;
	}

	return n;
}
QDataType QueueFront(Queue* Pq)
{
	//检查参数
	assert(Pq);
	assert(!(QueueEmpty(Pq)));

	return Pq->phead->data;
}
QDataType QueueBack(Queue* Pq)
{
	//检查参数
	assert(Pq);
	assert(!(QueueEmpty(Pq)));

	return Pq->ptail->data;
}
bool QueueEmpty(Queue* Pq)
{
	return (Pq->phead == NULL && Pq->ptail == NULL);
}