#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"


//»Î’ª
void Pushstack(Stack &S, SElemtype T)
{
	//≈–∂œ’ª¬˙
	if (S.top == MAXSIZE)
	{
		perror("’ª¬˙!");
		return;
	}
	S.data[S.top] = T;
	S.top++;
}

//≥ˆ’ª
void Popstack(Stack &S, BTnode* &q)
{
	//≈–∂œ «∑Ò «ø’’ª
	if (S.top == S.base)
	{
		perror("ø’’ª!");
		return ;
	}
	S.top--;
	q = S.data[S.top];
}

//≈–∂œ’ªø’
bool Stackempty(Stack S)
{
	if (S.top == S.base)
	{
		return true;
	}
	return false;
}

