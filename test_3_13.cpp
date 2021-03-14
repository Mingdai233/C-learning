#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>

using std::cin; 
using std::cout; 
using std::endl;
//十字链表节点
typedef struct TLnode
{
	int i, j, value;
	struct TLnode* right, *down;
}TLnode, *TLnodeLink;

//十字链表
typedef struct
{
	TLnodeLink *rhead, *chead;
	int n, m, num;
}TenList;

void CreateList(TenList &M,int n, int m,int num);
void printTL(TenList M);




int main()
{
	TenList M;
	CreateList(M, 4, 2,4);
	TLnode e1, e2, e3, e4;

	M.rhead[0] = &e1;
	M.rhead[1] = &e2;
	M.rhead[2] = &e3;

	M.chead[0] = &e2;
	M.chead[1] = &e1;
	e1.i = 1;
	e1.j = 2;
	e1.value = 2;
	e1.right = nullptr;
	e1.down = &e4;

	e2.i = 2;
	e2.j = 1;
	e2.value = 1;
	e2.right = nullptr;
	e2.down = &e3;

	e3.i = 3;
	e3.j = 1;
	e3.value = -2;
	e3.down = nullptr;
	e3.right = &e4;

	e4.i = 3;
	e4.j = 2;
	e4.value = 4;
	e4.down = nullptr;
	e4.right = nullptr;

	printTL(M);
	return 0;

}

void CreateList(TenList &M, int n, int m,int num)
{
	M.rhead = new TLnode*[n];
	M.chead = new TLnode*[m];
	if (!M.chead || !M.rhead)
	{
		perror("创建矩阵失败!");
		exit(EXIT_FAILURE);
	}
	M.n = n;
	M.m = m;
	M.num = num;
}

void printTL(TenList M)
{
	for (int i = 0; i < M.m; i++)
	{
		if (M.chead[i] != NULL)
		{
			TLnodeLink p = M.chead[i];
			while (p != NULL)
			{
				printf("%d\t%d\t%d\n", p->i, p->j, p->value);
				p = p->down;
			}
		}
	}
}