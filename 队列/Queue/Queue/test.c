#define _CRT_SECURE_NO_WARNINGS 1

//笔记
//1.少用一个元素
//2.标记
//入元素--- rear ---> front
//出队列--- front ---> rear
//flag = 0  front == rear 空
//入元素--> rear++  flag = 1
//出队列--> front++ flag = 0
//3.计数器
//count = 0 空
//count = N 满
//Push Pop Empty
#pragma once
#include<stdio.h>
#include <windows.h>
#include <assert.h>

#define MAX_SIZE 8
typedef int DataType;

typedef struct Queue
{
	DataType _arrzy[MAX_SIZE];
	int _front;
	int _back;
	int _count;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = 0;
	q->_count = 0;
}

void QueuePush(Queue* q, DataType data)
{
	assert(q);
	if (MAX_SIZE == q->_count)
	{
		printf("队列已满");
		return;
	}
	q->_arrzy[q->_back++] = data;
	if (q->_back == MAX_SIZE)
	{
		q->_back = 0;
	}
	q->_count++;
}
void QueuePop(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		printf("队列已空，无法出队列！\n");
		return;
	}
	++(q->_front);
	if (q->_front == MAX_SIZE)
	{
		q->_front = 0;
	}
	q->_count--;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return 0 == q->_count;
}
int QueueSize(Queue* q)
{
	return q->_count;
}
DataType QueueFront(Queue* q)
{
	return q->_arrzy[q->_front];
}
DataType QueueBack(Queue* q)
{
	//return q->_array[(q->_back-1+MAX_SIZE]%MAX_SIAE];

	if (0 != q->_back)
	{
		return q->_arrzy[q->_back - 1];
	}
	else
	{
		return q->_arrzy[MAX_SIZE];
	}
}

void TeatQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));

	QueuePop(&q);
	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
}

int main()
{
	TeatQueue();
	system("pause");
	return 0;
}
