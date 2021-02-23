#define _CRT_SECURE_NO_WARNINGS 1

#include"MyList.h"


//创建一个链表(链表长度)
Node* CreatList(int length)
{
	//判断长度输入是否正确
	if (length < 0)
	{
		perror("Length Error!");
		exit(EXIT_FAILURE);
	}
	//初始化链表头指针和尾指针
	Node *phead, *ptail;
	phead = ptail = NULL;
	//申请头结点(哑节点)
	phead = (Node*)malloc(sizeof(Node));
	//判断申请是否成功
	if (!phead)
	{
		perror("Malloc Fail!");
		exit(EXIT_FAILURE);
	}
	phead->sum = 0;
	phead->pnext = NULL;
	ptail = phead;
	//增加链表节点
	int i = 0;
	Node* NewNodepos=NULL;//新节点指针
	if (0 == length)
	{
		return phead;
	}
	for (i = 0; i < length;i++)
	{
		//申请一个新的节点
		NewNodepos = (Node*)malloc(sizeof(Node));
		//判断节点申请是否成功
		if (!NewNodepos)
		{
			perror("Malloc Fail!");
			exit(EXIT_FAILURE);
		}
		//初始化新节点
		NewNodepos->pnext = NULL;
		printf("请输入第%d个节点的值:", i+1);
		scanf("%d", &(NewNodepos->sum));
		//把新节点加入到链表中
		ptail->pnext = NewNodepos;
		//更新尾节点
		ptail = NewNodepos;
	}
	return phead;
}

//打印链表
void DisplayList(Node* pList)
{
	//判断链表是否为空
	if (!pList->pnext)
	{
		printf("这是一个空的链表\n\n");
		return 0;
	}
	Node *ptemp = pList->pnext;
	printf("链表所储存的值为:");
	while (ptemp)
	{
		printf("%d ", ptemp->sum);
		ptemp = ptemp->pnext;
	}
	printf("\n\n");
}

//链表插入元素(链表，作为第n个节点插入，插入数值)
Node* InserElement(Node *pList, int n, Datetype num)
{
	//判断输入位置是否正确
	if (n <= 0)
	{
		perror("Inserpositon Error!");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	Node *ptemp,*ptemp0;
	ptemp0 = NULL;
	ptemp = pList;
	for (i = 0; i < n; i++)
	{
		ptemp0 = ptemp;//上一个节点的地址
		ptemp = ptemp->pnext;//下一个节点的地址
		if (!ptemp)
		{
			break;
		}
	}
	if (i>=n-1)
	{
		//创建一个新的节点
		Node *Newnodepos = (Node*)malloc(sizeof(Node));
		//初始化新节点的值
		Newnodepos->pnext = ptemp;//原来节点的地址
		Newnodepos->sum = num;
		ptemp0->pnext = Newnodepos;
	}
	else
	{
		perror("Inserposition Error!");
		exit(EXIT_FAILURE);
	}
	return pList;
}

//删除链表所有节点
Node* DeleteList(Node *pList)
{
	Node *ptemp = pList->pnext;//当前节点
	Node *ptemp2 = NULL;
	pList->pnext = NULL;//头节点置空;
	while (ptemp)
	{
		ptemp2 = ptemp->pnext;//下一个节点先取出来
		free(ptemp);//释放当前节点
		ptemp = ptemp2;//把下一个节点作为当前节点
	}
	return pList;
}

//删除特定值的节点
Node* DeleteElement(Node *pList, Datetype value)
{
	Node *ptemp = pList;//当前节点
	Node *ptemp2 ;
	while (ptemp->pnext)
	{
		if (value ==ptemp->pnext->sum)
		{
			ptemp2 = ptemp->pnext;//值与所需删除的值相等的节点
			ptemp ->pnext= ptemp2->pnext;//当前节点的下一个节点变成值与所需删除的值相等的节点的下一个节点
			free(ptemp2);//删除节点
			ptemp2 = NULL;
			return pList;
		}
		ptemp = ptemp->pnext;//
	}
	printf("要删除的元素不存在\n\n");
	return pList;
}

//查找一个元素，返回所查找节点指针或NULL
Node* FindElement(Node *pList, Datetype value)
{
	while (pList->pnext)
	{
		if (value == pList->pnext->sum)
		{
			return pList->pnext;
		}
		pList = pList->pnext;//下一个节点
	}
	return NULL;//查找不到返回空值
}


