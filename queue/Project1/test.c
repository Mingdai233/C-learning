#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>


typedef int Datatype;
//�ڵ�ṹ��
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
	//���
	rear = inQueue(rear, 1);
	rear = inQueue(rear,2);
	rear = inQueue(rear, 3);
	rear = inQueue(rear, 4);
	rear = inQueue(rear, 5);
	rear = inQueue(rear, 6);
	//����
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	front = outQueue(front, rear);
	return 0;
}
//���
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

//����
QNode* outQueue(QNode *front, QNode *rear)
{
	//�ж��Ƿ�Ϊ�ն�
	if (front == rear)
	{
		printf("�նӣ�\n");
		return front;
	}
	printf("Ԫ��%d����!\n",front->data);
	QNode* tempNode = front;
	front = front->next;
	free(tempNode);
	tempNode = NULL;
	return front;
}


//��ʼ������(����ͷ�ڵ�)
QNode* Initqueue()
{
	QNode* queue;
	queue = (QNode*)malloc(sizeof(QNode));
	//�ж��Ƿ�����ɹ�
	if (!queue)
	{
		return NULL;
	}
	queue->data = 0;
	queue->next = NULL;
	return queue;
}



////˳�����
////���
//int inqueue(int *p, int tail, int value);
////����
//int outqueue(int *p, int tail);
//
//int main()
//{
//	int arr[10] = { 0 };
//	int front = 0, rear = 0;
//	//���
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
//	//����
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
//	//�ж��Ƿ�Ϊ����
//	if ((rear + 1) % 10 == front)
//	{
//		printf("����!\n");
//		return rear;
//	}
//	p[rear] = value;
//	rear++;
//	return rear%10;//���г���Ϊ10
//}
//
//int outqueue(int *p, int front, int rear)
//{
//	//�ж϶����Ƿ�Ϊ��
//	if (rear == front)
//	{
//		printf("�նӣ�\n");
//		return front;
//	}
//	printf("Ԫ��%d����!\n", p[front]);
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
////Ԫ�ؽ�ջ
//Node* List_PushElement(Node* stack,int value);
//
////Ԫ�س�ջ
//Node* List_PopElement(Node* stack);
//
//int main()
//{
//	//��ջ
//	Node* stack = NULL;
//	stack = List_PushElement(stack, 1);
//	stack = List_PushElement(stack, 2);
//	stack = List_PushElement(stack, 3);
//	stack = List_PushElement(stack, 4);
//	stack = List_PushElement(stack, 5);
//	stack = List_PushElement(stack, 6);
//	stack = List_PushElement(stack, 7);
//	//��ջ
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
//	//�ж��Ƿ�Ϊ��ջ
//	if (NULL == stack)
//	{
//		printf("��ջ��\n");
//		return stack;
//	}
//	printf("Ԫ��%d��ջ!\n", stack->data);
//	Node* temp = stack;
//	stack = stack->next;
//	free(temp);
//	temp = NULL;
//	return stack;
//}

////Ԫ�ؽ�ջ(�洢�ṹ��ջ��ָ�룬����)
//int PushElement(int *p, int top, int value);
////Ԫ�س�ջ(�洢�ṹ��ջ��ָ�룬����)
//int PopElement(int *p, int top);
//
//int main()
//{
//	int arr[10] = { 0 };
//	//ջ��ָ��(�±�)
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
//	//��ջ
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
//	//�ж�ջ�Ƿ�Ϊ��
//	if (top <= -1)
//	{
//		printf("��ջ��\n");
//		return -1;
//	}
//	else
//	{
//		printf("Ԫ��%d��ջ!\n", p[top]);
//		top--;
//		return top;
//	}
//}
