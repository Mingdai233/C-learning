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
	InitBoard(board, ROW, COL);//��ʼ������
	DispalyBoard(board,ROW,COL);//��ӡ����
	//����
	while (1)
	{
		PlayerMove(board,ROW,COL);//����ƶ�
		DispalyBoard(board, ROW, COL);//��ӡ����
		ret = Is_Win(board, ROW, COL);//�ж��Ƿ�Ӯ��
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//�����ƶ�
		DispalyBoard(board, ROW, COL);//��ӡ����
		ret = Is_Win(board, ROW, COL);//�ж��Ƿ�Ӯ��
		if (ret != 'C')
		{
			break;
		}
	}
	if ('*'==ret)
	{
		printf("���ʤ��!\n");
	}
	else if ('#' ==ret)
	{
		printf("����ʤ����\n");
	}
	else
	{
		printf("ƽ�֡�\n");
	}

}
void game2()
{
	char ret;
	char board[ROW][COL] = { 0 };
	srand((unsigned int)time(NULL));
	InitBoard(board, ROW, COL);//��ʼ������
	DispalyBoard(board, ROW, COL);//��ӡ����
	//����
	while (1)
	{
		ComputerMove(board, ROW, COL);//�����ƶ�
		DispalyBoard(board, ROW, COL);//��ӡ����
		ret = Is_Win(board, ROW, COL);//�ж��Ƿ�Ӯ��
		if (ret != 'C')
		{
			break;
		}
		PlayerMove(board, ROW, COL);//����ƶ�
		DispalyBoard(board, ROW, COL);//��ӡ����
		ret = Is_Win(board, ROW, COL);//�ж��Ƿ�Ӯ��
		if (ret != 'C')
		{
			break;
		}
	}
	if ('*' == ret)
	{
		printf("���ʤ��!\n");
	}
	else if ('#' == ret)
	{
		printf("����ʤ����\n");
	}
	else
	{
		printf("ƽ�֡�\n");
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
		printf("���롮1�����棬���롮0���˳���Ϸ\n");
		printf("������:");
		scanf("%d", &input1);
		while ((c = getchar()) != '\n' && c != EOF);
		switch (input1)
		{
		case 1:
			printf("��ѡ��1.���ֻ���2.����\n");
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
				printf("�������\n");
				break;
			}while (input2);
			break;
		case 0:
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input1);
	return 0;
}