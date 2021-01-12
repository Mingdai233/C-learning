#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10 //À×Êý


#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisPlayboard(char board[ROWS][COLS],int row,int col);
void SetBoom(char board[ROWS][COLS], int row, int col);
void FindBoom(char date[ROWS][COLS],char show[ROWS][COLS] ,int row ,int col );
int BoomCount(char date[ROWS][COLS],int row, int col);

