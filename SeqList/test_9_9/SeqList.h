#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SQLDataType;

typedef struct SeqList
{
	SQLDataType* arrary;
	size_t size;
	size_t capacity;
}SQL;

void SQLinit(SQL* psql);//��ʼ��˳���
void SQLdestroy(SQL* psql);//ɾ��˳���
void SQLCheckCapacity(SQL* psql);//���ռ��С
void SQLPrint(SQL* psql);//��ӡ˳���
void SQLPushfront(SQL* psql, SQLDataType fate);//ͷ������
void SQLPushBack(SQL* psql, SQLDataType fate);//β������
void SQLPopfront(SQL* psql);//ͷɾ����
void SQLPopBack(SQL* psql);//βɾ����