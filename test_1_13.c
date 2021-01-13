#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

int count_one(int x)
{
	int count=0;
	int a = 1;
	for (int i = 0; i < 32; i++)
	{
		if (x&a == 1)
		{
			count++;
		}
		x >>= 1;
	}
	return count;
}


void print(int* pa,int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(pa + i));
	}
}



int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("a=%d b=%d", a, b);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int arr[32] = { 0 };
//	scanf("%d", &a);
//	int b = a;
//	for (int i = 0; i < 32; i++)
//	{
//		arr[31 - i] = a & 1;
//		a >>= 1;
//	}
//	for (int i = 0; i < 32; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 32; i++)
//	{
//		if (arr[31 - i] == 1)
//		{
//			arr[31 - i] = 0;
//		}
//		else
//		{
//			arr[31 - i] = 1;
//		}
//		a >>= 1;
//	}
//	for (int i = 0; i < 32; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 1;
//	int count = 0;
//	scanf("%d%d", &a, &b);
//	c = a^b;
//	count = count_one(c);
//	printf("%d\n", count);
//	return 0;
//}

//int i;//全局变量不初始化值为0
//
//int main()
//{
//	i--;
//	//10000000000000000000000000000001
//	//11111111111111111111111111111110
//	//11111111111111111111111111111111
//	if (i > sizeof(i))//有符号数转化为无符号数再与无符号数运算
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}
//void exchange(int arr1[], int arr2[], int sz)
//{
//	int tmp;
//
//	for (int i = 0; i < sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//void init(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[],int sz)
//{
//	int left = 0;
//	int right = sz-1;
//	while (left <= right)
//	{
//		int tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;
//		left = left + 1;
//		right = right - 1;
//	}
//}
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int arr2[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	print(arr1, sz);
//	print(arr2, sz);
//	exchange(arr1, arr2, sz);
//	print(arr1, sz);
//	print(arr2, sz);
//}
//int main()
//{
//	int arr[] = { 10, 9, 11, 7, 6, 5, 4,13, 2, 1 };
//	int se = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 1; i <= se - 1; i++)
//	{
//		int count = 0;
//		for (int j = 0; j < se- i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			break;
//		}
//	}
//	for (int i = 0; i < se; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}