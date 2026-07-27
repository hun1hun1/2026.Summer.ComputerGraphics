#include <stdio.h>

struct SNode {
	int nData;
	SNode* pNext;
};

void EnQueue(int value);
int DeQueue();

SNode* CreateNode(SNode* pNode, int data); //노드를 생성하여 리턴한다.
SNode* FindNodeData(SNode* pStart, int data); //해당 데이터를 가진 노드를 찾는다.
SNode* InsertNodeData(SNode* pStart, int data, int insert); //해당 데이터를 가진 노드 뒤에 노드를 추가한다.
void DeleteNodeData(SNode* pStart, int del); //해당데이터를 가진 노드를 삭제한다.
void PrintLinkedList(SNode* pStart); //노드를 순회하며 끝날때까지 출력한다.
void DeleteLinkedList(SNode* pStart); //노드를 순회하며 모든데이터를 삭제한다.
int ListDeQueue(SNode* pNode);

void ArrayQueueMain();
void ListQueueMain();

const int MAX_SIZE = 100;
int rear = -1;
int front = -1;
int queue[MAX_SIZE];

int main()
{
	ArrayQueueMain();
	ListQueueMain();

	return 0;
}

void EnQueue(int value)
{
	if (front == MAX_SIZE - 1) return;

	queue[++front] = value;
}

int DeQueue()
{
	if (front == rear) return -1;
	return queue[++rear];
}

SNode* CreateNode(SNode* pNode, int data)
{
	SNode* pTemp = NULL;

	pTemp = new SNode();
	pTemp->nData = data;
	pTemp->pNext = NULL;
	if (pNode != NULL) pNode->pNext = pTemp;

	return  pTemp;
}

SNode* FindNodeData(SNode* pStart, int data)
{
	SNode* pNode = pStart;
	while (pNode)
	{
		if (pNode->nData == data)
		{
			return pNode;
		}

		pNode = pNode->pNext;
	}

	return pNode;
}

SNode* InsertNodeData(SNode* pStart, int data, int insert)
{
	SNode* pNode = pStart;
	SNode* pInsert = NULL;

	pNode = FindNodeData(pStart, data);

	pInsert = CreateNode(pInsert, insert);
	pInsert->pNext = pNode->pNext;
	pNode->pNext = pInsert;
	while (pNode->pNext) pNode = pNode->pNext;
	return pNode;
}

void DeleteNodeData(SNode* pStart, int del)
{
	SNode* pPre = NULL;
	SNode* pNode = pStart;

	while (pNode->pNext)
	{
		if (pNode->pNext->nData == del)
		{
			pPre = pNode;
			pNode = pNode->pNext;
			pPre->pNext = pNode->pNext;
			delete pNode;
			return;
		}

		pNode = pNode->pNext;
	}
}

void PrintLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	printf("data:");
	while (pNode)
	{
		printf("%d", pNode->nData);
		pNode = pNode->pNext;

		if (pNode != NULL)
			printf(",");
	}
	printf("\n");
}

void DeleteLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	SNode* pDel = NULL;

	while (pNode)
	{
		pDel = pNode;
		pNode = pNode->pNext;
		delete pDel;
	}
}

void ArrayQueueMain()
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
}

void ListQueueMain()
{
	SNode* pRear = NULL;
	SNode* pFront = NULL;

	pFront = CreateNode(pFront, 10);
	pRear = pFront;

	pFront = CreateNode(pFront, 20);
	pFront = CreateNode(pFront, 30);
	pFront = CreateNode(pFront, 40);
	pFront = CreateNode(pFront, 50);

	while (pRear != pFront)
	{
		printf("%d\n", pRear->nData);
		SNode* pDel = pRear;
		pRear = pRear->pNext;
		delete pDel;
	}
	printf("%d\n", pRear->nData);
	delete pRear;
}
