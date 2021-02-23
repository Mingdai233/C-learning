#ifndef _MYLIST_
#define _MYLIST_

#include<stdio.h>
#include<stdlib.h>

typedef int Datetype;//方便修改链表数据类型

//定义链表的一个节点
 typedef struct node
{
	Datetype sum;
	struct node *pnext;
}Node;

Node* CreatList(int length);//创建一个链表(链表长度)
void DisplayList(Node* pList);//打印链表
Node* InserElement(Node *pList, int pos, Datetype value);//链表插入元素(链表，作为第n个节点插入，插入数值)
Node* DeleteList(Node *pList);//删除链表所有节点
Node* DeleteElement(Node *pList, Datetype value);//删除特定值的节点
Node* FindElement(Node *pList, Datetype value);//查找一个元素，返回所查找节点指针或NULL
#endif