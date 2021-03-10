#define _CRT_SECURE_NO_WARNINGS 1

#define ROWS 20
#define COLS 20
#define CIR_  1
#define SIDE  30
#define QSIZE 6

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<conio.h>

typedef int SElemtype;

typedef struct QNode
{
	SElemtype data;
	struct QNode* next;
}QNode,*QueuePrt;

typedef struct LinkQueue
{
	QueuePrt front;
	QueuePrt rear;
}LinkQueue;

LinkQueue Q;

void Initqueue()
{
	Q.front = Q.rear = (QueuePrt)malloc(sizeof(QNode));
	if (!Q.front)
	{
		perror("队列初始化失败!");
		return;
	}
	Q.front->next = NULL;
}

void Destroyqueue()
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

void InserElement(SElemtype e)
{
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	if (!p)
	{
		perror("队列初始化失败!");
		return;
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

SElemtype PopElement()
{
	if (Q.front == Q.rear)
	{
		perror("空队!");
		return ERROR;
	}
	QNode* p = Q.front->next;
	SElemtype e = p->data;
	Q.front->next = p->next;
	if (p == Q.rear)
		Q.rear = Q.front;
	free(p);
	p = NULL;
	return e;
}

int main()
{
	Initqueue();
	InserElement(1);
	Destroyqueue();
	Initqueue();
	InserElement(2);
	InserElement(3);
	PopElement();
	PopElement();
	PopElement();
	return 0;
}


////顺序队
//typedef struct SqQueue
//{
//	SElemtype* base;
//	int front;//队头
//	int rear;//队尾
//	int Queuesize;//队的大小
//}SqQueue;
//
//SqQueue Q;
//
//void Createqueue()
//{
//	Q.base = (SElemtype*)malloc(sizeof(SqQueue)*QSIZE);
//	if (!Q.base)
//	{
//		perror("队申请失败");
//		return;
//	}
//	Q.front = Q.rear = 0;
//	Q.Queuesize = QSIZE;
//}
//
//void InserElement(SElemtype e)
//{
//	//判断队满
//	if ((Q.rear + 1) % Q.Queuesize == Q.front)
//	{
//		perror("队满!");
//		return;
//	}
//	Q.base[Q.rear] = e;
//	Q.rear = (Q.rear + 1) % Q.Queuesize;
//}
//
//SElemtype DeleteElement()
//{
//	//判断队空
//	if (Q.front == Q.rear)
//	{
//		perror("队空!");
//		return ERROR;
//	}
//	int ptemp = Q.front;
//	Q.front = (Q.front + 1) % Q.Queuesize;
//	return Q.base[ptemp];
//}
//
////计算队内元素个数
//int CountQueue()
//{
//	return (Q.rear - Q.front + Q.Queuesize) % Q.Queuesize;
//}
//
//int main()
//{
//	Createqueue();
//	InserElement(1);
//	InserElement(2);
//	InserElement(3);
//	InserElement(4);
//	InserElement(5);
//	InserElement(6);
//	InserElement(7);
//	printf("%d\n", CountQueue());
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", DeleteElement());
//	}
//	printf("%d\n", CountQueue());
//	return 0;
//}

//enum dir{ up, down, left, right };
//int Dir = up;
//
////圆坐标结构体
//typedef struct cir
//{
//	int x;
//	int y;
//}cir;
//
//cir C;
//void Update()
//{
//	switch (Dir)
//	{
//	case up:
//		if (C.x>0)
//		C.x -= 1;
//		break;
//	case down:
//		if (C.x < ROWS - 1)
//		C.x += 1;
//		break;
//	case left:
//		if (C.y>0)
//		C.y -= 1;
//		break;
//	case right:
//		if (C.y<COLS-1)
//		C.y += 1;
//		break;
//	default:
//		break;
//	}
//}
//void Displaymap()
//{
//	cleardevice();
//	setfillcolor(RED);
//	setlinecolor(RED);
//	fillcircle(C.y*SIDE,C.x*SIDE, SIDE/2);
//}
//
//void changedir()
//{
//	switch (_getch())
//	{
//	case 'w':
//	case 'W':
//	case 72:
//		Dir = up;
//		break;
//	case 's':
//	case 'S':
//	case 80:
//		Dir = down;
//		break;
//	case 'a':
//	case 'A':
//	case 75:
//		Dir = left;
//		break;
//	case 'd':
//	case 'D':
//	case 77:
//		Dir = right;
//		break;
//	default:
//		break;
//	}
//}
//
//
//int main()
//{
//	//初始化绘图窗口
//	initgraph(COLS*SIDE, ROWS*SIDE);
//	//随机初始坐标
//	srand((unsigned int)time(NULL));
//	C.x = rand() % ROWS;
//	C.y = rand() % COLS;
//	//主循环
//	while (1)
//	{
//		if (_kbhit())
//			changedir();
//		Update();
//		Displaymap();
//		Sleep(100);
//	}
//	return 0;
//}