#define _CRT_SECURE_NO_WARNINGS 1

#include"MyList.h"

int main()
{
	Node *pList = CreatList(5);
	DisplayList(pList);
	printf("��Ҫ���ҵ�ֵΪ%d\n\n", FindElement(pList, 3)->sum);
	DisplayList(InserElement(pList, 2, 11));
	DisplayList(DeleteList(pList));
	DisplayList(DeleteElement(pList, 5));
	return 0;
}