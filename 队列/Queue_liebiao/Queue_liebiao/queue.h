#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define TEST_HEADER printf("\n============%s============\n",__FUNCTION__)

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include <windows.h>

typedef int DataType;
typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;

typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = NULL;
	q->_pTail = NULL;
}

PNode QueueBuyNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	assert(pNewNode);
	pNewNode-> _pNext = NULL;
	pNewNode-> _data = data;

	return pNewNode;
}

void QueuePush(Queue* q, DataType data)
{
	assert(q);
	if (NULL == q->_pHead)
	{
		q->_pHead = q->_pTail = QueueBuyNode(data);
	}
	else
	{
		q->_pTail->_pNext = QueueBuyNode(data);
		q->_pTail = q->_pTail->_pNext;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (NULL == q->_pHead)
	{
		return;
	}
	else if (q->_pHead == q->_pTail)
	{
		free(q->_pHead);
		q->_pHead = q->_pTail = NULL;
	}
	else
	{
		/*PNode pPreTail = q->_pHead;
		while (pPreTail->_pNext != q->_pTail)
		{
			pPreTail = pPreTail->_pNext;
		}
		free(q->_pTail);
		q->_pTail = pPreTail;*/
		PNode pDel = q->_pHead;
		q->_pHead = pDel->_pNext;
		free(pDel);
	}
}

int QueueSize(Queue* q)
{
	int count = 0;
	PNode pCur;;
	assert(q);
	pCur = q->_pHead;

	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}

DataType QueueFront(Queue* q)
{
	assert(q && q->_pHead);
	return q->_pHead->_data;
}

DataType QueueBack(Queue* q)
{
	assert(q && q->_pHead);
	return q->_pTail->_data;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_pHead;
}

void QueueDestroy(Queue* q)
{
	PNode pCur = q->_pHead;
	while (pCur)
	{
		q->_pHead = pCur->_pNext;
		free(pCur);
		pCur = q->_pHead;
	}
	q->_pTail = NULL;
}

void TestQueue()
{
	TEST_HEADER;
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));

	QueuePush(&q, 2); 
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));

	QueueDestroy(&q);
}