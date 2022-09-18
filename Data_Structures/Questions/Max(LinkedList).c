//WAP To Find Max Element in A Linked List

#define ERRORCODE -2147483648

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
	int val;
	struct LinkedList *next;
}node;

node *head = NULL;

void append(int data)
{
	node *newNode = (node *) malloc(sizeof(node));
	if(newNode == NULL)
		printf("Linked List Overflow\n");
	else
	{
		newNode->val = data;
		newNode->next = NULL;
		if(head == NULL)
			head = newNode;
		else
		{
			node *current = head;
			while(current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
}
void display()
{
	node *current = head;
	while(current->next != NULL)
	{
		printf("%d => ",current->val);
		current = current->next;
	}
	printf("%d\n",current->val);
}
int max()
{
    int result = ERRORCODE;
	node *current = head;
	while(current!=NULL)
	{
		if(current->val > result)
			result = current->val;
		current = current->next;
	} 
	return result;
}
void main()
{
	int i,n,length;
	printf("Enter Number of Nodes To Create : "); scanf("%d",&length);
	printf("\nEnter %d Elements To the List\n",length);
	for(i=1;i<=length;i++)
	{
		scanf("%d",&n);
		append(n);
	}
	printf("\nCurrent List : "); display();
	printf("Max Element : %d\n",max());
}
