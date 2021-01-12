#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}

int main()
{
	int ret = 0;
	char arr[] = "little fat";
	ret=my_strlen(arr);
	printf("%d\n", ret);
	return 0;
}


//struct STU
//{
//	char name[20];
//	int age;
//	char ID[20];
//};
//
//int main()
//{
//	struct STU s1={"ÖíÖíÏÀ",18,"20201413"};
//	struct STU* ps = &s1;
//	printf("%s\n", ps->name);
//	printf("%d\n", ps->age);
//	printf("%s\n", ps->ID);
//	//printf("%s\n",s1.name);
//	//printf("%d\n",s1.age);
//	//printf("%s\n",s1.ID);
//	return 0;
//}