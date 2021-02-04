#define _CRT_SECURE_NO_WARNINGS 1

#include"table.h"
#include<stdio.h>



int main()
{
	int num = 0;
	Table t;
	CreatTable(5,&t);
	DisplayTable(t);
	SetTable(&t);
	DisplayTable(t);
	AddTable(&t, 0, 66);
	DisplayTable(t);
	AddTable(&t, 7, 77);
	DisplayTable(t);
	DelTable(&t, 0);
	DisplayTable(t);
	DelTable(&t, 8);
	DisplayTable(t);
	ChangeNum(&t, -1, 20);
	ChangeNum(&t, 0, 100);
	DisplayTable(t);
	printf("请输入所要查找的元素:");
	scanf("%d", &num);
	if (-1 == FindoutNum(&t, num))
	{
		printf("没有找到\n");
	}
	else
	{
		printf("元素所在顺序表的下标为:%d\n", FindoutNum(&t, num));
	}
	return 0;
}