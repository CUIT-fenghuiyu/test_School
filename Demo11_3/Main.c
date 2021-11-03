#include <stdio.h>
#include <stdlib.h>

typedef struct _Tree
{
	int data;
	struct _Tree *lchild;
	struct _Tree *rchild;
} Tree, *pTree;

int CreateBiTree(pTree *bt);
int countX(pTree bt, int x);

int main(void)
{
	int count;
	int x;
	pTree BT = NULL;

	printf("Input:\n");
	CreateBiTree(&BT);
	printf("Input X:\n");
	scanf("%d", &x);
	count = countX(BT, x);
	printf("countX = %d\n", count);
	return 0;
}

int CreateBiTree(pTree *bt)
{
	//先根序递归创建二叉树
	//1,2,3,0,0,0,4,0,0，无孩子时输入0值
	pTree p;
	int data;
	scanf("%d", &data);
	if (data != 0)
	{
		p = (pTree)malloc(sizeof(Tree));
		p->lchild = p->rchild = NULL;
		p->data = data;
		(*bt) = p;
		CreateBiTree(&p->lchild);
		CreateBiTree(&p->rchild);
	}
	return 0;
}

/******start******/
void _countX(pTree bt, int x , int* pn)
{
	if(bt == NULL)
		return;

	if(bt->data == x)
		(*pn)++;
	
	_countX(bt->lchild, x, pn);
	_countX(bt->rchild, x, pn);
	
	return;
}
int countX(pTree bt, int x)
{
	int n = 0;
	_countX(bt, x, &n);

	return n;
}
/******end******/