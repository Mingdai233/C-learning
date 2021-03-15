#ifndef _STACK_H_
#define _STACK_H_
#include "Bitree.h"
#include<stdbool.h>


typedef struct stack
{
	int base = 0;
	int top = 0;
	SElemtype data[MAXSIZE];
}Stack;

void Pushstack(Stack &S, SElemtype T);
void Popstack(Stack &S, BTnode* &q);
bool Stackempty(Stack S);
#endif 



