#include <stdio.h>

void EnQueue(int value);
int DeQueue();

const int MAX_SIZE = 100;
int rear = -1;
int front = -1;
int queue[MAX_SIZE];

int main()
{
	EnQueue(10);
	EnQueue(20);
	EnQueue(30);
	EnQueue(40);
	EnQueue(50);

	while (rear != front)
	{
		printf("%d\n", DeQueue());
	}

	return 0;
}

void EnQueue(int value)
{
	if (rear == MAX_SIZE - 1) return;

	queue[++front] = value;
}

int DeQueue()
{
	if (front == rear) return -1;
	return queue[++rear];
}