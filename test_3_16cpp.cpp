#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using std::cin;

typedef struct BitThrNodeType
{
	struct BitThrNodeType *lchild, *rchild;
	int ltag, rtag;
	char data;

} BitThrNodeType,BiThrTree;

void CreateBitree(BiThrTree* &T)
{
	char ch;
	cin >> ch;
	if (ch != '#')
	{
		T = new BitThrNodeType;
		T->data = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
	else
		T = NULL;
}


void InThreading(BiThrTree*p);//Ԥ������
BitThrNodeType *pre;
BiThrTree*InOrderThr(BiThrTree*T)
{
	/*�������������T��������������������preΪȫ�ֱ���*/
	BitThrNodeType* head;//������������ͷ��㣬ָ������
	head = (BitThrNodeType*)malloc(sizeof(BitThrNodeType));/*������ͷ���ɹ�*/
	head->ltag = 0; head->rtag = 1;/*����ͷ���*/
	head->rchild = head;/*��ָ���ָ*/
	if (!T)
		head->lchild = head;/*��������Ϊ�գ�����ָ���ָ*/
	else
	{
		head->lchild = T; 
		pre = head;
		InThreading(T);/*���������������������*/
		pre->rchild = head;
		pre->rtag = 1;/*���һ�����������*/
		head->rchild = pre;
	}
	return head;
}
void InThreading(BiThrTree*p)
{/*ͨ�����������������������*/
	if (p)
	{
		InThreading(p->lchild);/*���������������ݹ�*/
		if (p->lchild == NULL)/*ǰ������*/
		{
			p->ltag = 1;
			p->lchild = pre;
		}
		else
			p->ltag = 0;
		if (p->rchild == NULL)
			p->rtag = 1;/*��������*/
		else
			p->rtag = 0;
		if (pre != NULL&&pre->rtag == 1)
			pre->rchild = p;
		pre = p;
		InThreading(p->rchild);/*������������*/
	}
}

int main()
{
	BiThrTree* T;
	CreateBitree(T);
	T = InOrderThr(T);
	return 0;
}