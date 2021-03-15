#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"


//��ջ
void Pushstack(Stack &S, SElemtype T)
{
	//�ж�ջ��
	if (S.top == MAXSIZE)
	{
		perror("ջ��!");
		return;
	}
	S.data[S.top] = T;
	S.top++;
}

//��ջ
void Popstack(Stack &S, BTnode* &q)
{
	//�ж��Ƿ��ǿ�ջ
	if (S.top == S.base)
	{
		perror("��ջ!");
		return ;
	}
	S.top--;
	q = S.data[S.top];
}

//�ж�ջ��
bool Stackempty(Stack S)
{
	if (S.top == S.base)
	{
		return true;
	}
	return false;
}

