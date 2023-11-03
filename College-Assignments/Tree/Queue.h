#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queueNode
{
	void* data;
	struct queueNode* next;
}QueueNode;
typedef struct
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

Queue* newQueue()
{
	Queue* q = (Queue *) malloc(sizeof(Queue));
	q->front = NULL;
	q->rear  = NULL;
}
QueueNode* newQueueNode(void* data)
{
	QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
	node->data = data;
	node->next = NULL;
	return node;
}
int isEmpty(Queue* q)
{
	return (q->front==NULL);
}
void* peek(Queue* q)
{
	if(!isEmpty(q))
		return q->front->data;
	else
		return NULL;
}
void enqueue(void* data, Queue* q)
{
	QueueNode* node = newQueueNode(data);
	if(isEmpty(q))
	{
		q->front = node;
		q->rear  = node;
	}
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
}
void* dequeue(Queue* q)
{
	if(!isEmpty(q))
	{
		QueueNode* tmp = q->front;
		void* x = tmp->data;
		if(q->front==q->rear)
			q->rear = q->rear->next;
		q->front = q->front->next;
		free(tmp);
		return x;
	}
	else
		return NULL;
}
