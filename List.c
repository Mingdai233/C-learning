#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//��������ͷ�巨��
LinkList CreateList(int length)
{
	//����ͷ�ڵ�
	LinkList L = (LinkList)malloc(sizeof(LNode));
	if (!L)
	{
		perror("�ڴ治��");
		exit(EXIT_FAILURE);
	}
	L->next = NULL;
	int i = 0;
	for (i = length; i > 0; i--)
	{
		LNode* NewNode = (LNode*)malloc(sizeof(LNode));
		if (!NewNode)
		{
			perror("�ڴ治��");
			exit(EXIT_FAILURE);
		}
		printf("���������%d��Ԫ��->:",i);
		scanf("%d", &NewNode->data);
		NewNode->next = L->next;
		L->next = NewNode;
	}
	return L;
}

//��������(β�巨)
LinkList CreateList2(int length)
{
	//����ͷ����β�ڵ�
	LinkList L, R;
	L=(LinkList)malloc(sizeof(LNode));
	R = L;
	if (!L)
	{
		perror("�ڴ治��!");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < length; i++)
	{
		LNode* NewNode = (LNode*)malloc(sizeof(LNode));
		if (!NewNode)
		{
			perror("�ڴ治��!");
			exit(EXIT_FAILURE);
		}
		printf("�������%d��Ԫ��->:", i + 1);
		scanf("%d", &NewNode->data);
		NewNode->next = NULL;
		R->next = NewNode;
		R = NewNode;
	}
	return L;
}

//��ӡ����
void DisplayList(LinkList L)
{
	if (L == NULL)
	{
		printf("��������!\n");
		return 0;
	}
	//�ձ�
	if (L->next == NULL)
	{
		printf("����Ϊ�ձ�!\n\n");
		return 0;
	}
	LNode* p = L;
	printf("�������Ԫ��Ϊ:");
	while (p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("\n\n");
}
//��������(�ձ���0)
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

//��������
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

//����ڵ�
LinkList ClearList(LinkList L)
{
	LinkList p = L->next;//��Ԫ���
	LinkList q = p->next;//��Ԫ�����һ���ڵ�
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

//ȡ�����i��Ԫ�ص�ֵ
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
		perror("����λ�ô���!");
		return -1;
	}
	return p->data;
}

//��ֵ����
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
	return 0;//û���ҵ�����-1
}
//����һ���ڵ�
LinkList InserNode(LinkList L, Elementtype n,int i)
{
	LNode* NewNode = (LNode*)malloc(sizeof(LNode));
	if (!NewNode)
	{
		perror("�ڴ治��!");
		return L;
	}
	LNode* p = L;
	for (int j = 0; j < i - 1; j++)//�ҵ���i-1���ڵ�
	{
		p = p->next;
	}
	NewNode->data = n;
	NewNode->next = p->next;
	p->next = NewNode;
	return L;
}
//ɾ����i���ڵ�
LinkList DeleteNode(LinkList L, int i)
{
	//�ҵ���i-1���ڵ�
	LNode* p = L;
	for (int j = 0; j < i - 1; j++)
	{
		p = p->next;
	}
	//ɾ���ڵ�
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
	return L;
}

//��ϲ�
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

