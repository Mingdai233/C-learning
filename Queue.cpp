#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//Èë¶Ó
void EnterQueue(Queue &Q,SElemtype T)
{
	//ÅÐ¶ÏÊÇ·ñÂú¶Ó
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		perror("Âú¶Ó!");
		return;
	}
	Q.data[Q.rear] = T;
	Q.rear=(Q.rear+1)%MAXSIZE;
}

//³ö¶Ó
void OutQueue(Queue &Q, SElemtype &e)
{
	//ÅÐ¶Ï¶Ó¿Õ
	if (Q.front == Q.rear)
	{
		perror("¶Ó¿Õ!");
		return;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
}

//ÅÐ¶Ï¶Ó¿Õ
bool Queueempty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}