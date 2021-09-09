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

void SQLinit(SQL* psql);//初始化顺序表
void SQLdestroy(SQL* psql);//删除顺序表
void SQLCheckCapacity(SQL* psql);//检查空间大小
void SQLPrint(SQL* psql);//打印顺序表
void SQLPushfront(SQL* psql, SQLDataType fate);//头插数据
void SQLPushBack(SQL* psql, SQLDataType fate);//尾插数据
void SQLPopfront(SQL* psql);//头删数据
void SQLPopBack(SQL* psql);//尾删数据