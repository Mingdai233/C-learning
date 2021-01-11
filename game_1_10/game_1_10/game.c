#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void InitBoard(char board[ROW][COL], int row,int col)
{
	//��ʼ������
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void  DispalyBoard(char board[ROW][COL], int row, int col)
{
	//��ӡ����
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j< col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	//����ƶ�
	int x = 0;
	int y = 0;
	char c;
	while (1)
	{
		printf("��������������:");
		scanf("%d %d",&x,&y);
		while ((c = getchar()) != '\n' && c != EOF);
		if (0 < x && x<=ROW && y>0 && y <= COL)
		{
			if (board[x-1][y-1] != ' ')
			{
				printf("��λ����������\n");
			}
			else
			{
				system("cls");
				printf("�����:\n");
				board[x-1][y-1] = '*';
				break;
			}
		}
		else
		{
			printf("�������벻�Ϸ�\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	//�����ƶ�
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % ROW;
		if (board[x][y] == ' ')
		{
			printf("������:\n");
			board[x][y] = '#';
			break;
		}
	}
}

char Is_Win(char board[ROW][COL], int row, int col)
{
	//�ж���Ӯ����
	//���Ӯ'*'
	//����Ӯ'#'
	//ƽ��'P'
	//����'C'
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				if (board[i][j] == ' ')
					return 'C';
			}
		}
	return 'P';
}
