#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

int main()
{
	Queue pq;
	QueueInit(&pq);
	
	QueuePush(&pq, 1);
	printf("data=%d size=%d\n", QueueBack(&pq), QueueSize(&pq));
	
	QueuePush(&pq, 2);
	printf("data=%d size=%d\n", QueueBack(&pq), QueueSize(&pq));

	QueuePush(&pq, 3);
	printf("data=%d size=%d\n", QueueBack(&pq), QueueSize(&pq));
	
	QueuePush(&pq, 4);
	printf("data=%d size=%d\n", QueueBack(&pq), QueueSize(&pq));

	QueuePush(&pq, 5);
	printf("data=%d size=%d\n", QueueBack(&pq), QueueSize(&pq));
	QueuePop(&pq);

	printf("data=%d size=%d\n", QueueFront(&pq), QueueSize(&pq));

	QueueDestory(&pq);
	return 0;
}