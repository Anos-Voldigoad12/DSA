#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct Node
{
	int data;
	int priority;
	struct Node *next;
};
typedef struct
{
	struct Node *front;
}Queue;

Queue* createQueue()
{
	Queue* newQ = (Queue *) malloc(sizeof(Queue));
	newQ->front = NULL;
}
void enqueue(int data, int priority, Queue* q)
{
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	if(newNode)
	{
		newNode->data = data;
		newNode->priority = priority;
		newNode->next = NULL;
		if (q->front == NULL || priority < q->front->priority)
		{
	        newNode->next = q->front;
	        q->front = newNode;
    	} 
		else
		{ 
			struct Node* current = q->front;
			while (current->next != NULL && priority >= current->next->priority)
			{
	            current = current->next;
	        }
	        newNode->next = current->next;
	        current->next = newNode;
		}
	}
}
int dequeue(Queue* q)
{
	int x;
	if(q->front==NULL)
		return INT_MIN;
	else
	{
		x = q->front->data;
		struct Node* temp = q->front;
		q->front = q->front->next;
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
			printf("%d (P:%d) <= ",cur->data,cur->priority);
		printf("%d (P:%d) [ REAR ]\n",cur->data,cur->priority);
	}
}
void safe_dequeue(Queue *q)
{
	int x = dequeue(q);
	(x==INT_MIN)? printf("\n\nQUEUE UNDERFLOW EXCEPTION!\n\n") : printf("Dequeued Element: %d\n",x) ;
}
void displayMenu()
{
	printf("\nPRIORITY QUEUE OPERATIONS\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("\nChoice: ");
}
void main()
{
	Queue* q = createQueue();
	int n,p;
	do
	{
		displayMenu(); scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Data: "); scanf("%d",&n);
				printf("Priority: "); scanf("%d",&p);
				enqueue(n,p,q);
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
