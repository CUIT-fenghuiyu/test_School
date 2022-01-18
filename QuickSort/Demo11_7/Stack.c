#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void StackInit(Stack* pstack)
{
	assert(pstack);
	pstack->a = NULL;
	pstack->top = 0;
	pstack->capacity = 0;
}
void StackDestroy(Stack* pstack)
{
	//参数校验
	assert(pstack);

	if(pstack->a != NULL)
	{
		free(pstack->a);
	}

	pstack->a = NULL;
	pstack->top = 0;
	pstack->capacity = 0;
}
void StackPush(Stack* pstack, STDatatype x)
{
	assert(pstack);

	if (pstack->top == pstack->capacity)
	{
		int newcapacity;
		newcapacity = pstack->capacity == 0 ? 4 : pstack->capacity * 2;
		pstack->capacity = newcapacity;
		int * tmp = pstack->a;
		pstack->a = realloc(tmp, newcapacity * sizeof(Stack));
	}
	pstack->a[pstack->top] = x;
	pstack->top++;
}
void StackPop(Stack* pstack)
{
	assert(pstack);
	assert(!StackEmpty(pstack));

	pstack->top--;
}
bool StackEmpty(Stack* pstack)
{
	assert(pstack);

	return pstack->top == 0;
}
int StackSize(Stack* pstack)
{
	assert(pstack);

	return pstack->top;
}
STDatatype StackTop(Stack* pstack)
{
	assert(pstack);
	assert(!StackEmpty(pstack));

	return pstack->a[pstack->top - 1];
}