//WAP To Remove All Occurences Of Val From The LIst

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
	if(newNode==NULL)
		printf("Can Not Append\n");
	else
	{
		newNode->val = data;
		newNode->next = NULL;
		if(head == NULL)
			head = newNode;
		else
		{
			node *current = head;
			while(current->next!=NULL)
				current = current->next;
			current->next = newNode;
		}
	}
	
}
void display()
{
	if (head==NULL)
		printf("Empty List\n");
	else
	{
		node *current = head;
		while(current->next!=NULL)
		{
			printf("%d => ",current->val);
			current = current->next;
		}
		printf("%d\n",current->val);
	}
}
void removeAllOccurences(int val)
{
	node *current, *tmp;
	while(head->val==val)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		if (head== NULL) return;
	}
	current = head;
	
	while(current->next!=NULL)
	{
		if(current->next->val==val)
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
			continue;
		}
		current = current->next;
	}
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
	printf("Element for which all occurences are to be deleted : "); scanf("%d",&n);
	removeAllOccurences(n);
	printf("\nUpdated List : "); display();
}
