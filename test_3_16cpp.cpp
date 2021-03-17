#define _CRT_SECURE_NO_WARNINGS 1

#include"Haffuman.h"
#include<stdio.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n = 0;
	HaffumanTree H=NULL;
	cout << "请输入哈夫曼树的叶子数:";
	cin >> n;
	CreateHaffumantree(H, n);
	Haffumancode HC = NULL;
	CreateHaffumancode(H, HC, n);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		printf("第%d个叶子的哈夫曼编码为:%s\n", i + 1, HC[i+1]);
	}
	return 0;
}
