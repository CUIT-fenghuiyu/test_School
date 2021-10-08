#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

void QueueInit(Queue* Pq);
void QueueDestory(Queue* Pq);
void QueuePush(Queue* Pq, QDataType x);
void QueuePop(Queue* Pq);                
int QueueSize(Queue* Pq);
QDataType QueueFront(Queue* Pq);
QDataType QueueBack(Queue* Pq);
bool QueueEmpty(Queue* Pq);





