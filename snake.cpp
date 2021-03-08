#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

int map[ROWS][COLS] = { 0 };
enum resoure{FLOOR,WALL,SNAKE,FOOD};
enum dir{up,down,left,right};
int snakelength = 0;//蛇长
int Foodnum = 0;
int Dir = down;
Food F;//食物
int score = 0;//得分
Snakehead H;

//初始化地图
void Initmap()
{
	//赋墙
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			
			if (0 == i || 0 == j || ROWS-1 == i || COLS-1 == j)
			{
				map[i][j] = WALL;
			}
			else
			{
				map[i][j] = FLOOR;
			}
		}
	}
}

//初始化蛇
void Initsnake()
{
	//释放内存(上一把)
	if (snakelength > 0)
	{
		Snakehead ptemp = H->next;
		for (int i = 0; i < snakelength; i++)
		{
			free(H);
			ptemp->piror = NULL;
			H = ptemp;
			if (H != NULL)
				ptemp = H->next;
		}
	}
	snakelength = 3;
	//蛇头
	H = (Snakehead)malloc(sizeof(Snakenode));
	H->next = H;
	H->piror = H;
	H->x = 10;
	H->y = 10;
	//蛇身
	Snakenode* p = H;
	for (int i = 0; i < snakelength - 1; i++)
	{
		//双循环链表
		Snakenode* Newnode = (Snakenode*)malloc(sizeof(Snakenode));
		Newnode->piror = p;
		Newnode->next = H;
		p->next = Newnode;
		H->piror = Newnode;
		Newnode->x = p->x;
		Newnode->y = p->y+1;
		p = p->next;
	}
}
//初始化游戏
void Displaymap()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			switch (map[i][j])
			{
			case FLOOR:
				setfillcolor(WHITE);
				setlinecolor(WHITE);
				fillrectangle(j*SIDE,i*SIDE,(j+1)*SIDE,(i+1)*SIDE);
				break;
			case WALL:
				setfillcolor(DARKGRAY);
				setlinecolor(DARKGRAY);
				fillrectangle(j*SIDE, i*SIDE, (j + 1)*SIDE, (i + 1)*SIDE);
				break;
			case SNAKE:
				setfillcolor(BLUE);
				setlinecolor(BLUE);
				fillrectangle(j*SIDE, i*SIDE, (j + 1)*SIDE, (i + 1)*SIDE);
				if (i == H->x&&j == H->y)
				{
					setfillcolor(RED);
					setlinecolor(RED);
					fillrectangle(j*SIDE, i*SIDE, (j + 1)*SIDE, (i + 1)*SIDE);
				}
				break;
			case FOOD:
				setfillcolor(GREEN);
				setlinecolor(GREEN);
				fillrectangle(j*SIDE, i*SIDE, (j + 1)*SIDE, (i + 1)*SIDE);
				break;
			default:
				break;
			}
		}
	}
}

//绘制蛇
void Displaysnake()
{
	Snakenode* p = H;
	for (int i = 0; i < snakelength; i++)
	{
		map[p->x][p->y] = SNAKE;
		p = p->next;
	}
}

//食物生成
void Displayfood()
{
	F.next = NULL;
	F.piror = NULL;
	while (!Foodnum)
	{
		F.x = rand() % (ROWS - 2) + 1;
		F.y = rand() % (COLS - 2) + 1;
		if (map[F.x][F.y] != SNAKE && (F.x != 1 && F.y != 1) && (F.x != ROWS - 2 && F.y != COLS - 2) && (F.x != 1 && F.y != COLS - 2) && (F.x != ROWS - 2 && F.y != 1))
		{
			map[F.x][F.y]=FOOD;
			Foodnum++;
		}
	}
}

void Snakemove()
{
	Snakenode* p = H->piror;
	for (int i = snakelength; i > 1; i--)
	{
		p->x=p->piror->x;
		p->y = p->piror->y;
		p = p->piror;
	}
	//头后动
	switch (Dir)
	{
	case up:
		H->x -= 1;
		break;
	case down:
		H->x += 1;
		break;
	case left:
		H->y -= 1;
		break;
	case right:
		H->y += 1;
		break;
	default:
		break;
	}
}

void changedir()
{
	switch (_getch())
	{
	case'w':
	case'W':
		if (Dir != down)
			Dir=up;
		break;
	case's':
	case'S':
		if (Dir != up)
			Dir=down;
		break;
	case'a':
	case'A':
		if (Dir != right)
			Dir=left;
		break;
	case'd':
	case'D':
		if (Dir != left)
			Dir=right;
		break;
	default:
		break;
	}
}


//吃食物
int Is_Eatfood()
{
	switch (Dir)
	{
	case up:
		if (map[H->x - 1][H->y] == FOOD)
			return 1;
	case down:
		if (map[H->x + 1][H->y] == FOOD)
			return 1;
	case left:
		if (map[H->x][H->y - 1] == FOOD)
			return 1;
	case right:
		if (map[H->x][H->y + 1] == FOOD)
			return 1;
	default:
		break;
	}
	return 0;
}

//增加蛇身
void Insersnake()
{
	Snakehead N = (Snakehead)malloc(sizeof(Snakenode));
	N->x = F.x;
	N->y = F.y;
	N->next = H;
	N->piror = H->piror;
	H->piror = N;
	H = N;
	snakelength++;//蛇身长增加
	Foodnum--;//食物数量减
	score++;
}

//是否碰撞
int Is_crash()
{
	if (H->x<1 || H->x>ROWS - 2 || H->y<1 || H->y>COLS - 2)
	{
		char s[300];
		sprintf(s, "撞墙!\n得分:%d!\n是否重新游戏!", score);
		if (IDYES == MessageBox(GetHWnd(), s, "提示", MB_YESNO))
		{
			Initgame();
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	Snakenode* ptemp = H->next;
	for (int i = 1; i < snakelength;i++)
	{
		if (ptemp->x == H->x&&ptemp->y == H->y)
		{
			char s[300];
			sprintf(s, "撞身!\n得分:%d!\n是否重新游戏!", score);
			if (IDYES == MessageBox(GetHWnd(), s, "提示", MB_YESNO))
			{
				Initgame();
			}
			else
			{
				exit(EXIT_SUCCESS);
			}
		}
		ptemp = ptemp->next;
	}
	return 1;
}


//初始化游戏
void Initgame()
{
	//初始化分数
	score = 0;
	//初始化食物
	Foodnum = 0;
	//初始化地图
	Initmap();
	//初始化蛇
	Initsnake();
}
void Displaygame()
{
	system("cls");
	srand((unsigned int)time(NULL));
	Displaysnake();
	Displayfood();
	Displaymap();
	map[H->piror->x][H->piror->y] = FLOOR;//清尾
}