#define _CRT_SECURE_NO_WARNINGS 1
#include"Bitree.h"
#include"Stack.h"
#include"Queue.h"
#include<stdio.h>




//根据输入的序列由先序进行二叉树的创建('#'代表空树)
void CreateBitree(Bitree &T)
{
	BTElemtype ch;
	cin >> ch;
	if (ch != '#')
	{
		T = new BTnode;
		T->data = ch;
		CreateBitree(T->lChild);
		CreateBitree(T->rChild);
	}
	else
		T = NULL;
}

//访问操作
void vist(Bitree T)
{
	cout << T->data;
}

//先序遍历
void Preodertraverse(Bitree T)
{
	if (T != NULL)
	{
		vist(T);
		Preodertraverse(T->lChild);
		Preodertraverse(T->rChild);
	}
	else
		return;
}
//中序遍历
void Inodertraverse(Bitree T)
{
	if (T != NULL)
	{
		Inodertraverse(T->lChild);
		vist(T);
		Inodertraverse(T->rChild);
	}
	else
		return;
}
//后序遍历
void Postodertraverse(Bitree T)
{
	if (T != NULL)
	{
		Postodertraverse(T->lChild);
		Postodertraverse(T->rChild);
		vist(T);
	}
	else
		return;
}

//不利用递归的中序遍历
void Inodertraverses(Bitree T)
{
	Stack S;
	BTnode* q=NULL;
	while (T || !Stackempty(S))
	{
		if (T)
		{
			Pushstack(S, T);
			T = T->lChild;
		}
		else
		{
			Popstack(S, q);
			vist(q);
			T = q->rChild;
		}

	}
}

//二叉树的层次遍历(利用队列先进先出的原理)
void Levelodertraverse(Bitree T)
{
	Queue Q;
	SElemtype e;
	EnterQueue(Q, T);
	while (!Queueempty(Q))
	{
		OutQueue(Q, e);
		vist(e);
		if (e->lChild != NULL)
		{
			EnterQueue(Q, e->lChild);
		}
		if (e->rChild != NULL)
		{
			EnterQueue(Q, e->rChild);
		}
	}
}

//二叉树的复制(利用先序)
void Bitreecopy(Bitree T, Bitree &S)
{
	if (T==NULL)
	{
		S = NULL;
	}
	else
	{
		S = new BTnode;
		if (!S)
		{
			perror("内存不足!");
			exit(EXIT_FAILURE);
		}
		S->data = T->data;
			Bitreecopy(T->lChild, S->lChild);
			Bitreecopy(T->rChild, S->rChild);
	}
}

//计算树的深度
int Bitreedepth(Bitree T)
{
	if (T == NULL)
		return 0;//空树没深度
	else
	{
		int n = Bitreedepth(T->lChild);
		int m = Bitreedepth(T->rChild);
		if (n > m)
		{
			return n + 1;
		}
		else
		{
			return m + 1;
		}
	}
}

//叶子节点数
int Leadcount(Bitree T)
{
	if (T == NULL)
		return 0;
	if (T->lChild == NULL&&T->rChild == NULL)
		return 1;
	else
	{
		return Leadcount(T->lChild) + Leadcount(T->rChild);
	}
}
