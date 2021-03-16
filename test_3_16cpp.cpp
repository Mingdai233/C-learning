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


void InThreading(BiThrTree*p);//预先声明
BitThrNodeType *pre;
BiThrTree*InOrderThr(BiThrTree*T)
{
	/*中序遍历二叉树T，并将其中序线索化，pre为全局变量*/
	BitThrNodeType* head;//线索二叉树的头结点，指向根结点
	head = (BitThrNodeType*)malloc(sizeof(BitThrNodeType));/*设申请头结点成功*/
	head->ltag = 0; head->rtag = 1;/*建立头结点*/
	head->rchild = head;/*右指针回指*/
	if (!T)
		head->lchild = head;/*若二叉树为空，则左指针回指*/
	else
	{
		head->lchild = T; 
		pre = head;
		InThreading(T);/*中序遍历进行中序线索化*/
		pre->rchild = head;
		pre->rtag = 1;/*最后一个结点线索化*/
		head->rchild = pre;
	}
	return head;
}
void InThreading(BiThrTree*p)
{/*通过中序遍历进行中序线索化*/
	if (p)
	{
		InThreading(p->lchild);/*左子树线索化，递归*/
		if (p->lchild == NULL)/*前驱线索*/
		{
			p->ltag = 1;
			p->lchild = pre;
		}
		else
			p->ltag = 0;
		if (p->rchild == NULL)
			p->rtag = 1;/*后驱线索*/
		else
			p->rtag = 0;
		if (pre != NULL&&pre->rtag == 1)
			pre->rchild = p;
		pre = p;
		InThreading(p->rchild);/*右子树线索化*/
	}
}

int main()
{
	BiThrTree* T;
	CreateBitree(T);
	T = InOrderThr(T);
	return 0;
}