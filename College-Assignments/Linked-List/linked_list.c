/*
	LINKED LIST FUNCTIONS
	(*) void insertNode(int value): Inserts a new node with the given value at the end of the linked list.

	(*) void deleteNode(int value): Deletes the node with the given value from the linked list.

	(*) void displayList(): Displays the elements of the linked list.

	(*) void reverseList(): Reverses the order of the nodes in the linked list.

	(*) int searchNode(int value): Search for a node with the given value in the linked list and return its position (index) if found, or -1 if not found
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void insertNode(int value)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if(head==NULL)
		head = newNode;
	else
	{
		struct Node* cur = head;
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = newNode;
	}
}
void deleteNode(int value)
{
	if(head==NULL)
	{
		printf("\nEmpty List Exception!\n");
		return;
	}
	if(head->data==value)
		head = head->next;
	else if(head->next==NULL)
	{
		printf("\nValue Not Found Exception!\n");
		return;
	}
	else
	{
		struct Node* cur = head;
		while(cur->next!=NULL)
		{
			if(cur->next->data!=value)
				cur = cur->next;
			else
			{
				struct Node* temp = cur->next; 
				cur->next = cur->next->next;
				free(temp);
				return;		
			}			
		}
		printf("\nValue Not Found Exception!\n");
	}
}
void reverseList()
{
	if(head==NULL)
	{
		printf("\nEmpty List Exception!\n");
		return;
	}
	struct Node *cur, *temp=NULL;
	while(head->next!=NULL)
	{
		cur = head;
		head = head->next;
		cur->next = temp;
		temp = cur;
	}
	head->next = temp;
}
int searchNode(int value)
{
	if(head!=NULL)
	{
		int i;
		struct Node* cur = head;
		for(i=0;cur!=NULL;i++)
		{
			if(cur->data==value)
				return i;
			cur = cur->next;
		}
		return -1;
	}
	else
	{
		printf("\nEmpty List Exception!\n");
		return -1;
	}
}
void displayList()
{
	if(head!=NULL)
	{
		struct Node* cur = head;
		while(cur->next!=NULL)
		{
			printf("%d => ",cur->data);
			cur = cur->next;
		}
		printf("%d\n",cur->data);
	}
	else
	{
		printf("\nEmpty List Exception!\n");
		return;
	}
}
void main()
{
	int n;
	while(1)
	{
		printf("\n\n\tMenu\t\n");
		printf("1. Append a Node\n");
		printf("2. Delete a Node\n");
		printf("3. Display List\n");
		printf("4. Reverse List\n");
		printf("5. Search Node\n");
		printf("6. Exit Program\n");
		printf("\nChoose a List Operation: "); scanf("%d",&n);
		switch(n)
		{
			case 1: 
				printf("Enter value to insert: "); scanf("%d",&n);
				insertNode(n);
				break;
			case 2:
				printf("Enter value to delete: "); scanf("%d",&n);
				deleteNode(n);
				break;
			case 3: 
				displayList();
				break;
			case 4:
				reverseList();
				break;
			case 5:
				printf("Enter value to search: "); scanf("%d",&n);
				printf("%d found at: position %d\n",n,searchNode(n));
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid Choice! Please try again!\n");
		}
	}
	
}
