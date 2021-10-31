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

bool isSymmetric(struct TreeNode* root) {

}