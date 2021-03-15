#define _CRT_SECURE_NO_WARNINGS 1
#include"Bitree.h"
#include"Stack.h"
#include"Queue.h"
#include<stdio.h>




//���������������������ж������Ĵ���('#'�������)
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

//���ʲ���
void vist(Bitree T)
{
	cout << T->data;
}

//�������
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
//�������
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
//�������
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

//�����õݹ���������
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

//�������Ĳ�α���(���ö����Ƚ��ȳ���ԭ��)
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

//�������ĸ���(��������)
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
			perror("�ڴ治��!");
			exit(EXIT_FAILURE);
		}
		S->data = T->data;
			Bitreecopy(T->lChild, S->lChild);
			Bitreecopy(T->rChild, S->rChild);
	}
}

//�����������
int Bitreedepth(Bitree T)
{
	if (T == NULL)
		return 0;//����û���
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

//Ҷ�ӽڵ���
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
