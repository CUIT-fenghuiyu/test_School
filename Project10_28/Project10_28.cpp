#include<stdio.h>
#include<assert.h>
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

typedef struct StackNode
{
	BTNode* Bnode;
	struct StackNode* Next;
}Node;

typedef struct LinkStack
{
	Node* Top;
}Stack;

void StakInit(Stack** Pst)
{
	(*Pst) = (Stack*)malloc(sizeof(Stack));
	(*Pst)->Top = NULL;
}

void StackPush(Stack* st, BTNode* Bnode)
{
	Node* x = (Node*)malloc(sizeof(Node));
	x->Bnode = Bnode;
	x->Next = st->Top;
	st->Top = x;
}

BTNode* StackPop(Stack* st)
{
	Node* tmp;
	BTNode* Btmp;
	tmp = st->Top;
	Btmp = tmp->Bnode;
	st->Top = tmp->Next;
	free(tmp);

	return Btmp;
}

int StackEmpety(Stack* st)
{
	return st->Top == NULL ? 1 : 0;
}

int main()
{
	BTNode* root = CreatBinaryTree();
	Stack* ST;
	StakInit(&ST);
	BTNode* p = root;
	while(1)
	{
		if(p == NULL)
		{
			printf("NULL ");
			if(StackEmpety(ST) == 1)
			{
				printf("\n");
				return 0;
			}
			p = StackPop(ST);
			p = p->right;
		}
		else
		{
			printf("%c ",p->data);
			StackPush(ST,p);
			p = p->left;
		}
	}

	return 0;
}