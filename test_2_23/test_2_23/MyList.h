#ifndef _MYLIST_
#define _MYLIST_

#include<stdio.h>
#include<stdlib.h>

typedef int Datetype;//�����޸�������������

//���������һ���ڵ�
 typedef struct node
{
	Datetype sum;
	struct node *pnext;
}Node;

Node* CreatList(int length);//����һ������(������)
void DisplayList(Node* pList);//��ӡ����
Node* InserElement(Node *pList, int pos, Datetype value);//�������Ԫ��(������Ϊ��n���ڵ���룬������ֵ)
Node* DeleteList(Node *pList);//ɾ���������нڵ�
Node* DeleteElement(Node *pList, Datetype value);//ɾ���ض�ֵ�Ľڵ�
Node* FindElement(Node *pList, Datetype value);//����һ��Ԫ�أ����������ҽڵ�ָ���NULL
#endif