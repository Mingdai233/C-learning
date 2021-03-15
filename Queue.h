#ifndef  _QUEUE_H_
#define  _QUEUE_H_

#include "Bitree.h"

typedef struct queue
{
	int front = 0;
	int rear = 0;
	SElemtype data[MAXSIZE];
}Queue;


void EnterQueue(Queue &Q,SElemtype T);
void OutQueue(Queue &Q,SElemtype &e);
bool Queueempty(Queue Q);


#endif // ! _QUEUE_H_
