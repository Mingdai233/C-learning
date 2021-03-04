#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//创建链表（头插法）
LinkList CreateList(int length)
{
	//创建头节点
	LinkList L = (LinkList)malloc(sizeof(LNode));
	if (!L)
	{
		perror("内存不足");
		exit(EXIT_FAILURE);
	}
	L->next = NULL;
	int i = 0;
	for (i = length; i > 0; i--)
	{
		LNode* NewNode = (LNode*)malloc(sizeof(LNode));
		if (!NewNode)
		{
			perror("内存不足");
			exit(EXIT_FAILURE);
		}
		printf("输入链表第%d个元素->:",i);
		scanf("%d", &NewNode->data);
		NewNode->next = L->next;
		L->next = NewNode;
	}
	return L;
}

//创建链表(尾插法)
LinkList CreateList2(int length)
{
	//创建头结点和尾节点
	LinkList L, R;
	L=(LinkList)malloc(sizeof(LNode));
	R = L;
	if (!L)
	{
		perror("内存不足!");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < length; i++)
	{
		LNode* NewNode = (LNode*)malloc(sizeof(LNode));
		if (!NewNode)
		{
			perror("内存不足!");
			exit(EXIT_FAILURE);
		}
		printf("请输入第%d个元素->:", i + 1);
		scanf("%d", &NewNode->data);
		NewNode->next = NULL;
		R->next = NewNode;
		R = NewNode;
	}
	return L;
}

//打印链表
void DisplayList(LinkList L)
{
	if (L == NULL)
	{
		printf("链表不存在!\n");
		return 0;
	}
	//空表
	if (L->next == NULL)
	{
		printf("链表为空表!\n\n");
		return 0;
	}
	LNode* p = L;
	printf("链表储存的元素为:");
	while (p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("\n\n");
}
//数链表长度(空表返回0)
int List_Length(LinkList L)
{
	LNode* p = L;
	int count = 0;
	while (p = p->next)
	{
		count++;
	}
	return count;
}

//销毁链表
void DestoryList(LinkList L)
{
	while (L)
	{
		LNode *temp = L->next;
		free(L);
		L = temp;
		if (L)
		temp = L->next;
	}
}

//清除节点
LinkList ClearList(LinkList L)
{
	LinkList p = L->next;//首元结点
	LinkList q = p->next;//首元结点下一个节点
	while (p)
	{
		free(p);
		L->next = q;
		p = q;
		if (p)
		{
			q = p->next;
		}
	}
	
	return L;
}

//取链表第i个元素的值
Elementtype List_Num(LinkList L, int i)
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		perror("输入位置错误!");
		return -1;
	}
	return p->data;
}

//按值查找
int List_Findnum(LinkList L, Elementtype n)
{
	LNode* p = L->next;//syjd
	int j = 1;
	while (p)
	{
		if (p->data == n)
		{
			return j;
		}
		p = p->next;
		j++;
	}
	return 0;//没有找到返回-1
}
//插入一个节点
LinkList InserNode(LinkList L, Elementtype n,int i)
{
	LNode* NewNode = (LNode*)malloc(sizeof(LNode));
	if (!NewNode)
	{
		perror("内存不足!");
		return L;
	}
	LNode* p = L;
	for (int j = 0; j < i - 1; j++)//找到第i-1个节点
	{
		p = p->next;
	}
	NewNode->data = n;
	NewNode->next = p->next;
	p->next = NewNode;
	return L;
}
//删除第i个节点
LinkList DeleteNode(LinkList L, int i)
{
	//找到第i-1个节点
	LNode* p = L;
	for (int j = 0; j < i - 1; j++)
	{
		p = p->next;
	}
	//删除节点
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
	return L;
}

//表合并
LinkList List_union(LinkList A, LinkList B)
{
	int a = List_Length(A);
	int b = List_Length(B);
	for (int i = 1; i < b; i++)
	{
		if (!List_Findnum(A, List_Num(B, i)))
		{
			InserNode(A, List_Num(B, i), ++a);
		}
	}
	return A;
}

