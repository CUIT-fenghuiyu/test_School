#define _CRT_SECURE_NO_WARNINGS 1

struct ListNode *detectCycle(struct ListNode *head) {
	int pos = -1;
	struct ListNode *slow, *fast;
	fast = slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			struct ListNode* begin = head;
			head = 0;
			while (begin == slow)
			{
				begin = begin->next;
				slow = slow->next;
				pos++;
			}
		}
	}

	return begin;
}