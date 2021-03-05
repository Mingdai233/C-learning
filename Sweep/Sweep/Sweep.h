
#ifndef _SWEEP_H_
#define _SWEEP_H_

#define EASY 10  //雷数
//地图大小
#define _ROW 10
#define _COL 10
#define SROW 10+2
#define SCOL 10+2

#define HARD 41  //雷数
//地图大小
#define ROW_ 20
#define COL_ 20
#define ROWS 20+2
#define COLS 20+2

//地图元素
#define WALL 10//墙
#define BOOM 9//炸弹
#define FLAG 20//旗子
#define BORD 20//挡板

//格子边长
#define SIDE 25

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>


//初始化游戏
int ** Initgame();
//初始化数据
int **InitData(int rows,int cols,int boom);
//初始化图片
void Initgraphics(int rows,int cols);
//绘制界面
void Display(int **map);
void Displaymap(int **map);
void Displaynum(int **map);
void travelprint(int **map,int rows, int cols);
//游戏主循环
void game(int **map);
void Playermove(int **map);
void Openzero(int **map,int r,int c);//开0
int Is_Win(int **map);
#endif