#define _CRT_SECURE_NO_WARNINGS 1
/*
	�����ڱ�׼C�� ��̬����汾���ⲻ��static����˼������data[]����д����
	SeqList.c
	V1.0
	2019.9.9 wangx
	����ĺ�����Ϊ��ҵ����ͬѧ��ȥ��ɣ�
*/
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 10000  // ʵ�ʹ�ҵ����У�������ֻ�ܴ󣡣�

typedef struct
{
	// ��Ϊ����˳���ܴ�10000ֻ�ǽ�ѧ�������������������к����ڴ���ʱ�����Ҫ���������鴫ָ�룬ֱ�����ԭ�����в����������鴫�ṹ����������׻��ջ���ű���
	// �����int *pdata; ������д������pdataֻ��4���ֽڣ�SeqList�ṹ������Ŀռ��������С���ͻ᷽��ܶ࣬���ͱ�ɶ�̬�����ˣ���Ҫ�ڶ����п��ٿռ����洢���ݣ�
	int data[INIT_SIZE];  // 10000��Ԫ�أ�40000���ֽڡ�
	int length;           // 4���ֽ�
	int listsize;         // 4���ֽ�
}SeqList;

SeqList InitList()
{
	SeqList tt;
	tt.length = 0;
	tt.listsize = INIT_SIZE;
	//tt.data[3] = ;
	return tt;				// �Ѿֲ��Ľṹ�����tt���������帳ֵ�������Ľ����ߣ�tt�ں�������Ҳ���帴���˹�ȥ��tt��return���ͷš�
}

// ��Ϊ˳�����ͨ�����ν����ģ����ڲ������ڲ�������лᱻ�޸ģ����Դ˴��β�Ӧ����Ϊָ�룬ȥ����main�����ж�Ӧ��ʵ��list1
// �����һ��������ΪSeqList��������SeqList *����pL�Ͳ�����һ��ָ�룬�������ջ���е�һ���ṹ�������408���ֽڣ����������޸Ĳ�����������Ӱ�쵽list1
// �����У�i��ʾ�±�λ�ã���0��ʼ��ŵġ����Ҫ��1��ʼ��ţ�������붼��Ҫ΢��
int listInsert(SeqList *pL, int i, int value)
{
	int j;
	// 3.����У��
	if (i > pL->length || i < 0 || pL == NULL)
		return -1;  // �������󣬷��ش����� -1
	// 4.���Ǽ������
	if (pL->length >= pL->listsize)
		return -2;  // �������������磬���ش����� -2 ����̬����汾�����Ա�û�����б�ռ����䣬��һ�����ָ������ʾ�Ķ�̬����汾�Ĳ�һ����
	// 5.�����ڲŴ�������·
	for (j = pL->length; j > i; j--)
		pL->data[j] = pL->data[j - 1];

	pL->data[j] = value;
	pL->length++;  // ���ǧ������ˣ�
	return 0;
}

// ��������Ȼû�иı����Ա�ʵ�Σ�������Ϊ���Ա�ʵ����̫���ˣ�Ϊ��ʡջ�ռ䣬���Ч�ʣ�������ָ��������ԭ���������ǲ���ջ���еĽṹ�������ӡ��
int getValue(SeqList *pL, int i)
{
	// 3. ����У��
	if (i<0 || i> pL->length - 1 || pL == NULL)
		return -1;
	// 4. ���Ǽ��������������û�м����������д
	// 5. ������·��˳��洢�ṹ����ֱ����ȡ��i��Ԫ�أ��ܼ򵥣���һ�仰
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

// ɾ��ֵΪx��Ԫ��
int Erase_by_value(SeqList *PL, int x)
{
	//����У��
	if (PL == NULL)
		return -1;//-1�������������
	int begin_length = PL->length;
	int i;
	for (i = 0; i < PL->length; i++)
	{
		//���ҵ�Xʱ��������Ԫ����ǰŲ����������һ��Ԫ�ص���X��ֱ��PL->length--
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
		return -2;//ɾ��ʧ��
	else
		return 0;//ɾ���ɹ�����������
}


// ɾ����i��Ԫ�أ�i��0��ʼ��ţ�
int Erase_by_location(SeqList* PL, int location)
{
	//����У��
	if (PL == NULL || location < 0 || location >= PL->length)
		return -1;//�����������
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

// ���ر�
int length_of_SeqList(SeqList *PL)
{
	//����У��
	if (PL == NULL)
		return -1;

	return PL->length;
}

// �ϲ������(��Ϊ��̬����汾��������ռ䣬������Ҫ�ȼ���AB������Ч���ݸ��������ܳ���INIT_SIZE������ֻ�ܰչ�)
SeqList* Merge_SeqList(SeqList *PL1, SeqList *PL2)
{
	//����У��
	if (PL1 == NULL || PL2 == NULL || PL1->length + PL2->length > INIT_SIZE)
		return NULL;
	SeqList* newList = (SeqList*)malloc(sizeof(SeqList));
	*newList = InitList();

	int i, j, k;
	//��PL1�����е�������ֲ��newList����
	for (i = 0; i < PL1->length; i++)
	{
		newList->data[i] = PL1->data[i];
		newList->length++;
	}

	//��PL2�����е�������ֲ��newList����
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
	listInsert(&list1, 2, 40);    // ��һ������������д��Ҳ����ȫ���Եģ�
	listInsert(&list1, 2, 30);
	listInsert(&list1, 0, 5);             // ͷ��
	listInsert(&list1, list1.length, 50); // β��
	printAll(&list1);
	printf("\n");

	listInsert(&list2, 0, 10);
	listInsert(&list2, 1, 20);
	listInsert(&list2, 2, 40);    // ��һ������������д��Ҳ����ȫ���Եģ�
	listInsert(&list2, 2, 30);
	listInsert(&list2, 0, 5);             // ͷ��
	listInsert(&list2, list2.length, 50);
	printAll(&list2);
	printf("\n");

	SeqList* newList = Merge_SeqList(plist1, plist2);
	printAll(newList);
	printf("\n");

	return 0;
}
