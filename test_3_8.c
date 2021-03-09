#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//��ջ
typedef int SElemtype;

typedef struct Stacknode
{
	SElemtype data;
	struct Stacknode* next;
}Stacknode,*Linkstack;

Linkstack S;

void Initstack()
{
	 S = NULL;
}

int stackempty(Linkstack S)
{
	if (S == NULL)
		return true;
	else
		return false;
}

void Clearstack(Linkstack S)
{
	Stacknode *ptemp;
	while (S)
	{
		ptemp = S;
		S = S->next;
		free(ptemp);
	}
}

void pushstack(Linkstack S,SElemtype e)
{
	Stacknode* New = (Stacknode*)malloc(sizeof(Stacknode));
	New->data = e;
	New->next = S;
	S = New;
}

SElemtype popstack(Linkstack S)
{
	if (S != NULL)
	{
		Stacknode* p = S;
		S = S->next;
		SElemtype e = p->data;
		free(p);
		return e;
	}
	perror("�����!");
}
////˳��ջ
//typedef int SElemtype;
//typedef struct Sqstack
//{
//	SElemtype* base;
//	SElemtype* top;
//	int stacksize;
//}Sqstack;
////����һ����ջ
//Sqstack Createstack(int stacksize)
//{
//	Sqstack S;
//	S.top=S.base = (SElemtype*)malloc(sizeof(SElemtype)*stacksize);
//	S.stacksize = stacksize;
//	return S;
//}
////�жϿ�ջ
//int Emptystack(Sqstack S)
//{
//	if (S.base == S.top)
//		return true;
//	else
//		return false;
//
//}
////���ջԪ��
//void ClearElement(Sqstack* S)
//{
//	S->top = S->base;
//}
////����Ԫ������
//int Elementnum(Sqstack S)
//{
//	return S.top - S.base;
//}
////����ջ
//void Destroystack(Sqstack* S)
//{
//	if (S)
//	{
//		free(S->base);
//		S->base = S->top = NULL;
//		S->stacksize = 0;
//	}
//}
////��ȡջ��Ԫ��
//SElemtype topElement(Sqstack S)
//{
//	if (S.base == S.top)
//	{
//		perror("��ջ!");
//		return -1;
//	}
//	return *S.top;
//}
////��ջ
//void pushstack(Sqstack* S, SElemtype e)
//{
//	if (S->top - S->base == S->stacksize)
//	{
//		perror("ջ�����!");
//		return 0;
//	}
//	*(S->top)++ = e;
//}
////��ջ
//SElemtype popstack(Sqstack *S)
//{
//	if (S->base == S->top)
//	{
//		perror("ջ�������");
//		return 0;
//	}
//	return *--(S->top);
//}
//int main()
//{
//	Sqstack S = Createstack(5);
//	if (Emptystack(S))
//	{
//		printf("��ջ!\n");
//	}
//	pushstack(&S, 1);
//	pushstack(&S, 2);
//	pushstack(&S, 3);
//	if (Emptystack(S))
//	{
//		printf("��ջ!\n");
//	}
//	else
//	{
//		printf("ջ��Ϊ��!\n");
//	}
//	pushstack(&S, 4);
//	pushstack(&S, 5);
//	pushstack(&S, 6);
//	ClearElement(&S);
//	if (Emptystack(S))
//	{
//		printf("��ջ!\n");
//	}
//	return 0;
//}
////ϡ�����ʽ���
//typedef struct Node
//{
//	int exponent;//ָ��
//	int coefficient;//ϵ��
//	struct Node* next;
//}Node,*Head;
//
//Head CreatePolyn(int n)//ϡ�����ʽ����
//{
//	Node* rear;
//	Head L = (Head)malloc(sizeof(Node));
//	rear = L;
//	L->next = NULL;
//	for (int i = 0; i < n; i++)
//	{
//		Node* p = (Node*)malloc(sizeof(Node));
//		p->next = NULL;
//		printf("�������%d��ָ��:",i+1);
//		scanf("%d", &p->exponent);
//		printf("�������%d��ϵ��:",i+1);
//		scanf("%d", &p->coefficient);
//		rear->next = p;
//		rear = p;
//	}
//	return L;
//}
//
//Head Add(Head Pa, Head Pb)
//{
//	Node *pa, *pb,*H,*B;
//	H = Pa;
//	pa = Pa->next;
//	pb = Pb->next;
//	while (pa&&pb)
//	{
//		if (pa->exponent == pb->exponent)
//		{
//			pa->coefficient = (pa->coefficient) + (pb->coefficient);
//			if (pa->coefficient == 0)
//			{
//				H->next = pa->next;
//				free(pa);
//			}
//			pa = pa->next;
//			pb = pb->next;
//		}
//		else
//		{
//			if (pa->exponent < pb->exponent)
//			{
//				H->next = pa;
//				pa = pa->next;
//			}
//			else
//			{
//				H->next = pb;
//				pb = pb->next;
//			}
//		}
//		H = H->next;
//	}
//	(pa)?(H->next = pa) : (H->next = pb);
//	free(Pb);
//	Pb = NULL;
//	return Pa;
//}
//
//int main()
//{
//	Head Pa,Pb,Pc;
//	Pa = CreatePolyn(4);
//	Pb = CreatePolyn(3);
//	Pc = Add(Pa, Pb);
//	return 0;
//}

//typedef struct List
//{
//	int *head;
//	int length;
//	int size;
//}List;
//
//List CreatList(int length)
//{
//	List L;
//	L.head = (int*)malloc(sizeof(List)*length);
//	L.length = length;
//	L.size = length * 2;
//	return L;
//}
//
//List Add(List Pa, List Pb)
//{
//	int i = 0;
//	while (i < Pa.length&&i < Pb.length)
//	{
//		Pa.head[i] = Pa.head[i] + Pb.head[i];
//		i++;
//	}
//	while (i < Pa.length)
//		return Pa;
//	while (i < Pb.length)
//	{
//		Pa.head[i] = Pb.head[i];
//		i++;
//		Pa.length = Pb.length;
//	}
//	return Pa;
//}
//
//
//int main()
//{
//	List Pa,Pb,Pc;
//	Pa = CreatList(5);
//	Pb = CreatList(7);
//	Pc = CreatList(7);
//	//����ʽPa
//	Pa.head[0] = 10;
//	Pa.head[1] = 5;
//	Pa.head[2] = -4;
//	Pa.head[3] = 3;
//	Pa.head[4] = 2;
//	//Pb
//	Pb.head[0] = -3;
//	Pb.head[1] = 8;
//	Pb.head[2] = 4;
//	Pb.head[3] = 0;
//	Pb.head[4] = -5;
//	Pb.head[5] = 7;
//	Pb.head[6] = -2;
//	Pc=Add(Pa, Pb);
//}