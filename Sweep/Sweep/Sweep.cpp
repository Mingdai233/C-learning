#define _CRT_SECURE_NO_WARNINGS 1

#include"Sweep.h"
//初始化游戏
int **Initgame()
{
	//选择难度界面
	MOUSEMSG m;
	initgraph(400, 600, EW_SHOWCONSOLE);
	setbkcolor(LIGHTGRAY);
	cleardevice();
	setfillcolor(DARKGRAY);
	setlinecolor(BLACK);
	fillrectangle(100, 250, 300, 300);
	fillrectangle(100, 350, 300, 400);
	RECT r1 = { 0, 0, 400, 100 };
	RECT r2 = { 0, 100, 400, 200 };
	RECT r3 = { 100, 250, 300, 300 };
	RECT r4 = { 100, 350, 300, 400 };
	settextcolor(BLUE);
	settextstyle(64, 0, "Consolas");
	drawtext(_T("扫雷"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextcolor(BLACK);
	settextstyle(32, 0, "宋体");
	drawtext(_T("!请选择难度!"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("简单"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("困难"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1)
	{
		m = GetMouseMsg();
		//简单
		if (m.x >= 100 && m.x <= 300 && m.y >= 250 && m.y <= 300)
		{
			if (m.uMsg == WM_LBUTTONUP)
			{
				int**p = InitData(SROW,SCOL,EASY);
				Initgraphics(SROW,SCOL);
				return p;
			}
		}
		//困难
		if (m.x >= 100 && m.x <= 300 && m.y >= 350 && m.y <= 400)
		{
			if (m.uMsg == WM_LBUTTONUP)
			{
				int **p = InitData(ROWS,COLS,HARD);
				Initgraphics(ROWS,COLS);
				return p;
			}
		}
	}
}
	//1.初始化数据
int **InitData(int rows,int cols,int boom)
{
    int i = 0;
    int j = 0;
	int count = 0;
    //1.申请一个二维数组
    int **map = (int**)malloc(sizeof(int*)*rows);
    for (i = 0; i < rows;i++)
    {
	   map[i] = (int*)malloc(sizeof(int)*cols);
    }
	//2.初始化数组数据
    for (i = 0; i < rows; i++)
    {
	   for (j = 0; j < cols; j++)
	   {
		   //墙
		   if (0 == i || rows - 1 == i || 0 == j || cols - 1 == j)
		   {
			   map[i][j] = WALL;
		   }
		   //空地
		   else
		   {
			   map[i][j] = NULL;
		   }
	   }
    }
	//3.置雷(在游戏区域内)
	srand((unsigned int)time(NULL));
	while (count != boom)
	{
		int x = rand() % (rows - 2) + 1;
		int y = rand() % (cols - 2) + 1;
		if (map[x][y] != BOOM)
		{
			map[x][y] = BOOM;
			count++;
		}
	}
	//4.数雷
	for (i = 1; i < rows - 1; i++)
	{
		for (j = 1; j < cols - 1; j++)
		{
			//判断自己不是雷
			if (map[i][j] != BOOM)
			{
				//自己周围雷的个数
				int n = 0;
				int m = 0;
				for (n = -1; n <= 1; n++)
				{
					for (m = -1; m <= 1; m++)
					{
						if (map[i + n][j + m] == BOOM)
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	 }
	//5.盖板
	for (i = 1; i < rows-1; i++)
	{
		for (j = 1; j < cols-1; j++)
		{
			map[i][j] += BORD;
		}
	}
	map[0][0] = boom;
   return map;
}
//2.初始化图像
IMAGE wall, board, flag, boom, img[10];
void Initgraphics(int rows,int cols)
{
	initgraph(cols*SIDE,rows*SIDE,SHOWCONSOLE);
	int i = 0;
	loadimage(&wall, "wall.jpg", SIDE, SIDE);
	loadimage(&board, "bord.png", SIDE, SIDE);
	loadimage(&flag, "flag.jpg", SIDE, SIDE);
	loadimage(&boom, "boom.png", SIDE, SIDE);
	char picname[100];
	for (i = 0; i < 9; i++)
	{
		sprintf(picname, "%d.png", i);
		loadimage(&img[i], picname, SIDE, SIDE);
	}
}
//绘制
void Display(int **map)
{
	Displaynum(map);
	Displaymap(map);
}

void Displaynum(int **map)
{
	int i = 0;
	int j = 0;
	if (map[0][0] == EASY)
	{
		for (i = 0; i < SROW; i++)
		{
			for (j = 0; j < SCOL; j++)
			{
				printf("%3d", map[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		for (i = 0; i < ROWS; i++)
		{
			for (j = 0; j < COLS; j++)
			{
				printf("%3d", map[i][j]);
			}
			printf("\n");
		}
	}
	printf("\n");
}

//绘制图像
void Displaymap(int **map)
{
	if (map[0][0] == EASY)
	{
		travelprint(map,SROW, SCOL);
	}
	else
	{
		travelprint(map,ROWS, COLS);
	}
}

//遍历绘图
void travelprint(int** map,int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (map[i][j] >= BORD && map[i][j] <BORD+FLAG)
			{
				putimage(j*SIDE, i*SIDE, &board);
			}
			if (map[i][j] >= BORD+FLAG)
			{
				putimage(j*SIDE, i*SIDE, &flag);
			}
			switch (map[i][j])
			{
			case 0:
				putimage(j*SIDE, i*SIDE, &img[0]);
				break;
			case 1:
				putimage(j*SIDE, i*SIDE, &img[1]);
				break;
			case 2:
				putimage(j*SIDE, i*SIDE, &img[2]);
				break;
			case 3:
				putimage(j*SIDE, i*SIDE, &img[3]);
				break;
			case 4:
				putimage(j*SIDE, i*SIDE, &img[4]);
				break;
			case 5:
				putimage(j*SIDE, i*SIDE, &img[5]);
				break;
			case 6:
				putimage(j*SIDE, i*SIDE, &img[6]);
				break;
			case 7:
				putimage(j*SIDE, i*SIDE, &img[7]);
				break;
			case 8:
				putimage(j*SIDE, i*SIDE, &img[8]);
				break;
			case BOOM:
				putimage(j*SIDE, i*SIDE, &boom);
				break;
			case WALL:
				putimage(j*SIDE, i*SIDE, &wall);
				break;
			case HARD:
				putimage(j*SIDE, i*SIDE, &wall);
				break;
			default:
				break;
			}
		}
	}
}

//游戏主循环
void game(int **map)
{

	while (Is_Win(map) != -1 && Is_Win(map) != 1)//返回-1为失败，返回1为胜利
	{
		//1.玩家操作(左键打开，右键标记)
		Playermove(map);
		//2.判断是否需要开0
		Display(map);
	}
}

void Playermove(int **map)
{
	MOUSEMSG m;
	int r = 0;
	int c = 0;
	while (1)
	{
		m = GetMouseMsg();
		if (map[0][0] == EASY)
		{
			if (m.x>SIDE && m.x<(SROW-1)*SIDE && m.y>SIDE && m.y<(SCOL-1)*SIDE)
			{
				r = m.y / SIDE, c = m.x/ SIDE;
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (map[r][c] >= BORD)
					{
						map[r][c] -= BORD;
					}
					//判断是否开0
					if (map[r][c] == 0)
					{
						Openzero(map,r,c);
					}
					break;
				}
				if (m.uMsg == WM_RBUTTONDOWN)
				{
					if (map[r][c]>=BORD && map[r][c]<BORD+FLAG)
					map[r][c] += FLAG;
					break;
				}
			}
		}
		if (map[0][0] == HARD)
		{
			if (m.x>SIDE && m.x<(ROWS - 1)*SIDE && m.y>SIDE && m.y<(COLS - 1)*SIDE)
			{
				r = m.y / SIDE, c = m.x / SIDE;
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (map[r][c] >= BORD)
					{
						map[r][c] -= BORD;
					}
					if (map[r][c] == 0)
					{
						Openzero(map, r, c);
					}
					break;
				}
				if (m.uMsg == WM_RBUTTONDOWN)
				{
					if (map[r][c] >= BORD && map[r][c]<BORD + FLAG)
					map[r][c] += FLAG;
					break;
				}
			}
		}
	}
}
//判断胜负有问题！！明天查
int Is_Win(int **map)
{
	int i = 0;
	int j = 0;
	if (map[0][0] == EASY)
	{
		int count = 0;
		for (i = 0; i < SROW; i++)
		{
			for (j = 0; j < SCOL; j++)
			{
				if (map[i][j] == BOOM)
				{
					return -1;
				}
				if (map[i][j]==BOOM+FLAG+BORD)
				{
					count++;
					if (count == EASY)
					{
						return 1;
					}
				}
			}
		}
	}
	if (map[0][0] == HARD)
	{
		int count = 0;
		for (i = 0; i < ROWS; i++)
		{
			for (j = 0; j < COLS; j++)
			{
				if (map[i][j] == BOOM)
				{
					return -1;
				}
				if (map[i][j] == BOOM + BORD + FLAG)
				{
					count++;
					if (count == HARD)
					{
						return 1;
					}
				}
			}
		}
	}
}

//开0
void Openzero(int **map,int r,int c)
{
	int n = 0;
	int m = 0;
	for (n = -1; n <= 1; n++)
	{
		for (m = -1; m <= 1; m++)
		{
			if (n == 0 && m == 0)
			{
				;
			}
			else
			{
				if (map[r + n][c + m] - BORD < BOOM && map[r + n][c + m] - BORD >= 0)
				{
					map[r + n][c + m] -= BORD;
					if (map[r + n][c + m] == 0)
					{
						Openzero(map, r + n, c + m);
					}
				}
			}
		}
	}
}

