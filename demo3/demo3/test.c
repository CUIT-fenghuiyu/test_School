#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
struct Node {
	int val;
	struct Node *next;
	struct Node *random;
	
};

void RandomCopy(struct Node* head) {
	struct Node* cur = head;
	while (cur)
	{
		struct Node* next = cur->next->next;
		if (cur->random != NULL) {
			cur->next->random = cur->random->next;
		}
		else {
			cur->next->random = NULL;
		}
		cur = next;
	}
}

struct Node* apartList(struct Node* head) {
	struct Node* cur = head;
	struct Node *tail, *copyHead;
	tail = copyHead = (struct Node*)malloc(sizeof(struct Node));
	
	while (cur)
	{
		struct Node* next = cur->next->next;
		tail->next = cur->next;
		tail = tail->next;
		cur->next = next;
		if (next != NULL) {
			tail->next = next->next;
		}
		else {
			tail->next = NULL;
		}
		cur = next;
	}

	struct Node* copyRand = copyHead->next;
	free(copyHead);

	return copyRand;
}

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) {
		return NULL;
	}
	struct Node* cur = head;
	while (cur)
	{
		struct Node* next = cur->next;
		struct Node* cloNode = (struct Node*)malloc(sizeof(struct Node));
		cur->next = cloNode;
		cloNode->val = cur->val;
		cloNode->next = next;
		cur = next;
	}
	
	RandomCopy(head);
	return apartList(head);
}
