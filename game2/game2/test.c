#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	char date[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘（数据存储盘/显示盘）
	InitBoard(date, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//放雷
	SetBoom(date, ROW, COL);
	//打印棋盘
	DisPlayboard(show, ROW, COL);
	//DisPlayboard(date, ROW, COL);//可用于查看数据存储盘
	//排雷
	FindBoom(date, show, ROW, COL);
}


void test()
{
	char c;
	int input = 0;
	do
	{
		printf("************************************\n");
		printf("************   1.play  *************\n");
		printf("************   0.exit  *************\n");
		printf("************************************\n");
		printf("请输入:");
		scanf("%d", &input);
		while ((c = getchar()) != '\n' && c != EOF);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
}



int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}