#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//void qsort(void*base,  num,     width,  int(*compare)(const void*, const void*));
//   要排序的数组指针  元素个数  元素大小 比较元素大小的函数

typedef struct STU
{
	char name[20];
	int age;
}STU;

void Swap(char*p1,char* p2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}

void Bubble_sort(void*base, int sz, int width,int(*cmp)( void *e1, void*e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width) > 0)
			{
				Swap((char*)base + j*width, (char*)base + (j + 1)*width,width);//交换
			}
		}
	}
}



int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_float(const void*e1, const void*e2)
{
	if (*(float*)e1 > *(float*)e2)
		return 1;
	else if (*(float*)e1 == *(float*)e2)
		return 0;
	else
		return -1;
}
int cmp_STU_by_age(const void*e1, const void*e2)
{
	return (*(STU*)e1).age - (*(STU*)e2).age;//((STU*)e1)->age-((STU*)e1)->age
}

int cmp_STU_by_name(const void*e1, const void*e2)
{
	return strcmp((*(STU*)e1).name,((STU*)e1)->name);
}

void test1()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (;i<sz;i++)
	printf("%d ", arr[i]);
	system("pause");
}

void test2()
{
	float arr[] = { 1.0, 3.0, 5.0, 7.0, 9.0, 2.0, 4.0, 6.0, 8.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);
	int i = 0;
	for (; i<sz; i++)
		printf("%f ", arr[i]);
	system("pause");
}
void test3()
{
	STU s[3] = { { "Tom", 12 }, { "Cow", 31 }, { "Fat", 26 } };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_STU_by_age);
	qsort(s, sz, sizeof(s[0]), cmp_STU_by_name);
	int i = 0;
	for (; i < sz; i++)
	{
		printf("%s ", s[i].name);
		printf("%d ", s[i].age);
		printf("\n");
	}
}
void test4()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (; i<sz; i++)
		printf("%d ", arr[i]);
	system("pause");
}
void test5()
{
	STU s[3] = { { "Tom", 12 }, { "Cow", 31 }, { "Fat", 26 } };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_STU_by_age);
	//qsort(s, sz, sizeof(s[0]), cmp_STU_by_name);
	//Bubble_sort(s, sz, sizeof(s[0]), cmp_STU_by_age);
	Bubble_sort(s, sz, sizeof(s[0]), cmp_STU_by_age);
	int i = 0;
	for (; i < sz; i++)
	{
		printf("%s ", s[i].name);
		printf("%d ", s[i].age);
		printf("\n");
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	 test5();
	return 0;
}
//char* my_strcpy1(char* arr, const char* str)
//{
//	char* ret = arr;
//	assert(arr != NULL);
//	assert(str != NULL);
//	while (*arr++ =*str++)
//	{
//		;
//	}
//	return ret;
//}
//char* my_strcpy2(char* arr, const char* str)
//{
//	char* ret = arr;
//	assert(arr != NULL);
//	assert(str != NULL);
//	while (*arr++ = *str++)
//	{
//		;
//	}
//	return ret;
//}char* my_strcpy3(char* arr, const char* str)
//{
//	char* ret = arr;
//	assert(arr != NULL);
//	assert(str != NULL);
//	while (*arr++ = *str++)
//	{
//		;
//	}
//	return ret;
//}char* my_strcpy4(char* arr, const char* str)
//{
//	char* ret = arr;
//	assert(arr != NULL);
//	assert(str != NULL);
//	while (*arr++ = *str++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[] = "************";
//	char arr2[] = "little";
//	char*(*pf)(char*, const char*)=my_strcpy1;
//	char*(*pfarr[4])(char*, const char*) = { my_strcpy1, my_strcpy2, my_strcpy3, my_strcpy4 };
//		printf("%s\n", pfarr[2](arr1,arr2));
//		system("pause");
//	return 0;
//}