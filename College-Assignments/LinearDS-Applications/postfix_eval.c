#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef unsigned short int bool;

//STACK
struct node
{
	int data;
	struct node* prev;
};
typedef struct
{
	struct node* top;
	unsigned int height;
}Stack;

Stack* createStack()
{
	Stack* newStack = (Stack*) malloc(sizeof(Stack));
	newStack->top = NULL;
	newStack->height = 0;
	return newStack;
}
unsigned short int isEmpty(Stack *s)
{
	return (s->top==NULL);
}
void push(int data, Stack *s)
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
		return INT_MIN;
	}
}

//OPERATOR AND OPERAND
bool isDigit(char c)
{
	switch(c)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': return TRUE;
		default : return FALSE;
	}
}
int parseDigit(char c)
{
	switch(c)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default : return INT_MIN;
	}
}
bool isOperator(char c)
{
	switch(c)
	{
		case '+' : 
		case '-' :
		case '*' :
		case '/' :
		case '^' : return TRUE;
		default  : return FALSE;
	}
}
int operate(int a, int b, char c)
{
	switch(c)
	{
		case '+' : return a + b;
		case '-' : return a - b;
		case '*' : return a * b;
		case '/' : return (b!=0)? a/b : INT_MIN; 
		case '^' : return (int)pow(a,b);
		default  : return INT_MIN;
	}
}

//BUSINESS LOGIC
int evaluatePostfix(const char *str)
{
	int i;
	int n1,n2;
	Stack *s = createStack();
	for(i=0;str[i]!='\0';i++)
	{
		if(isDigit(str[i]))
		{
			n1 = 0;
			while(str[i]!=' ')
				n1 = 10*n1 + parseDigit(str[i++]);
			push(n1,s);
		}
		else if(isOperator(str[i]))
		{
			n2 = pop(s);
			n1 = pop(s);
			if(n1==INT_MIN || n2==INT_MIN)
			{
				printf("ERROR!"); exit(0);
			}
			push(operate(n1,n2,str[i]),s);
		}
	}
	return pop(s);
}

//DRIVER
void main()
{
	char exp[30];
	printf("Enter Postfix Expression: "); scanf("%[^\n]s",exp);
	int result = evaluatePostfix(exp);
	if(result==INT_MIN)
		printf("ERROR!\n");
	else
		printf("Result = %d\n",result);
}
