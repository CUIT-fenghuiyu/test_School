#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// ̬
//#define N 100
//typedef int STDatatype;
//struct Stack
//{
//	STDatatype a[N];
//	int top;    
//};

typedef int STDatatype;
typedef struct Stack
{
	STDatatype* a;
	int top;		
	int capacity;
}Stack;

void StackInit(Stack* stack);
void StackDestroy(Stack* stack);
void StackPush(Stack* stack, STDatatype x);
void StackPop(Stack* stack);
bool StackEmpty(Stack* stack);
int StackSize(Stack* stack);
STDatatype StackTop(Stack* stack);