#define _CRT_SECURE_NO_WARNINGS 1

#include"Haffuman.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using std::cin;

//����������
void CreateHaffumancode(HaffumanTree HT, Haffumancode &HC, int n)
{
	HC = new char*[n+1];//0��λ��ʹ��
	char* cd = new char[n];//һ���������������n-1��������λ��+'\0'
	int start = n - 1;
	cd[start] = '\0';
	for (int i = 1; i <= n; i++)//��������Ҷ�ӽڵ���й���������
	{
		start = n - 1;
		int f = HT[i].parent;//��ǰ�ڵ��˫�׽ڵ�
		int c = i;//��¼��ǰ�ڵ�
		while (f)//һֱ�ҵ����ڵ�Ϊֹ
		{
			//�жϵ�ǰ�ڵ���˫�׽ڵ���ĸ�����
			if (HT[f].lchild == c)//��'0'
				//��Ҫһ���������洢����ֵ
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
			//��ǰ�ڵ�Ҫ��Ϊ˫�׽ڵ����ж�����˫�׽ڵ����ڵ㻹���ҽڵ�
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n -start];
		strcpy(HC[i],&cd[start]);//��ʱ���븴�Ƶ�Haffumancode�б���
	}
	//�ͷ���ʱ����
	delete[]cd;
}
//��������������nΪҶ�ӽڵ���
void CreateHaffumantree(HaffumanTree &HT, int n)
{
	int m = 2 * n - 1;
	HT = new HTnode[m + 1];//0��λ�ò�ʹ��
	//��ʼ����������
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	 if (i <= n)//1-n���ڵ��Ȩֵ
		{
			printf("�������%d������Ȩֵ:", i);
			cin >> HT[i].weight;
		}
	}
	//�����������
	for (int i = n+1; i <= m; i++)
	{
		int s1, s2;
		slecte(HT, i-1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}


//ѡ����ǰ������ɭ����С���������ڵ��±�
void slecte(HaffumanTree H, int size, int &s1, int &s2)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		if (H[i].parent == 0)
		{
			s1 = i;
			break;
		}
		else
			i++;
	}
	j = i + 1;
	while (1)
	{
		if (H[j].parent == 0)
		{
			s2 = j;
			break;
		}
		else
			j++;
	}
	for (int k = j; k <= size; k++)
	{
		if (H[k].parent == 0)
		{
			if (H[k].weight < H[s1].weight)
			{
				s2 = s1;
				s1 = k;
			}
			else
			{
				if (H[k].weight < H[s2].weight)
					s2 = k;
			}
		}
	}
}