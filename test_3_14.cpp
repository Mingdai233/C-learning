#define _CRT_SECURE_NO_WARNINGS 1

#include"Bitree.h"
#include"Stack.h"
#include<stdio.h>


int main()
{
	Bitree T,S;
	CreateBitree(T);
	//Levelodertraverse(T);
	int a = Bitreedepth(T);
	int b = Leadcount(T);
	Inodertraverses(T);
	Bitreecopy(T, S);
	Inodertraverse(S);
	return 0;
}



