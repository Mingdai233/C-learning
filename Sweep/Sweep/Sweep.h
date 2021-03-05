
#ifndef _SWEEP_H_
#define _SWEEP_H_

#define EASY 10  //����
//��ͼ��С
#define _ROW 10
#define _COL 10
#define SROW 10+2
#define SCOL 10+2

#define HARD 41  //����
//��ͼ��С
#define ROW_ 20
#define COL_ 20
#define ROWS 20+2
#define COLS 20+2

//��ͼԪ��
#define WALL 10//ǽ
#define BOOM 9//ը��
#define FLAG 20//����
#define BORD 20//����

//���ӱ߳�
#define SIDE 25

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>


//��ʼ����Ϸ
int ** Initgame();
//��ʼ������
int **InitData(int rows,int cols,int boom);
//��ʼ��ͼƬ
void Initgraphics(int rows,int cols);
//���ƽ���
void Display(int **map);
void Displaymap(int **map);
void Displaynum(int **map);
void travelprint(int **map,int rows, int cols);
//��Ϸ��ѭ��
void game(int **map);
void Playermove(int **map);
void Openzero(int **map,int r,int c);//��0
int Is_Win(int **map);
#endif