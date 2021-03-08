#ifndef _SNAKE_
#define _SNAKE_

#define ROWS 22
#define COLS 22

#define SIDE 25

//ÉßµÄ½Úµã
typedef struct Snakenode
{
	int x;
	int y;
	struct Snakenode* next;
	struct Snakenode* piror;
}Snakenode,*Snakehead,Food;

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<graphics.h>

void Initgame();
void Initmap();
void Initsnake();
void Displaygame();
void Displaymap();
void Displaysnake();
void Displayfood();
void Snakemove();
void changedir();
int Is_Eatfood();
void Insersnake();
int Is_crash();
void Initdraw();

extern int Dir;
extern int Foodnum;
extern Snakehead H;
#endif