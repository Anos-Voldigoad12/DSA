#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct Node
{
	int data;
	struct Node *next;
};
typedef struct
{
	struct Node *front;
	struct Node *rear;
}Queue;

Queue* createQueue()
{
	Queue* newQ = (Queue *) malloc(sizeof(Queue));
	newQ->front = NULL;
	newQ->rear = NULL;
}
void enqueue(int data, Queue* q)
{
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	if(newNode)
	{
		newNode->data = data;
		newNode->next = NULL;
		if(q->rear==NULL)
		{
			q->front = newNode;
			q->rear = newNode;
		}
		else
		{
			q->rear->next = newNode;
			q->rear = q->rear->next;
		}
	}
}
int dequeue(Queue* q)
{
	int x;
	if(q->rear==NULL)
		return INT_MIN;
	else
	{
		x = q->front->data;
		struct Node* temp = q->front;
		q->front = q->front->next;
		if(q->front == NULL) q->rear = NULL;
		free(temp);
		return x;
	}
}
void displayQueue(Queue* q)
{
	if(q->front==NULL)
		printf("\n\nEMPTY QUEUE!\n\n");
	else
	{
		struct Node* cur;
		printf("[ FRONT ] ");
		for(cur=q->front;cur->next!=NULL;cur=cur->next)
			printf("%d <= ",cur->data);
		printf("%d [ REAR ]\n",cur->data);
	}
}
void safe_dequeue(Queue *q)
{
	int x = dequeue(q);
	(x==INT_MIN)? printf("\n\nQUEUE UNDERFLOW EXCEPTION!\n\n") : printf("Dequeued Element: %d\n",x) ;
}
void displayMenu()
{
	printf("\nQUEUE OPERATIONS\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("\nChoice: ");
}
void main()
{
	Queue* q = createQueue();
	int n;
	do
	{
		displayMenu(); scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Data: "); scanf("%d",&n);
				enqueue(n,q);
				break;
			case 2:
				safe_dequeue(q);
				break;
			case 3:
				displayQueue(q);
				break;
			case 4:
				break;
			default:
				printf("INVALID CHOICE!\n");
		}
	}while(n!=4);
}
