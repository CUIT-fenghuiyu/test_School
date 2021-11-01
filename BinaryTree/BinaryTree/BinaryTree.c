#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[(*pi)] == ' ')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;
}
void BinaryTreeDestory(BTNode** root)
{
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* ret;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;

	return NULL;
	
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
	
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
	
}

//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue qu;
//	BTNode * cur;
//
//	QueueInit(&qu);
//
//	QueuePush(&qu, root);
//
//	while (!QueueIsEmpty(&qu))
//	{
//		cur = QueueTop(&qu);
//
//		printf("%c", cur->_data);
//
//		if (cur->_left)
//		{
//			QueuePush(&qu, cur->_left);
//		}
//
//		if (cur->_right)
//		{
//			QueuePush(&qu, cur->_right);
//		}
//
//		QueuePop(&qu);
//	}
//
//	QueueDestory(&qu);
//}
//
//int BinaryTreeComplete(BTNode* root)
//{
//		Queue qu;
//		BTNode * cur;
//		int tag = 0;
//
//		QueueInit(&qu);
//
//		QueuePush(&qu, root);
//
//		while (!QueueIsEmpty(&qu))
//		{
//			cur = QueueTop(&qu);
//
//			printf(cur->_data);
//
//			if (cur->_right && !cur->_left)
//			{
//				return 0;
//			}
//
//			if (tag && (cur->_right || cur->_left))
//			{
//				return 0;
//			}
//
//			if (cur->_left)
//			{
//				QueuePush(&qu, cur->_left);
//			}
//
//			if (cur->_right)
//			{
//				QueuePush(&qu, cur->_right);
//			}
//			else
//			{
//				tag = 1;
//			}
//
//			QueuePop(&qu);
//		}
//
//		QueueDestory(&qu);
//		return 1;
//	}