#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//
//int Fbi(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c=1;
//	if (n > 2)
//	{
//		for (int i = 0; i < n - 2; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//	}
//	return c;
//}


int Fbi(int n)
{
	if (n > 2)
		return Fbi(n - 1) + Fbi(n - 2);
	else
		return 1;
}



int main()
{
	int n = 0;
	printf("求第n个斐波那契数:");
	scanf("%d", &n);
	int ret=Fbi(n);
	printf("%d\n", ret);
	return 0;
}
//double nmulk(int n, int k)
//{
//	if (k > 0)
//	{
//		return n*nmulk(n, k - 1);
//	}
//	else if (k==0)
//		return 1;
//	else
//	{
//		return (1.0 / (nmulk(n, -k)));
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret=nmulk(n, k);
//	printf("%lf\n", ret);
//	return 0;
//}
//int Digitsum(int n)
//{
//	if (n / 10 != 0)
//		return n % 10 + Digitsum(n / 10);
//	else
//		return n%10;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret=Digitsum(n);
//	printf("%d", ret);
//	return 0;
//}


//void str_reverse(char* arr)
//{
//	int i = 0;
//	for (i = 0; arr[i] != '\0'; i++)
//	{
//
//	}
//	int left = 0;
//	int right = i - 1;
//	while (left <= right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int my_strlen(char arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; arr[i] != '\0'; i++)
//	{
//
//	}
//		return i;
//}

//void str_reverse(char arr[])
//{
//	int len = my_strlen(arr);
//	char tmp = arr[0];
//	arr[0] = arr[len-1];
//	arr[len-1] = '\0';
//	if (len >= 2)
//	{
//		str_reverse(arr + 1);
//	}
//	arr[len-1] = tmp;
//}
//
//
//
//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//	{
//		return  1+my_strlen(arr + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
////
//int main()
//{
//	char arr[] = "abcdefg";
//	 str_reverse(arr);
//		 printf("%s ", arr);
//	return 0;
//}
//int factorial(int n)
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret = ret*i;
//	}
//	return ret;
//}

//int factorial(int n)
//{
//	int ret = 1;
//	if (n>1)
//	ret = n*factorial(n-1);
//	return ret;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret=factorial(n);
//	printf("%d\n", ret);
//	return 0;
//}
//void print(int n)
//{
//	if (n / 10 != 0)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//		print(n);
//	return 0;
//}

//void mul_table(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	mul_table(n);
//	return 0;
//}

//void Is_prime()
//{
//	int j = 0;
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for ( j = 2; j <=sqrt (i); j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j>sqrt(i))
//		{
//			printf("%d ", i);
//		}
//	}
//}
//
//
//int main()
//{
//	Is_prime();
//	return 0;
//}

//void print(int n)
//{
//	printf("偶数位:");
//	for (int i = 0; i <32; i += 2)
//	{
//		printf("%d ", (n >> i & 1));
//	}
//	printf("\n");
//	printf("奇数位:");
//	for (int i = 1; i < 32; i += 2)
//	{
//		printf("%d ", (n >> i & 1));
//	}
//
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}
//int count_one(int n)//求二进制（补码）中1的个数
//{
//	int count = 0;
//	while (n)
//	{
//		n=n&(n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count = count_one(a);
//	printf("%d\n", count);
//	return 0;
//}