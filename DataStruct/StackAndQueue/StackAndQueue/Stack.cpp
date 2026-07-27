#include <stdio.h>

struct SNode {
	int nData;
	SNode* pNext;
};

void push(int value);
int pop();
SNode* CreateNode(SNode* top, int data);
SNode* ListPop(SNode* top);
void ListStackMain();
void ArrayStackMain();

const int MAX_SIZE = 100;
int top = -1;
int stack[MAX_SIZE];

int main()
{
	ListStackMain();

	return 0;
}

void push(int value)
{
	if (top >= MAX_SIZE - 1) return;

	top++;
	stack[top] = value;
}

int pop()
{
	return stack[top--];
}

SNode* CreateNode(SNode* top, int data)
{
	SNode* pTemp = new SNode();
	pTemp->nData = data;
	if (top != NULL) pTemp->pNext = top;
	return pTemp;
}

SNode* ListPop(SNode* top)
{
	printf("%d\n", top->nData);
	return top->pNext;
}

void ListStackMain()
{
	SNode* pTop = NULL;

	pTop = CreateNode(pTop, 10);
	pTop = CreateNode(pTop, 20);
	pTop = CreateNode(pTop, 30);
	pTop = CreateNode(pTop, 40);
	pTop = CreateNode(pTop, 50);

	while (pTop != NULL)
	{
		pTop = ListPop(pTop);
	}
}

void ArrayStackMain()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	while (top >= 0)
	{
		int value = pop();
		printf("%d\n", value);
	}
}