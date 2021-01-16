#define _CRT_SECURE_NO_WARNINGS 1





#include<stdio.h>
#include<math.h>
#include"binary_search.h"


//汉诺塔问题（n为盘子数量）
//1，当n == 1时，只需从a移动到c；
//2，当n > 1时：
//将n - 1个盘子由a经c移到b
//将最大的盘子由a移到c
//将n - 1个盘子由b经a移到c
//hanoi(n,    x,    y,    z);
//    盘数   由     经     到


void move(char x, char y)
{
	printf("%c->%c\n", x, y);
}
void hanoi(int n, char a, char b, char c)
{
	if (1 == n)
	{
		move(a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}
int main()
{
	int n = 0;
	printf("请输入盘子的数量:");
	scanf("%d",&n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
//int Fbi2(int x)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	int i = 0;
//	if (1==x)
//	{
//		return 1;
//	}
//	else
//	{
//		for (i = x; i>1; i--)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//	}
//		return c;
//}
//int Fbi(int x)
//{
//	if (x > 1)
//	{
//		return Fbi(x - 1) + Fbi(x - 2);
//	}
//	else
//	{
//		return 1;
//	}
//}


int main()
{
	int k = 0;
	int ret = 0;
	scanf("%d", &k);
	ret=Fbi2(k);
	printf("%d\n", ret);
	return 0;
}
//
//int my_strlen(char* s)
//{
//	if (*s != '\0')
//	{
//		return 1 + my_strlen(s+1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char arr[] = "ming dai";
//	printf("%d\n", my_strlen(arr));
//}
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x%10);
//}
////print(123)   4
////print(12)  3 4
////print(1) 2 3 4
//
//int main()
//{
//	int s = 0;
//	scanf("%d", &s);
//	print(s);
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int se = sizeof(arr)/sizeof(arr[0]);
//	int k = 9;
//	int ret = 0;
//	ret=binary_search(arr, k,se);
//	if (-1 == ret)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%d\n", ret);
//	}
//	return 0;
//}

//int is_leap_year(int n)
//{
//	//能被4整除但不能被100整除和可以被400整除为闰年
//	if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i =1000; i <= 2000; i++)
//	{
//		if (ix_leap_year(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int is_prime(int n)
//{
//	int ret = 0;
//	int j = 2;
//	for (j = 2; j <=sqrt(n); j++)
//	{
//		if (n%j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}