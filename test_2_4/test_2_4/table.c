#define _CRT_SECURE_NO_WARNINGS 1

#include"table.h"
#include<stdio.h>
#include<stdlib.h>

Table* CreatTable(int size,Table* t)
{
	int *p = (int*)malloc(sizeof(int)*size);
	t->head = p;
	t->size = size;
	t->length = 0;
	return t;
}

void DisplayTable(Table t)
{
	int i = 0;
	printf("˳��������Ϊ:");
	for (i = 0; i < t.length; i++)
	{
		printf("%d ", t.head[i]);
	}
	printf("\n���Ԫ�ظ���Ϊ:%d\n",t.length);
	printf("����ܴ�СΪ:%d\n\n", t.size);
}


Table* SetTable(Table*p)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		(p->head)[i] = i;
		p->length++;
	}
	return p;
}

Table* AddTable(Table*p,int pos,int num)
{
	//�жϲ���λ���Ƿ���ȷ
	if (pos<0 || pos >p->length)
	{
		printf("����λ�ô���\n");
		return p;
	}
	//�ж��Ƿ���Ҫ����
	if (p->length == p->size)
	{
		//��¼ԭ�ڴ��ַ
		//���ڴ���չ����
		//��ȡԭ�ڴ�����
		//�ͷ�ԭ�ڴ�
		//ԭ�ڴ��ַ�ÿ�
		int* ptmp = p->head;
		p->head = (int *)calloc(sizeof(int), (p->size) *=2);
		//�ж������Ƿ�ɹ�
		if (p->head)
		{
			int i = 0;
			for (i = 0; i < p->length; i++)
			{
				p->head[i] = ptmp[i];
			}
			free(ptmp);
			ptmp = NULL;
		}
		else
		{
			return p;
		}
	}
	//����
	int i = 0;
	for (i = p->length; i > pos; i--)
	{
		p->head[i] = p->head[i-1];
	}
	p->head[pos] = num;
	p->length++;
	return p;
}

Table* DelTable(Table*p, int pos)
{
	//�ж���Ҫɾ�����±��Ƿ���ȷ
	if (pos < 0 || pos >= p->length)
	{
		printf("������������\n");
		return p;
	}
	//ɾ��Ԫ��
	int i = 0;
	for (i = pos; i < p->length - 1; i++)
	{
		p->head[i] = p->head[i + 1];
	}
	p->length--;
	//�ж��Ƿ���Ҫ��������
	if (p->length == p->size/2)
	{
		//��¼ԭ�ڴ��ַ
		//���ڴ���������
		//��ȡԭ�ڴ�����
		//�ͷ�ԭ�ڴ�
		//ԭ�ڴ��ַ�ÿ�
		int* ptmp = p->head;
		p->head = (int *)calloc(sizeof(int), p->size /= 2);
		//�ж������Ƿ�ɹ�
		if (p->head)
		{
			for (i = 0; i < p->length; i++)
			{
				p->head[i] = ptmp[i];
			}
			free(ptmp);
			ptmp = NULL;
		}
		else
		{
			return p;
		}
	}
	return p;
}

int FindoutNum(Table*p, int num)
{
	int i = 0;
	for (i = 0; i < p->length; i++)
	{
		if (p->head[i] == num)
		{
			return i;
		}
	}
	return -1;
}


void ChangeNum(Table*p, int pos, int num)
{
	if (pos<0 || pos>p->length - 1)
	{
		printf("\n��ѡ������Ԫ��\n\n");
	}
	else
	{
		p->head[pos] = num;
	}
}