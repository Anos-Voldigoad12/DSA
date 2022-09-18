#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	struct Stack *prev;
	char val;
};
typedef struct Stack node;

node *pointer=NULL;

int value(char c)
{
	int n;
	switch(c)
	{
		case '^' : n = 2;
					break;
		case '%' : n = 1;
					break;
		case '/' : n = 1;
					break;
		case '*' : n = 1;
					break;
		case '+' : n = 0;
					break;
		case '-' : n = 0;
					break; 
	}
	return n;
}
int precedence(char c1 , char c2)
{
	if(value(c1) >= value(c2))
		return 1;
	else
		return 0;
}
void push(char c)
{
	node *temp = (node*) malloc(sizeof(node));
	temp->val = c;
	temp->prev = pointer;
	if(pointer==NULL)
		pointer = temp;
	else
	{
		temp->prev = pointer;
		pointer =  temp;
	}
}
char pop()
{
	char element;
	node *current=pointer;
	if(current==NULL)
		return ' ';
	else
	{
		element = current->val;
		pointer = pointer->prev;
		free(current);
		return element;
	}
}
void display(node *current)
{
	if(current == NULL)
		return;
	else
	{
		display(current->prev);
		printf("%c ",current->val);
	}
}
void main()
{
	int i;
	char c;
	char infix[30] , postfix[30]="\0";
	printf("Enter Infix Expression : ");
	scanf("%s",infix);
	c  = ')';
	strncat(infix,&c,1);
		
	push('(');
	for(i=0;i<strlen(infix);i++)
	{
		if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%' || infix[i]=='^' || infix[i]==')')
		{
			if(pointer->val=='(' && infix[i]!=')')
				push(infix[i]);
			else
			{
				if(infix[i]==')')
				{
					while(pointer->val!='(')
					{
						c = pop();
						strncat(postfix,&c,1);
					}
					pop();
				}
				else if(precedence(pointer->val,infix[i]))
				{
					while(precedence(pointer->val,infix[i]))
					{
						c = pop();
						strncat(postfix,&c,1);
						if(pointer->val=='(')
							break;
					}
					push(infix[i]);
				}
				else
					push(infix[i]);
			}
		}
		else if(infix[i]==' ')
			continue;
		else
		{
			c = infix[i];
			strncat(postfix,&c,1);
		}
	}
	printf("Postfix Expression : %s",postfix);
}
