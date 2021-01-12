#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

void SetBoom(char board[ROWS][COLS], int row, int col)
{
	//'1'���洢��
	int count = COUNT;
	while (count)
	{
		int x = rand() % row + 1;//��1-9����
		int y = rand() % col + 1;//��1-9����
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


void DisPlayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void FindBoom(char date[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 1;
	while (i<=ROW*COL-COUNT)
	{
		i++;
		printf("����������:");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (date[x][y] == '1')
			{
				printf("ը������Ϸ����\n");
				DisPlayboard(date, ROW, COL);
				break;
			}
			else
			{
				show[x][y] = BoomCount(date, x, y) + '0';
				DisPlayboard(show, ROW, COL);
			}

		}
		else
		{
			printf("�Ƿ�����");
		}
	}
	if (i == ROW*COL - COUNT + 1)
	{
		printf("��ϲ�㣬���׽���\n");
	}
}
int BoomCount(char date[ROWS][COLS], int x, int y)
{
	//������Χ�˸�һ���ж�����
	 return date[x - 1][y] +
		date[x - 1][y - 1] +
		date[x][y - 1] +
		date[x + 1][y - 1] +
		date[x + 1][y] +
		date[x + 1][y + 1] +
		date[x][y + 1] +
		date[x - 1][y + 1] - 8 * '0';
}

//void OpenZero(char date[ROWS][COLS],char show[ROWS][COLS],int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = x - 1; i <= x + 1; i++)
//	{
//		for (j = y - 1; j <= y + 1; j++)
//		{
//			IsBoom(date[ROWS][COLS], show[ROWS][COLS], i, j);
//			if (show[x][y] == '0')
//			{
//				OpenZero(date[ROWS][COLS], show[ROWS][COLS], x, y);
//			}
//			else
//			{
//				IsBoom(date[ROWS][COLS], show[ROWS][COLS], i, j);
//			}
//		}
//	}
//}
