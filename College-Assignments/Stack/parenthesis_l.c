#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OVERFLOW INT_MAX
#define UNDERFLOW INT_MIN
#define BOOL(X) (X? "TRUE" : "FALSE")

struct node
{
	char data;
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
void push(char data, Stack *s)
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
		printf("| %c |\n",cur->data);
		printf("-----\n");
		cur = cur->prev;
	}
}
unsigned short int isParenthesesMatch(const char* str)
{
	int i;
	Stack *s = createStack(100);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(')
			push(str[i],s);
		else if(str[i]==')')
			pop(s);	
	}
	return isEmpty(s);		
}
void main()
{
	char exp[50];
	printf("Enter Expression: "); scanf(" %[^\n]s",exp);
	if(isParenthesesMatch(exp))
		printf("Balanced Parenthesis.\n");
	else
		printf("UnBalanced Parenthesis.\n");
}
