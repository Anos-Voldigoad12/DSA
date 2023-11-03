#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100
#define OVERFLOW INT_MAX
#define UNDERFLOW INT_MIN
#define BOOL(X) (X? "TRUE" : "FALSE")

int stack[MAX_SIZE];
int top = -1;

unsigned short int isEmpty()
{
	return (top==-1);
}
unsigned short int isFull()
{
	return (top==MAX_SIZE-1);
}
void push(int data)
{
	if(!isFull())
	{
		stack[++top] = data;
	}
	else
	{
		printf("\nSTACK OVERFLOW EXCEPTION!\n");
	}
}
int pop()
{
	if(!isEmpty())
	{
		int temp = stack[top];
		stack[top--] = -1;
		return temp;
	}
	else
	{
		printf("\nSTACK UNDERFLOW EXCEPTION!\n");
		return UNDERFLOW;
	}
}
void display()
{
	if(isEmpty())
	{
		printf("\nEMPTY STACK!\n");
	}
	int i;
	for(i=top;i>=0;i--)
	{
		printf("| %4d |\n",stack[i]);
		printf("--------\n");
	}
}
void main()
{
	int n;
	while(1)
	{
		printf("\nSTACK OPERATIONS\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Is Empty?\n");
		printf("5. Exit\n");
		printf("\nYour Choice: "); scanf("%d",&n);
		printf("\n");
		switch(n)
		{
			case 1:
				printf("Value to push: "); scanf("%d",&n);
				push(n);
				break;
			case 2:
				printf("Popped Element: %d\n",pop());
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Is the stack empty? %s\n",BOOL(isEmpty()));
				break;
			case 5:
				printf("Good Bye!"); 
				exit(0);
			default:
				printf("INVALID CHOICE!\n");
		}
	}	
}
