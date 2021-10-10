#define _CRT_SECURE_NO_WARNINGS 1

#include"Joseph.h"

int main() {
	ListNode* JosephRing = CreateJosephRing(10);
	PrintList(JosephRing);
	printf("The winner is %d", FindWinner(JosephRing, 1, 5, 40));
	return 0;
}