#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>


typedef int Datatype;
//节点结构体
typedef struct QNode
{
	Datatype data;
	struct QNode* next;
}QNode;
QNode* inQueue(QNode* rear, int value);
QNode* outQueue(QNode* front, QNode* rear);
QNode* Initqueue();



int main()
{
	QNode *front, *rear;
	front = rear = Initqueue();
	//入队
	rear = inQueue(rear, 1);
	rear = inQueue(rear,2);
	rear = inQueue(rear, 3);
	rear = inQueue(rear, 4);
	rear = inQueue(rear, 5);
	rear = inQueue(rear, 6);
	//出队
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	return 0;
}
//入队
QNode* inQueue(QNode* rear, int value)
{
	rear->data = value;
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	NewNode->data = value;
	NewNode->next = NULL;
	rear->next = NewNode;
	rear = NewNode;
	return rear;
}

//出队
QNode* outQueue(QNode *front, QNode *rear)
{
	//判断是否为空队
	if (front == rear)
	{
		printf("空队！\n");
		return front;
	}
	printf("元素%d出队!\n",front->data);
	QNode* tempNode = front;
	front = front->next;
	free(tempNode);
	tempNode = NULL;
	return front;
}


//初始化链表(创建头节点)
QNode* Initqueue()
{
	QNode* queue;
	queue = (QNode*)malloc(sizeof(QNode));
	//判断是否申请成功
	if (!queue)
	{
		return NULL;
	}
	queue->data = 0;
	queue->next = NULL;
	return queue;
}



////顺序队列
////入队
//int inqueue(int *p, int tail, int value);
////出队
//int outqueue(int *p, int tail);
//
//int main()
//{
//	int arr[10] = { 0 };
//	int front = 0, rear = 0;
//	//入队
//	rear = inqueue(arr, rear, 1,front);
//	rear = inqueue(arr, rear, 2,front);
//	rear = inqueue(arr, rear, 3,front);
//	rear = inqueue(arr, rear, 4,front);
//	rear = inqueue(arr, rear, 5,front);
//	rear = inqueue(arr, rear, 6,front);
//	rear = inqueue(arr, rear, 7, front);
//	rear = inqueue(arr, rear, 8, front);
//	rear = inqueue(arr, rear, 9, front);
//	rear = inqueue(arr, rear, 10, front);
//	//出队
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	rear = inqueue(arr, rear, 10, front);
//	rear = inqueue(arr, rear, 11, front);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//	front = outqueue(arr, front, rear);
//
//	return 0;
//}
//int inqueue(int *p, int rear, int value,int front)
//{
//	//判断是否为满队
//	if ((rear + 1) % 10 == front)
//	{
//		printf("满队!\n");
//		return rear;
//	}
//	p[rear] = value;
//	rear++;
//	return rear%10;//队列长度为10
//}
//
//int outqueue(int *p, int front, int rear)
//{
//	//判断队列是否为空
//	if (rear == front)
//	{
//		printf("空队！\n");
//		return front;
//	}
//	printf("元素%d出队!\n", p[front]);
//	front++;
//	return front%10;
//}

//typedef int Datatype;
//typedef struct Node
//{
//	Datatype data;
//	struct Node* next;
//}Node;
//
////元素进栈
//Node* List_PushElement(Node* stack,int value);
//
////元素出栈
//Node* List_PopElement(Node* stack);
//
//int main()
//{
//	//进栈
//	Node* stack = NULL;
//	stack = List_PushElement(stack, 1);
//	stack = List_PushElement(stack, 2);
//	stack = List_PushElement(stack, 3);
//	stack = List_PushElement(stack, 4);
//	stack = List_PushElement(stack, 5);
//	stack = List_PushElement(stack, 6);
//	stack = List_PushElement(stack, 7);
//	//出栈
//	stack = List_PopElement(stack);
//	stack = List_PopElement(stack);
//	stack = List_PopElement(stack);
//	stack = List_PopElement(stack);
//	stack = List_PopElement(stack);
//	stack = List_PopElement(stack);
//	stack = List_PopElement(stack);
//	stack = List_PopElement(stack);
//	return 0;
//}
//
//
//Node* List_PushElement(Node* stack, int value)
//{
//	Node* NewNode = (Node*)malloc(sizeof(Node));
//	NewNode->data = value;
//	NewNode->next = stack;
//	stack = NewNode;
//	return stack;
//}
//
//Node* List_PopElement(Node* stack)
//{
//	//判断是否为空栈
//	if (NULL == stack)
//	{
//		printf("空栈！\n");
//		return stack;
//	}
//	printf("元素%d出栈!\n", stack->data);
//	Node* temp = stack;
//	stack = stack->next;
//	free(temp);
//	temp = NULL;
//	return stack;
//}

////元素进栈(存储结构，栈顶指针，数据)
//int PushElement(int *p, int top, int value);
////元素出栈(存储结构，栈顶指针，数据)
//int PopElement(int *p, int top);
//
//int main()
//{
//	int arr[10] = { 0 };
//	//栈顶指针(下标)
//	int top = -1;
//	top=PushElement(arr, top, 1);
//	top=PushElement(arr, top, 2);
//	top = PushElement(arr, top, 3);
//	top =PushElement(arr, top, 4);
//	top = PushElement(arr, top, 5);
//	top = PushElement(arr, top, 6);
//	top = PushElement(arr, top, 7);
//	top = PushElement(arr, top, 8);
//	top = PushElement(arr, top, 9);
//	//出栈
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	top = PopElement(arr, top);
//	return 0;
//}
//
//
//int PushElement(int *p, int top, int value)
//{
//	p[++top] = value;
//	return top;
//}
//
//int PopElement(int *p,int top)
//{
//	//判断栈是否为空
//	if (top <= -1)
//	{
//		printf("空栈！\n");
//		return -1;
//	}
//	else
//	{
//		printf("元素%d出栈!\n", p[top]);
//		top--;
//		return top;
//	}
//}
