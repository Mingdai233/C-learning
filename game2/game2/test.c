#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	char date[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ�����̣����ݴ洢��/��ʾ�̣�
	InitBoard(date, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//����
	SetBoom(date, ROW, COL);
	//��ӡ����
	DisPlayboard(show, ROW, COL);
	//DisPlayboard(date, ROW, COL);//�����ڲ鿴���ݴ洢��
	//����
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
		printf("������:");
		scanf("%d", &input);
		while ((c = getchar()) != '\n' && c != EOF);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
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