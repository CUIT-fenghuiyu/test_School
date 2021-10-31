#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* preTree(char* pstr, int* pi)
{
	if (pstr[*pi] == ' ')
	{
		(*pi)++;
		return NULL;
	}
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = pstr[(*pi)++];
	root->left = preTree(pstr,pi);
	root->right = preTree(pstr,pi);

	return root;
}

void InorderTree(struct TreeNode* root)
{
	if (root == NULL)
		return;
	InorderTree(root->left);
	printf("%c", root->val);
	InorderTree(root->right);

}

int main()
{
	char str[100];
	gets(str);
	int i = 0;
	struct TreeNode* root = preTree(str,&i);
	InorderTree(root);
}