#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


char* my_strcpy(char* dest, const char* str)
{
	char* ret=dest;
	assert(dest != NULL && str != NULL);
	while (*dest++ = *str++)
	{
		;
	}
	return ret;
}


int main()
{
	char arr1[] = "***************";
	char arr2[] = "fatboy";
	printf("%s\n", my_strcpy(arr1, arr2));
	system("pause");
	return 0;
}


//void my_strcpy(char* dest, char* str)
//{
//	assert(dest != NULL && str != NULL);
//	while (*dest++ = *str++)
//	{
//		;
//	}
//}

//void my_strcpy(char* dest, char* str)
//{
//	while (*dest++ = *str++)
//	{
//		;
//	}
//}


//void my_strcpy(char* dest, char* str)
//{
//	while (*str != '\0')
//	{
//		*dest = *str;
//		dest++;
//		str++;
//	}
//	*dest = *str;
//}

//int main()
//{
//	char arr1[] = "***************";
//	char arr2[] = "fatboy";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}


//struct Stu
//{
//	char name[20];
//	short age;
//	char tele[15];
//	char sex[5];
//
//};
//
//
//typedef struct Work
//{
//	char location[20];
//	struct Stu s;
//}Work;
//
//
//void print(Work* s)
//{
//	printf("%s\n", s->location);
//	printf("%s\n", s->s.name);
//	printf("%d\n", s->s.age);
//	printf("%s\n", s->s.tele);
//	printf("%s\n", s->s.sex);
//}
//
//int main()
//{
//	Work s= { "广东省佛山市", { "小明", 18, "13788888888", "男" } };
//	print(&s);
//	system("pause");
//	return 0;
//}