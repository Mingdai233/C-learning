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
	cout << "���������������Ҷ����:";
	cin >> n;
	CreateHaffumantree(H, n);
	Haffumancode HC = NULL;
	CreateHaffumancode(H, HC, n);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		printf("��%d��Ҷ�ӵĹ���������Ϊ:%s\n", i + 1, HC[i+1]);
	}
	return 0;
}
