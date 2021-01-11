#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"

void menu()
{
	printf("*************************\n");
	printf("*****1.play   0.exit*****\n");
	printf("*************************\n");
}
void game1()
{
	char ret;
	char board[ROW][COL] = { 0 };
	srand((unsigned int)time(NULL));
	InitBoard(board, ROW, COL);//初始化棋盘
	DispalyBoard(board,ROW,COL);//打印棋盘
	//下棋
	while (1)
	{
		PlayerMove(board,ROW,COL);//玩家移动
		DispalyBoard(board, ROW, COL);//打印棋盘
		ret = Is_Win(board, ROW, COL);//判断是否赢了
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑移动
		DispalyBoard(board, ROW, COL);//打印棋盘
		ret = Is_Win(board, ROW, COL);//判断是否赢了
		if (ret != 'C')
		{
			break;
		}
	}
	if ('*'==ret)
	{
		printf("玩家胜利!\n");
	}
	else if ('#' ==ret)
	{
		printf("电脑胜利。\n");
	}
	else
	{
		printf("平局。\n");
	}

}
void game2()
{
	char ret;
	char board[ROW][COL] = { 0 };
	srand((unsigned int)time(NULL));
	InitBoard(board, ROW, COL);//初始化棋盘
	DispalyBoard(board, ROW, COL);//打印棋盘
	//下棋
	while (1)
	{
		ComputerMove(board, ROW, COL);//电脑移动
		DispalyBoard(board, ROW, COL);//打印棋盘
		ret = Is_Win(board, ROW, COL);//判断是否赢了
		if (ret != 'C')
		{
			break;
		}
		PlayerMove(board, ROW, COL);//玩家移动
		DispalyBoard(board, ROW, COL);//打印棋盘
		ret = Is_Win(board, ROW, COL);//判断是否赢了
		if (ret != 'C')
		{
			break;
		}
	}
	if ('*' == ret)
	{
		printf("玩家胜利!\n");
	}
	else if ('#' == ret)
	{
		printf("电脑胜利。\n");
	}
	else
	{
		printf("平局。\n");
	}

}


int main()
{
	char c;
	int input1;
	int input2;
	do
	{
		menu();
		printf("输入‘1’游玩，输入‘0’退出游戏\n");
		printf("请输入:");
		scanf("%d", &input1);
		while ((c = getchar()) != '\n' && c != EOF);
		switch (input1)
		{
		case 1:
			printf("请选择1.先手还是2.后手\n");
			scanf("%d", &input2);
			while ((c = getchar()) != '\n' && c != EOF);
			switch (input2)
				do
			{
			case 1:
				game1();
				break;
			case 2:
				game2();
				break;
			default:
				printf("输入错误\n");
				break;
			}while (input2);
			break;
		case 0:
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input1);
	return 0;
}