#include <stdio.h>

void push(int value);
int pop();

const int MAX_SIZE = 100;
int top = -1;
int stack[MAX_SIZE];

int main()
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
