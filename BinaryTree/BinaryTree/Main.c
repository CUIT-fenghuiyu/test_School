#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

int main()
{
	char arr[100];
	gets(arr);
	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, &i);
	printf("%d\n", BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	BinaryTreePrevOrder(root);
	printf("\n"); 
	BinaryTreeInOrder(root);
	printf("\n"); 
	BinaryTreePostOrder(root);
	printf("\n");

	return 0;
}