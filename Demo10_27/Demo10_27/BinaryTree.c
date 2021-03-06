#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode('A');
	BTNode* node2 = BuyNode('B');
	BTNode* node3 = BuyNode('C');
	BTNode* node4 = BuyNode('D');
	BTNode* node5 = BuyNode('E');
	BTNode* node6 = BuyNode('F');

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node3->left = node5;
	node3->right = node6;
	return node1;

}

void PreOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	else
		printf("%c ", root->data);
	
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	else
	{
		InOrder(root->left);
		printf("%c ", root->data);
		InOrder(root->right);
	}

}

void PostOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	else
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c ", root->data);
	}
}

int BinaryTreeSize(BTNode* root)
{
	return NULL == root? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root, k - 1) + BinaryTreeLevelKSize(root, k - 1);
}

int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	int LeftDepth = BinaryTreeDepth(root->left);
	int RightDepth = BinaryTreeDepth(root->right);

	return LeftDepth > RightDepth ? LeftDepth + 1 : RightDepth + 1;
}

BTNode* BinaryTreFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		printf("Find it\n");
		return root;
	}

	BTNode* retleft = BinaryTreFind(root->left, x);
	if (retleft)
	{
		return retleft;
	}
	BTNode* retright = BinaryTreFind(root->right, x);
	if (retright)
	{
		return retright;
	}
	return NULL;

}

int main()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	printf("%d",BinaryTreeLeafSize(root));
	printf("\n");
	printf("%d", BinaryTreeDepth(root));
	printf("\n");
	BTNode* ret = BinaryTreFind(root, 'F');
	printf("%c",ret->data);
	return 0;
}