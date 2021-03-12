#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//KMP算法

//计算next值
int *getnext(char* T)
{
	int *next = new int[strlen(T)];
	int s = 0;
	int t = -1;
	next[0] = -1;
	while (s < strlen(T) - 1)
	{
		if (t == -1 || T[s] == T[t])
		{
			s++;
			t++;
			if (T[s] != T[t])
				next[s] = t;
			else
				next[s] = next[t];
		}
		else
		{
			t = next[t];
		}
	}
	return next;
}

int indexKMP(char* S, char* T)
{
	int *next = getnext(T);
	int s = 0;
	int t = 0;
	while (s < strlen(S) && t < (int)strlen(T))
	{
		if (t == -1 || S[s] == T[t])
		{
			s++;
			t++;
		}
		else
		{
			t = next[t];
		}
	}
	delete next;
	if (t != strlen(T))
		return -1;//没有找到
	else
		return s - t ;
}

int main()
{

	char S[] = {"bbabcaabcabbaccbaaccbab"};
	char T[] = {"bcaa"};
	int a = indexKMP(S, T);
	return 0;
}
