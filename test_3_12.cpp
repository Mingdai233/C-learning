#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>




//#include<iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
////三元组结构体
//typedef struct
//{
//	int row, col;
//	int data;
//}triple;
////三元组顺序表
//typedef struct
//{
//	triple *p;
//	int n,m,num;//行，列，非0元素个数
//}TSMatrix;
//
//void StoreMatrix(TSMatrix &M,int n,int m,int num)
//{
//	M.p = new triple[num];
//	M.n = n;
//	M.m = m;
//	M.num = num;
//}
//
//void printMatrix(TSMatrix M);
//int main()
//{
//	TSMatrix M;
//	StoreMatrix(M, 6, 6, 8);
//
//	M.p[0].row = 1;
//	M.p[0].col = 2;
//	M.p[0].data = 12;
//
//
//	M.p[1].row = 1;
//	M.p[1].col = 3;
//	M.p[1].data = 9;
//
//
//	M.p[2].row = 3;
//	M.p[2].col = 1;
//	M.p[2].data = -3;
//
//
//	M.p[3].row = 3;
//	M.p[3].col = 5;
//	M.p[3].data = 14;
//
//
//	M.p[4].row = 4;
//	M.p[4].col = 3;
//	M.p[4].data = 24;
//
//
//	M.p[5].row = 5;
//	M.p[5].col = 2;
//	M.p[5].data = 18;
//
//
//	M.p[6].row = 6;
//	M.p[6].col = 1;
//	M.p[6].data = 15;
//
//
//	M.p[7].row = 6;
//	M.p[7].col = 4;
//	M.p[7].data = -7;
//
//	printMatrix(M);
//	delete M.p;
//	return 0;
//}
//
//void printMatrix(TSMatrix M)
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= M.n;i++)
//	{
//		for (j = 1; j <= M.m; j++)
//		{
//			if (M.p[n].row == i&&M.p[n].col == j)
//			{
//				printf("%3d", M.p[n].data);
//				n++;
//			}
//			else
//			{
//				printf("%3d", 0);
//			}
//		}
//		cout << endl;
//	}
//}