#pragma once

#include "Stack.h"
#define TEST_HEADER printf("\n============%s============\n",__FUNCTION__)
//////////////////////////////
//1
//////////////////////////////
typedef struct MinStack
{
	Stack _st;
	Stack _minst;
}MinStack;

void MinStackInit(MinStack* mst)
{
	assert(mst);
	StackInit(&(mst->_minst));
	StackInit(&(mst->_st));
}

void MinStackPushAd(MinStack* mst, DataType x)
{
	assert(mst);
	StackPush(&(mst->_st), x);
	if (StackSize(&(mst->_minst)) == 0 ||
		StackTop(&(mst->_minst)) >= x)
	{
		StackPush(&(mst->_minst), StackTop(&(mst->_st)));
	}
}

void MinStackPush(MinStack* mst, DataType x)
{
	assert(mst);
	StackPush(&(mst->_st), x);
	if (StackSize(&(mst->_minst)) == 0 ||
		StackTop(&(mst->_minst)) > x)
	{
		StackPush(&(mst->_minst), StackTop(&(mst->_st)));
	}
	else
	{
		StackPush(&(mst->_minst), StackTop(&(mst->_minst)));
	}
}

void MinStackPopAd(MinStack* mst)
{
	DataType x;
	DataType min;
	assert(mst);
	x = MinStackTop(&(mst->_st));
	min = MinStackTop(&(mst->_minst));
	StackPop(&(mst->_st));
	if (x == min)
	{
		StackPop(&(mst->_minst));
	}
}

void MinStackPop(MinStack* mst)
{
	assert(mst);
	StackPop(&(mst->_st));
	StackPop(&(mst->_minst));
}
DataType MinStackTop(MinStack* mst)
{
	assert(mst);
	return StackTop(&(mst->_st));
}

DataType MinStackMin(MinStack* mst)
{
	assert(mst);
	return StackTop(&(mst->_minst));
}

int MinStackEmpty(MinStack* mst)
{
	assert(mst);
	return StackEmpty(&(mst->_st));
}

int MinStackSize(MinStack* mst)
{
	assert(mst);
	return StackSize(&(mst->_st));
}

void TestMinStack()
{
	TEST_HEADER;
	MinStack mst;
	MinStackInit(&mst);
	MinStackPush(&mst, 5);
	MinStackPush(&mst, 3);
	MinStackPush(&mst, 6);
	MinStackPush(&mst, 7);
	MinStackPush(&mst, 8);
	MinStackPush(&mst, 0);
	MinStackPush(&mst, 9);
	while (!MinStackEmpty(&mst))
	{
		DataType top = MinStackTop(&mst);
		DataType min = MinStackMin(&mst);
		printf("top=%d min=%d\n",top, min);
		MinStackPop(&mst);
	}
}

void TestMinStackAd()
{
	TEST_HEADER;
	MinStack mst;
	MinStackInit(&mst);
	MinStackPushAd(&mst, 5);
	MinStackPushAd(&mst, 3);
	MinStackPushAd(&mst, 6);
	MinStackPushAd(&mst, 7);
	MinStackPushAd(&mst, 8);
	MinStackPushAd(&mst, 0);
	MinStackPushAd(&mst, 9);
	while (MinStackSize(&mst) != 0)
	{
		DataType top = MinStackTop(&mst);
		DataType min = MinStackMin(&mst);
		printf("top=%d min=%d\n", top, min);
		MinStackPopAd(&mst);
	}
}

//////////////////////////////
//2
//////////////////////////////
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* q)
{
	assert(q);
	StackInit(&q->s1);
	StackInit(&q->s2);
}

void QueueByTwoStackPush(QueueByTwoStack* q, DataType x)
{
	assert(q);
	StackPush(&(q->s1), x);
}

void QueueByTwoStackPop(QueueByTwoStack* q)
{
	assert(q);
	if (StackSize(&(q->s2)) == 0)
	{
		while (StackSize(&(q->s1)) != 0)
		{
			StackPush(&(q->s2), StackTop(&(q->s1)));
			StackPop(&(q->s1));
		}
	}
	StackPop(&(q->s2));
}

int QueueByTwoStackEmpty(QueueByTwoStack* q)
{
	assert(q);
	
	return StackEmpty(&(q->s1)) + StackEmpty(&(q->s2));
}

int QueueByTwoStackSize(QueueByTwoStack* q)
{
	assert(q);
	return StackSize(&(q->s1)) + StackSize(&(q->s2));
}

DataType QueueByTwoStackFront(QueueByTwoStack* q)
{
	assert(q);
	if (StackSize(&(q->s2)) == 0)
	{
		while (StackSize(&(q->s1)) != 0)
		{
			StackPush(&(q->s2), StackTop(&(q->s1)));
			StackPop(&(q->s1));
		}
	}
	return StackTop(&(q->s2));
}

void TestQueueByTwoStack()
{
	TEST_HEADER;
	QueueByTwoStack q;
	QueueByTwoStackInit(&q);
	QueueByTwoStackPush(&q, 1);
	QueueByTwoStackPush(&q, 2);
	QueueByTwoStackPush(&q, 3);
	QueueByTwoStackPush(&q, 4);

	while (QueueByTwoStackSize(&q))
	{
		printf("%d ", QueueByTwoStackFront(&q));
		QueueByTwoStackPop(&q);
	}
	printf("\n");
}


//////////////////////////////
//3
//////////////////////////////
//
//typedef struct StackByTwoQueue
//{
//	Queue q1;
//	Queue q2;
//}StackByTwoQueue;
//
//void StackByTwoQueueInit(StackByTwoQueue* s)
//{
//	assert(s);
//	QueueInit(&s->q1);
//	QueueInit(&s->q2);
//}
//
//void StackByTwoQueuePush(StackByTwoQueue* s, DataType x)
//{
//	assert(s);
//	StackPush(&(s->q1), x);
//}
//
//void StackByTwoQueuePop(StackByTwoQueue* s)
//{
//	assert(s);
//	if (StackSize(&(s->q2)) == 0)
//	{
//		while (StackSize(&(s->q1)) != 0)
//		{
//			StackPush(&(s->q2), StackTop(&(s->q1)));
//			StackPop(&(s->q1));
//		}
//	}
//	StackPop(&(s->q2));
//}
//
//int StackByTwoQueueEmpty(StackByTwoQueue* s)
//{
//	assert(s);
//
//	return StackEmpty(&(s->q1)) + StackEmpty(&(s->q2));
//}
//
//int StackByTwoQueueSize(StackByTwoQueue* s)
//{
//	assert(s);
//	return StackSize(&(s->q1)) + StackSize(&(s->q2));
//}
//
//DataType StackByTwoQueueFront(StackByTwoQueue* s)
//{
//	assert(s);
//	if (StackSize(&(s->q2)) == 0)
//	{
//		while (StackSize(&(s->q1)) != 0)
//		{
//			StackPush(&(s->q2), StackTop(&(s->q1)));
//			StackPop(&(s->q1));
//		}
//	}
//	return StackTop(&(s->q2));
//}

//////////////////////////////
//4
//////////////////////////////
int IsInvalidStackOrder(int* in, int* out, int in_size)
{
	Stack s;
	int in_index = 0, out_index = 0;	
	StackInit(&s);
	while (in_index < in_size)
	{
		if (in[in_index] == out[out_index])
		{
			in_index++;
			out_index++;
		}
		else
		{
			StackPush(&s, in[in_index]);
			in_index++;
		}
	}
	while (StackSize(&s) != 0)
	{
		if (StackTop(&s, in[in_index]) == out[out_index])
		{
			StackPop(&s);
			out_index++;
		}
		else
		{
			printf("不匹配！！！\n");
			return 0;
		}
	}
	printf("匹配！！！\n");
	return 1;
}

int IsInvalidStackOrderAd(int* in, int* out, int in_size)
{
	Stack s;
	int in_index = 0, out_index = 0;
	StackInit(&s);
	while (in_index < in_size)
	{
		if (in[in_index] == out[out_index])
		{
			in_index++;
			out_index++;
		}
		else
		{
			StackPush(&s, in[in_index]);
			in_index++;
		}
	}
	while (StackSize(&s) != 0)
	{
		if (StackTop(&s, in[in_index]) == out[out_index])
		{
			StackPop(&s);
			out_index++;
		}
		else
		{
			printf("不匹配！！！\n");
			return 0;
		}
	}
	printf("匹配！！！\n");
	return 1;
}


void TestIsInvalidStackOrder()
{
	int in_size;
	int in[5] = { 1, 2, 3, 4, 5 };
	int out[5] = { 3, 5, 4, 2, 1 };
	in_size = sizeof(in) / sizeof(in[0]);
	IsInvalidStackOrder(in, out, in_size);
}

//////////////////////////////
//5
//////////////////////////////
#pragma once
#define N 10
#include <assert.h>
typedef struct TwoStack
{
	DataType* _a[N];
	size_t top1;
	size_t top2;
	
}TwoStack;

void TwoStackInit(TwoStack* s)
{
	assert(s);
	s->top1 = 0;
	s->top2 = N-1;
}

void TwoStackPush(TwoStack* s, int which, int data)
{
	assert(s);
	if (1 == which)
	{
		s->_a[s->top1] = 1;
		s->top1 += 1;
	}
	else if (2 == which)
	{
		s->_a[s->top2] = data;
		s->top2 -= 1;
	}
	else
	{
		printf("输入错误！！！\n");
		return;
	}
}



//void _TwoStackPush(TwoStack* s, DataType data)
//{
//Part1:
//	printf("=============菜单=============\n");
//	printf("\t1.向第一个栈插入元素\n");
//	printf("\t2.向第一个栈插入元素");
//	printf("\t请选择:");
//	int which;
//	scanf("%d", &which);
//	if (1 == which)
//	{
//		s->_a[s->top1] = data;
//		s->top1 += 2;
//	}
//	else if (2 == which)
//	{
//		s->_a[s->top2] = data;
//		s->top2 += 2;
//	}
//	else
//	{
//		printf("输入错误！！！\n");
//		goto Part1;
//	}
//}

//void TwoStackPop(TwoStack* s, int which)
//{
//
//}
//
int TwoStackSize(TwoStack* s, int which)
{
	assert(s);
	return s->top1 + s->top2;
}

//int TwoStackEmpty(TwoStack* s, int which)
//{
//
//}
//
//DataType TwoStackTop(TwoStack* s, int which)
//{
//
//}

//void Test()
//{
//	int i = 0;
//	TwoStack* s;
//	TwoStackInit(&s);
//	TwoStackPush(&s, 1, 1);
//	TwoStackPush(&s, 2, 1);
//	TwoStackPush(&s, 1, 2);
//	for (; i < 3; i++)
//		printf("%d", s->_a[i]);
// }