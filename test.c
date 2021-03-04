#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

int main()
{
	int i = 0;
	LinkList L = CreateList2(5);
	LinkList L2 = CreateList(5);
	L = List_union(L, L2);
	DisplayList(L);
	printf("链表长度为:%d\n", List_Length(L));
	DestoryList(L);
	L = CreateList(5);
	DisplayList(L);
	i = List_Findnum(L, 4);
	printf("%d\n", i);
	i = List_Num(L, 3);
	printf("%d\n", i);
	DisplayList(InserNode(L, 11, 3));
	DisplayList(DeleteNode(L, 3));
	ClearList(L);
	DisplayList(L);
	return 0;
}