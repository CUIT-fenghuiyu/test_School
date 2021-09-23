#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode* removeElements(struct ListNode* head, int val) {
//	struct ListNode* tail = NULL;
//	struct ListNode* cur = head;
//	struct ListNode* newList = NULL;
//
//	while (cur != NULL)
//	{
//		struct ListNode* next = cur->next;
//		if (cur->val == val)
//		{
//			free(cur);
//		}
//		else
//		{
//			if (newList == NULL)
//			{
//				newList = cur;
//				tail = newList;
//			}
//			else
//			{
//				tail->next = cur;
//				tail = tail->next;
//				tail->next = NULL;
//			}
//		}
//		cur = next;
//
//	}
//
//	return newList;
//}

//struct ListNode* removeElements(struct ListNode* head, int val) {
//	struct ListNode* cur = head;
//	struct ListNode* next = NULL;
//	struct ListNode* newList = NULL;
//	struct ListNode* tail = NULL;
//	struct ListNode* bef = NULL;
//	if (newList == NULL) {
//		while (cur != NULL)
//		{
//			if (cur->val != val) {
//				next = cur->next;
//				free(cur);
//				break;
//			}
//			else {
//				cur = next;
//			}
//
//		}
//		newList = cur;
//		tail = newList;
//		cur = cur->next;
//	}else {
//		while (cur != NULL)
//		{
//			if (cur->val == val) {
//				next = cur->next;
//				free(cur);
//				cur = next;
//			}
//
//		}
//	}
//}

#include<stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 


//struct ListNode* reverseList(struct ListNode* head) {
//	struct ListNode* newList = NULL;
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* nextNode = head->next;
//	while (nextNode != NULL)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = nextNode;
//		nextNode = nextNode->next;
//	}
//	n2->next = n1;
//	newList = n2;
//
//	return newList;
//}

//void PushFront(struct ListNode** newList, struct ListNode* cur) {
//
//	cur->next = *newList;
//	*newList = cur;
//}
//
//  struct ListNode* reverseList(struct ListNode* head) {
//	  struct ListNode* cur = head;
//	  struct ListNode* newList = NULL;
//	  
//	  while (cur) {
//		  struct ListNode* next = cur->next;
//		  PushFront(&newList, cur);
//		  cur = next;
//	  }
//	  return newList;
//  }

  struct ListNode* middleNode(struct ListNode* head) {
	  struct ListNode *slow, *fast;
	  slow = fast = head;
	  while (fast && fast->next)
	  {
		  slow = slow->next;
		  fast = fast->next->next;
	  }

	  return slow;
  }