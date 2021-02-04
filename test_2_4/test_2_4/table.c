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
	printf("顺序表的内容为:");
	for (i = 0; i < t.length; i++)
	{
		printf("%d ", t.head[i]);
	}
	printf("\n表的元素个数为:%d\n",t.length);
	printf("表的总大小为:%d\n\n", t.size);
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
	//判断插入位置是否正确
	if (pos<0 || pos >p->length)
	{
		printf("插入位置错误\n");
		return p;
	}
	//判断是否需要扩容
	if (p->length == p->size)
	{
		//记录原内存地址
		//新内存扩展容量
		//读取原内存内容
		//释放原内存
		//原内存地址置空
		int* ptmp = p->head;
		p->head = (int *)calloc(sizeof(int), (p->size) *=2);
		//判断扩容是否成功
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
	//插入
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
	//判断需要删除的下标是否正确
	if (pos < 0 || pos >= p->length)
	{
		printf("输入错误的坐标\n");
		return p;
	}
	//删除元素
	int i = 0;
	for (i = pos; i < p->length - 1; i++)
	{
		p->head[i] = p->head[i + 1];
	}
	p->length--;
	//判断是否需要缩减容量
	if (p->length == p->size/2)
	{
		//记录原内存地址
		//新内存缩减容量
		//读取原内存内容
		//释放原内存
		//原内存地址置空
		int* ptmp = p->head;
		p->head = (int *)calloc(sizeof(int), p->size /= 2);
		//判断申请是否成功
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
		printf("\n所选坐标无元素\n\n");
	}
	else
	{
		p->head[pos] = num;
	}
}