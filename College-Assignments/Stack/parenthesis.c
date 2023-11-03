#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100
#define OVERFLOW INT_MAX
#define UNDERFLOW INT_MIN
#define BOOL(X) (X? "TRUE" : "FALSE")

char stack[MAX_SIZE];
int top = -1;

unsigned short int isEmpty()
{
	return (top==-1);
}
unsigned short int isFull()
{
	return (top==MAX_SIZE-1);
}
void push(char data)
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
void pop()
{
	if(!isEmpty())
	{
		stack[top--] = '\0';
	}
	else
	{
		printf("\nSTACK UNDERFLOW EXCEPTION!\n");
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
		printf("| %c |\n",stack[i]);
		printf("-----\n");
	}
}
unsigned short int isParenthesesMatch(const char* str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(')
			push(str[i]);
		else if(str[i]==')')
			pop();	
	}
	return isEmpty();		
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
