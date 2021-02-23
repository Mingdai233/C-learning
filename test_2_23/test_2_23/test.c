#define _CRT_SECURE_NO_WARNINGS 1

#include"MyList.h"

int main()
{
	Node *pList = CreatList(5);
	DisplayList(pList);
	printf("所要查找的值为%d\n\n", FindElement(pList, 3)->sum);
	DisplayList(InserElement(pList, 2, 11));
	DisplayList(DeleteList(pList));
	DisplayList(DeleteElement(pList, 5));
	return 0;
}