#ifndef _BITREE_H_
#define _BITREE_H_
#define MAXSIZE 100


#include<iostream>

using namespace std;


typedef char BTElemtype;

//创建二叉树节点
typedef struct BTnode
{
	BTElemtype data;
	struct BTnode *lChild, *rChild;
}BTnode, *Bitree;



typedef Bitree SElemtype;

void CreateBitree(Bitree &T);
void Preodertraverse(Bitree T);
void Inodertraverse(Bitree T);
void Postodertraverse(Bitree T);
void Inodertraverses(Bitree T);
void Levelodertraverse(Bitree T);

void Bitreecopy(Bitree T, Bitree &S);
int Bitreedepth(Bitree T);
int Leadcount(Bitree T);
void vist(Bitree T);



#endif