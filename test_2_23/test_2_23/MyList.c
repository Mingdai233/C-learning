#define _CRT_SECURE_NO_WARNINGS 1

#include"MyList.h"


//����һ������(������)
Node* CreatList(int length)
{
	//�жϳ��������Ƿ���ȷ
	if (length < 0)
	{
		perror("Length Error!");
		exit(EXIT_FAILURE);
	}
	//��ʼ������ͷָ���βָ��
	Node *phead, *ptail;
	phead = ptail = NULL;
	//����ͷ���(�ƽڵ�)
	phead = (Node*)malloc(sizeof(Node));
	//�ж������Ƿ�ɹ�
	if (!phead)
	{
		perror("Malloc Fail!");
		exit(EXIT_FAILURE);
	}
	phead->sum = 0;
	phead->pnext = NULL;
	ptail = phead;
	//��������ڵ�
	int i = 0;
	Node* NewNodepos=NULL;//�½ڵ�ָ��
	if (0 == length)
	{
		return phead;
	}
	for (i = 0; i < length;i++)
	{
		//����һ���µĽڵ�
		NewNodepos = (Node*)malloc(sizeof(Node));
		//�жϽڵ������Ƿ�ɹ�
		if (!NewNodepos)
		{
			perror("Malloc Fail!");
			exit(EXIT_FAILURE);
		}
		//��ʼ���½ڵ�
		NewNodepos->pnext = NULL;
		printf("�������%d���ڵ��ֵ:", i+1);
		scanf("%d", &(NewNodepos->sum));
		//���½ڵ���뵽������
		ptail->pnext = NewNodepos;
		//����β�ڵ�
		ptail = NewNodepos;
	}
	return phead;
}

//��ӡ����
void DisplayList(Node* pList)
{
	//�ж������Ƿ�Ϊ��
	if (!pList->pnext)
	{
		printf("����һ���յ�����\n\n");
		return 0;
	}
	Node *ptemp = pList->pnext;
	printf("�����������ֵΪ:");
	while (ptemp)
	{
		printf("%d ", ptemp->sum);
		ptemp = ptemp->pnext;
	}
	printf("\n\n");
}

//�������Ԫ��(������Ϊ��n���ڵ���룬������ֵ)
Node* InserElement(Node *pList, int n, Datetype num)
{
	//�ж�����λ���Ƿ���ȷ
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
		ptemp0 = ptemp;//��һ���ڵ�ĵ�ַ
		ptemp = ptemp->pnext;//��һ���ڵ�ĵ�ַ
		if (!ptemp)
		{
			break;
		}
	}
	if (i>=n-1)
	{
		//����һ���µĽڵ�
		Node *Newnodepos = (Node*)malloc(sizeof(Node));
		//��ʼ���½ڵ��ֵ
		Newnodepos->pnext = ptemp;//ԭ���ڵ�ĵ�ַ
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

//ɾ���������нڵ�
Node* DeleteList(Node *pList)
{
	Node *ptemp = pList->pnext;//��ǰ�ڵ�
	Node *ptemp2 = NULL;
	pList->pnext = NULL;//ͷ�ڵ��ÿ�;
	while (ptemp)
	{
		ptemp2 = ptemp->pnext;//��һ���ڵ���ȡ����
		free(ptemp);//�ͷŵ�ǰ�ڵ�
		ptemp = ptemp2;//����һ���ڵ���Ϊ��ǰ�ڵ�
	}
	return pList;
}

//ɾ���ض�ֵ�Ľڵ�
Node* DeleteElement(Node *pList, Datetype value)
{
	Node *ptemp = pList;//��ǰ�ڵ�
	Node *ptemp2 ;
	while (ptemp->pnext)
	{
		if (value ==ptemp->pnext->sum)
		{
			ptemp2 = ptemp->pnext;//ֵ������ɾ����ֵ��ȵĽڵ�
			ptemp ->pnext= ptemp2->pnext;//��ǰ�ڵ����һ���ڵ���ֵ������ɾ����ֵ��ȵĽڵ����һ���ڵ�
			free(ptemp2);//ɾ���ڵ�
			ptemp2 = NULL;
			return pList;
		}
		ptemp = ptemp->pnext;//
	}
	printf("Ҫɾ����Ԫ�ز�����\n\n");
	return pList;
}

//����һ��Ԫ�أ����������ҽڵ�ָ���NULL
Node* FindElement(Node *pList, Datetype value)
{
	while (pList->pnext)
	{
		if (value == pList->pnext->sum)
		{
			return pList->pnext;
		}
		pList = pList->pnext;//��һ���ڵ�
	}
	return NULL;//���Ҳ������ؿ�ֵ
}


