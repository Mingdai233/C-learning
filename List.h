
#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>

typedef int Elementtype;

//Á´±í½Úµã
typedef struct LNode
{
	Elementtype data;
	struct LNode* next;
}LNode,*LinkList;

LinkList CreateList(int length);
LinkList CreateList2(int length);
void DisplayList(LinkList L);
int List_Length(LinkList L);
void DestoryList(LinkList L);
LinkList ClearList(LinkList L);
Elementtype List_Num(LinkList L, int i);
int List_Findnum(LinkList L, Elementtype n);
LinkList InserNode(LinkList L, Elementtype n,int i);
LinkList DeleteNode(LinkList L, int i);
LinkList List_union(LinkList A, LinkList B);
#endif