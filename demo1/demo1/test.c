#define _CRT_SECURE_NO_WARNINGS 1



  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* cur1 = headA;
	struct ListNode* cur2 = headB;
	int n1, n2;
	n1 = n2 = 0;
	
	while (cur1) {
		n1++;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		n2++;
		cur2 = cur2->next;
	}
	struct ListNode* longList = headA;
	struct ListNode* sortList = headB;
	if (n1 < n2) {
		longList = headB;
		sortList = headA;
	}
	int gap = abs(n1 - n2);
	while (gap--)
	{
		longList = longList->next;
	}

	while (longList && sortList)
	{
		if (longList == sortList) {
			return longList;
		}
		longList = longList->next;
		sortList = sortList->next;
	}

	return NULL;
	
}