#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};

bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL)
		return true;
	if (root->left && root->val != root->left->val)
	{
		return false;
	}
	if (root->right && root->val != root->right->val)
	{
		return false;
	}

	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

void invert(struct TreeNode* root,struct TreeNode* Pleft, struct TreeNode* Pright)
{
	root->left = Pright;
	root->right = Pleft;
}

struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL)
	{
		return root;
	}
	if (root->left == root->right && root->left == NULL)
	{
		return root;
	}
	invert(root,root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);

	return root;
}

bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	return left->val == right->val &&
		_isSymmetric(left->left, right->right) &&
		_isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;
	
	return isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}

void TreeSize(struct TreeNode* root, int* size)
{
	if (root == NULL)
		return;
	size++;
	TreeSize(root->left,size);
	TreeSize(root->right,size);
	return;
}

void _preorderTraversal(struct TreeNode* root, int* arr, int* i)
{
	if (root == NULL)
		return;
	arr[*i++] = root->val;
	_preorderTraversal(root->left, arr, i);
	_preorderTraversal(root->left, arr, i);

	return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int size = 0;
	TreeSize(root, &size);
	*returnSize = size;
	int *arr = (int*)malloc(sizeof(int) * size);
	int i = 0;
	_preorderTraversal(root, arr, &i);
	return arr;
}