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
	printf("��������Ҫ���ҵ�Ԫ��:");
	scanf("%d", &num);
	if (-1 == FindoutNum(&t, num))
	{
		printf("û���ҵ�\n");
	}
	else
	{
		printf("Ԫ������˳�����±�Ϊ:%d\n", FindoutNum(&t, num));
	}
	return 0;
}