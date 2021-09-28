#define _CRT_SECURE_NO_WARNINGS 1
/*
	适用于标准C， 静态数组版本（这不是static的意思，而是data[]这种写法）
	SeqList.c
	V1.0
	2019.9.9 wangx
	后面的函数作为作业，让同学们去完成！
*/
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 10000  // 实际工业编程中，这个数字会很大！！

typedef struct
{
	// 因为线性顺序表很大（10000只是教学范例），所以下面所有函数在传参时，如果要传表，都建议传指针，直接针对原件进行操作！不建议传结构体变量（容易会把栈区撑爆）
	// 如果是int *pdata; 这样的写法，则pdata只有4个字节，SeqList结构体变量的空间量大大缩小，就会方便很多，但就变成动态数组了（需要在堆区中开辟空间来存储数据）
	int data[INIT_SIZE];  // 10000个元素，40000个字节。
	int length;           // 4个字节
	int listsize;         // 4个字节
}SeqList;

SeqList InitList()
{
	SeqList tt;
	tt.length = 0;
	tt.listsize = INIT_SIZE;
	//tt.data[3] = ;
	return tt;				// 把局部的结构体变量tt的内容整体赋值给函数的接收者，tt内含的数组也整体复制了过去。tt在return后被释放。
}

// 因为顺序表是通过传参进来的，其内部数据在插入操作中会被修改，所以此处形参应该设为指针，去操作main函数中对应的实参list1
// 如果第一个参数设为SeqList，而不是SeqList *，则pL就不再是一个指针，而变成了栈区中的一个结构体变量（408个字节），对它的修改操作根本不会影响到list1
// 本例中，i表示下标位置，从0开始编号的。如果要从1开始编号，下面代码都需要微调
int listInsert(SeqList *pL, int i, int value)
{
	int j;
	// 3.参数校验
	if (i > pL->length || i < 0 || pL == NULL)
		return -1;  // 参数有误，返回错误码 -1
	// 4.考虑极端情况
	if (pL->length >= pL->listsize)
		return -2;  // 表满，出现上溢，返回错误码 -2 （静态数组版本的线性表，没法进行表空间扩充，这一点和用指针来表示的动态数组版本的不一样）
	// 5.到现在才处理常规套路
	for (j = pL->length; j > i; j--)
		pL->data[j] = pL->data[j - 1];

	pL->data[j] = value;
	pL->length++;  // 这句千万别忘了！
	return 0;
}

// 本函数虽然没有改变线性表实参，但是因为线性表实在是太大了，为节省栈空间，提高效率，建议用指针来操作原件，而不是操作栈区中的结构体变量复印件
int getValue(SeqList *pL, int i)
{
	// 3. 参数校验
	if (i<0 || i> pL->length - 1 || pL == NULL)
		return -1;
	// 4. 考虑极端情况，本函数没有极端情况，不写
	// 5. 常规套路，顺序存储结构可以直接提取第i个元素，很简单，就一句话
	return pL->data[i];
}

void printAll(SeqList *pL)
{
	int i;
	if (pL == NULL)
		return;
	for (i = 0; i < pL->length; i++)
		printf("%d  ", getValue(pL, i));
	return;
}

// 删除值为x的元素
int Erase_by_value(SeqList *PL, int x)
{
	//参数校验
	if (PL == NULL)
		return -1;//-1：传入参数有误
	int begin_length = PL->length;
	int i;
	for (i = 0; i < PL->length; i++)
	{
		//当找到X时，将后面元素向前挪动，如果最后一个元素等于X，直接PL->length--
		while (x == PL->data[i] && i <= PL->length-1)
		{
			int j;
			for (j = i; j < PL->length - 1; j++)
			{
				PL->data[j] = PL->data[j + 1];
			}
			PL->length--;
		}
	}
	if (i == begin_length)
		return -2;//删除失败
	else
		return 0;//删除成功，正常返回
}


// 删除第i个元素（i从0开始编号）
int Erase_by_location(SeqList* PL, int location)
{
	//参数校验
	if (PL == NULL || location < 0 || location >= PL->length)
		return -1;//传入参数有误
	if (location == PL->length - 1)
	{
		PL->length--;
		return 0;
	}
	int i;
	for (i = location; i < PL->length - 1; i++)
	{
		PL->data[i] = PL->data[i + 1];
	}
	PL->length--;

	return 0;

}

// 返回表长
int length_of_SeqList(SeqList *PL)
{
	//参数校验
	if (PL == NULL)
		return -1;

	return PL->length;
}

// 合并无序表(因为静态数组版本不能扩充空间，所以需要先检验AB两表有效数据个数，不能超过INIT_SIZE，否则只能罢工)
SeqList* Merge_SeqList(SeqList *PL1, SeqList *PL2)
{
	//参数校验
	if (PL1 == NULL || PL2 == NULL || PL1->length + PL2->length > INIT_SIZE)
		return NULL;
	SeqList* newList = (SeqList*)malloc(sizeof(SeqList));
	*newList = InitList();

	int i, j, k;
	//将PL1链表中的数据移植给newList链表
	for (i = 0; i < PL1->length; i++)
	{
		newList->data[i] = PL1->data[i];
		newList->length++;
	}

	//将PL2链表中的数据移植给newList链表
	for (j = i, k = 0; k < PL2->length; j++,k++)
	{
		newList->data[j] = PL2->data[k];
		newList->length++;
	}

	return newList;
	
}


int main()
{
	SeqList list1, list2;
	SeqList *plist1, *plist2;
	plist1 = &list1;
	plist2 = &list2;
	list1 = InitList();
	list2 = InitList();
	listInsert(&list1, 0, 10);
	listInsert(&list1, 1, 20);
	listInsert(&list1, 2, 40);    // 第一个参数，这种写法也是完全可以的！
	listInsert(&list1, 2, 30);
	listInsert(&list1, 0, 5);             // 头插
	listInsert(&list1, list1.length, 50); // 尾插
	printAll(&list1);
	printf("\n");

	listInsert(&list2, 0, 10);
	listInsert(&list2, 1, 20);
	listInsert(&list2, 2, 40);    // 第一个参数，这种写法也是完全可以的！
	listInsert(&list2, 2, 30);
	listInsert(&list2, 0, 5);             // 头插
	listInsert(&list2, list2.length, 50);
	printAll(&list2);
	printf("\n");

	SeqList* newList = Merge_SeqList(plist1, plist2);
	printAll(newList);
	printf("\n");

	return 0;
}
