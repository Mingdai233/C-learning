#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 11 };
	int a = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = i+1; j < sz ; j++)
		{
			if (arr[i] + arr[j] == a)
			{
				printf("[%d,%d]\n", i, j);
			}
		}
	}
	return 0;
}





//int reverse(int a)//逆序
//{
//	int sum = 0;
//	int s = 0;
//	while (a)
//	{
//		s = a % 10;
//		sum = sum * 10 + s;
//		a = a / 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d\n", reverse(a));
//	return 0;
//}




//int Div357()//357整除
//{
//		int i = 0;
//		for (i = 0; i < 1000; i++)
//		{
//			if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0)
//			printf("%d ", i);
//		}
//}
//
//int main()
//{
//	Div357();
//	return 0;
//}

//int Sum(int a)//1累加到参数
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= a; i++)
//	{
//		sum = sum + i;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int sum=Sum(a);
//	printf("%d\n", sum);
//	return 0;
//}

//void Mul_table(int a)//乘法表
//{
//	int i = 1;
//	for (i = 1; i <= a; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	Mul_table(a);
//	return 0;
//}

//int MAX(int a, int b, int c)//三个数输出最大值
//{
//	if (a < b)
//	{
//		a = b;
//	}
//	if (a<c)
//	{
//		a = c;
//	}
//	return a;
//}
//
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	int ret=MAX(a, b, c);
//	printf("%d\n", ret);
//	return 0;
//}



//int sum()//应用题2
//{
//	int i, j, s;
//	int sum = 0;
//	
//	for (i = 1; i <= 100; i++)
//	{
//		s = 0;
//		for (j = 0; j < i; j++)
//		{
//			s = s + i;
//		}
//		sum = sum + s;
//	}
//		return sum;
//}
//
//int main()
//{
//	int a=sum();
//	printf("%d\n", a);
//	return 0;
//}

//void Find_carnum()
//{
//	int i = 0;
//	for (i = 1; i <9999; i++)
//	{
//		if (i / 1000 == (i / 100) % 10)//判断前两个数字是否相等
//		{
//			if (i % 10 == (i % 100) / 10 && i % 10 != i / 1000)//判断后两个数字是否相等并且不与前两个数字相等
//			{
//				int j = 0;
//				for (j = 1; j <= i;j++)//判断车牌是否是一个整数的平方
//				{
//					if (i == j*j)
//					{
//						printf("%#04d ", i);
//					}
//				}
//			}
//
//		}
//	}
//}
//
//
//int main()
//{
//	Find_carnum();
//	return 0;
//}



