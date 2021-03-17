#define _CRT_SECURE_NO_WARNINGS 1

#include"Haffuman.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using std::cin;

//哈夫曼编码
void CreateHaffumancode(HaffumanTree HT, Haffumancode &HC, int n)
{
	HC = new char*[n+1];//0号位不使用
	char* cd = new char[n];//一个哈夫曼编码最多n-1个二进制位数+'\0'
	int start = n - 1;
	cd[start] = '\0';
	for (int i = 1; i <= n; i++)//哈夫曼树叶子节点进行哈夫曼编码
	{
		start = n - 1;
		int f = HT[i].parent;//当前节点的双亲节点
		int c = i;//记录当前节点
		while (f)//一直找到根节点为止
		{
			//判断当前节点是双亲节点的哪个孩子
			if (HT[f].lchild == c)//左孩'0'
				//需要一个数组来存储所得值
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
			//当前节点要变为双亲节点以判断其是双亲节点的左节点还是右节点
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n -start];
		strcpy(HC[i],&cd[start]);//临时编码复制到Haffumancode列表里
	}
	//释放临时数组
	delete[]cd;
}
//创建哈夫曼树，n为叶子节点数
void CreateHaffumantree(HaffumanTree &HT, int n)
{
	int m = 2 * n - 1;
	HT = new HTnode[m + 1];//0号位置不使用
	//初始化哈夫曼表
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	 if (i <= n)//1-n个节点的权值
		{
			printf("请输入第%d个数的权值:", i);
			cin >> HT[i].weight;
		}
	}
	//构造哈夫曼树
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


//选出当前哈夫曼森林最小的两个根节点下标
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