#ifndef _HAFFUMAN_H_
#define _HAFFUMAN_H_


typedef struct HaffumanTreeNode
{
	int parent, lchild, rchild;
	int weight;
}HTnode, *HaffumanTree;

typedef char** Haffumancode;

void slecte(HaffumanTree H, int size, int &s1, int &s2);
void CreateHaffumantree(HaffumanTree &HT, int n);
void CreateHaffumancode(HaffumanTree HT, Haffumancode &HC, int n);


#endif