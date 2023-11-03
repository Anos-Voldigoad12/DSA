#include <stdio.h>
#include <limits.h>

#define BOOL unsigned short int
#define true 1
#define false 0
#define BPRINT(X) (X? "TRUE" : "FALSE")

#define MAX_SIZE 3

int queue[MAX_SIZE];
int front = -1 ,rear = -1;

BOOL isEmpty()
{
	return (front==-1 && rear==-1);
}
BOOL isFull()
{
	return (rear==MAX_SIZE-1);
}
void enqueue(int data)
{
	if(isFull())
		printf("\n\nOVERFLOW EXCEPTION!\n\n");
	else
	{
		if(isEmpty())	front++;
		queue[++rear] = data;
		printf("DATA ADDED SUCCESSFULLY!\n");
	}
}
int dequeue()
{
	if(isEmpty())
	{
		printf("\n\nUNDERFLOW EXCEPTION!\n\n");
		return INT_MIN;
	}
	else if(front==rear)
	{
		int x = queue[front];
		front = rear = -1;
		return x;
	}
	else
		return queue[front++];
}
void display()
{
	if(isEmpty())
	{
		printf("\n\nEMPTY QUEUE!\n\n");
		return;
	}
	int i;
	for(i=front;i<rear;i++)
		printf("%d <= ",queue[i]);
	printf("%d\n",queue[i]);
}
void displayMenu()
{
	printf("::QUEUE OPERATIONS::\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Is Empty?\n");
	printf("5. Is Full?\n");
	printf("6. Exit\n");
	printf("\nChoice: ");
}
void main()
{
	int n,x;
	do
	{
		displayMenu(); scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Data: "); scanf("%d",&n);
				enqueue(n);
				break;
			case 2:
				x = dequeue();
				if(x!=INT_MIN)
					printf("Dequeued Element: %d\n",x);
				break;
			case 3:
				printf("Current Queue: "); display();
				break;
			case 4:
				printf("Is Empty? %s\n",BPRINT(isEmpty()));
				break;
			case 5:
				printf("Is Full? %s\n",BPRINT(isFull()));
				break;
			case 6:
				break;
			default:
				printf("INVALID CHOICE!");
		}
		printf("\n");
	}while(n!=6);
}
