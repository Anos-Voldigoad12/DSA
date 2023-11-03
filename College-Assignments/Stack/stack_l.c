#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OVERFLOW INT_MAX
#define UNDERFLOW INT_MIN
#define BOOL(X) (X? "TRUE" : "FALSE")

struct node
{
	int data;
	struct node* prev;
};
typedef struct
{
	struct node* top;
	unsigned int height;
	unsigned int max_height;
}Stack;

Stack* createStack(unsigned int height)
{
	Stack* newStack = (Stack*) malloc(sizeof(Stack));
	newStack->top = NULL;
	newStack->height = 0;
	newStack->max_height = height;
	return newStack;
}
void setMaxHeight(unsigned int height, Stack *s)
{
	s->max_height = height;
}
unsigned short int isEmpty(Stack *s)
{
	return (s->top==NULL);
}
unsigned short int isFull(Stack *s)
{
	return (s->height==s->max_height);
}
void push(int data, Stack *s)
{
	if(!isFull(s))
	{
		struct node *newNode = (struct node *) malloc(sizeof(struct node));
		if(newNode==NULL)
		{
			printf("\nMEMORY UNAVAILABLE!\n");
			return;
		}
		
		newNode->data = data;
		newNode->prev = s->top;
		s->top = newNode;
		s->height++;
	}
	else
	{
		printf("\nSTACK OVERFLOW EXCEPTION!\n");
	}
}
int pop(Stack *s)
{
	if(!isEmpty(s))
	{
		struct node* tempNode = s->top;
		s->top = s->top->prev;
		int temp = tempNode->data;
		free(tempNode);
		s->height--;
		return temp;
	}
	else
	{
		printf("\nSTACK UNDERFLOW EXCEPTION!\n");
		return UNDERFLOW;
	}
}
void display(Stack *s)
{
	if(isEmpty(s))
	{
		printf("\nEMPTY STACK!\n");
	}
	struct node* cur = s->top;
	while(cur!=NULL)
	{
		printf("| %4d |\n",cur->data);
		printf("--------\n");
		cur = cur->prev;
	}
}
void main()
{
	int n;
	Stack *s = createStack(100);
	while(1)
	{
		printf("\nSTACK OPERATIONS\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Is Empty?\n");
		printf("5. Change Max Height\n");
		printf("6. Exit\n");
		printf("\nYour Choice: "); scanf("%d",&n);
		printf("\n");
		switch(n)
		{
			case 1:
				printf("Value to push: "); scanf("%d",&n);
				push(n,s);
				break;
			case 2:
				printf("Popped Element: %d\n",pop(s));
				break;
			case 3:
				display(s);
				break;
			case 4:
				printf("Is the stack empty? %s\n",BOOL(isEmpty(s)));
				break;
			case 5:
				printf("Current Max Height: %d\n",s->max_height);
				printf("New Max Height: "); scanf("%d",&n);
				setMaxHeight(n,s);
				break;
			case 6: 
				exit(0);
			default:
				printf("INVALID CHOICE!\n");
		}
	}	
}
