#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include<math.h>

int TreeDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);

	if (abs(leftDepth - rightDepth) <= 1)
		return true;
	return false;

}