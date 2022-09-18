/*
	=================================================================================================================================================
	|		Data Structure		 | 			Node	  	| 							Functions						    							|	
	=================================================================================================================================================
	|		<1>STACK			 |  	Stack_Node		|  <a>void push(int val) : To Push Data Into The STACK										|
	|							 |						|  <b>int pop() : To Pop The Topmost Value From The STACK									|
	|							 |		  {top}			|  <c>void displayStack() : To Display The Current STACK									|
	|							 |						|  <d>void invertStack() : To Invert The Current STACK 										|
	|							 |						|  <e>int stackLength() : To Find The Length Of The Current STACK   						|
	=================================================================================================================================================
	|		<2>QUEUE			 |  	Queue_Node		|  <a>void load(int val) : To Load Data Into The QUEUE										|
	|							 |						|  <b>int retrieve() : To Retrieve the Front Value From The QUEUE							|
	|							 |	  {front ; rear}	|  <c>void displayQueue() : To Display The Current QUEUE									|
	|							 |						|  <d>void reverseQueue() : To Reverse The Current QUEUE 									|
	|							 |						|  <e>int queueLength() : To Find The Length Of The Current The QUEUE   					|
	=================================================================================================================================================
	|	   <3>LINKED LIST		 |  	List_Node		|  <a>void append(int val) : To Append The Value At The End Of The LIST 					|
	|							 |						|  <b>void addNodeAt(int val , int index) : To Add Node At A Specific Index In The LIST		|
	|							 |		  {head}		|  <c>void removeNodeAt(int index) : To Remove Node At A Certain Index In The LIST			|
	|							 |						|  <d>void removeLastNode() : To Remove Last Node From The LIST								|
	|							 |						|  <e>void removeAllOccurences(int val) : To Remove All Occurences Of A Value From The LIST	|
	|							 |						|  <f>int valueAt(int index) : To Find Value At A Specific Index In The LIST				|
	|							 |						|  <g>int indexOf(int val) : To Find The Index Where A Value Is Located In The LIST			|
	|							 |						|  <h>void displayList() : To Display The Current LIST										|
	|							 |						|  <i>void reverseList() : To Reverse The Current LIST										| 
	|							 |						|  <j>int listLength() : To Find The Length Of The Current The LIST							|
	=================================================================================================================================================
*/

#define ERRORCODE -2147483648

#include <stdio.h>
#include <stdlib.h>

//Defining The Data Structures
typedef struct Stack
{
	int data;
	struct Stack *prev;
}Stack_Node;
typedef struct Queue
{
	int data;
	struct Queue *next;
}Queue_Node;
typedef struct Linked_List
{
	int data;
	struct Linked_List *next;
}List_Node;

//Declaring The Initial Node Of The Data Structures
Stack_Node *top = NULL;
Queue_Node *front = NULL, *rear = NULL;
List_Node *head = NULL; 

//Stack Functions
void push(int val)
{
	Stack_Node *newNode = (Stack_Node *) malloc(sizeof(Stack_Node));
	if(newNode==NULL)
		printf("\n\t\t!!! Stack Overflow !!!\n");
	else
	{
		newNode->data = val;
		newNode->prev = top;
		top = newNode;
	}
}
int pop()
{
	int n = ERRORCODE;
	if(top==NULL)
		printf("\n\t\t!!! Stack Underflow !!!\n");
	else
	{
		Stack_Node *tmp;
		tmp = top;
		n = top->data;
		top = top->prev;
		free(tmp);
	}
	return n;
}
void displayStack()
{
	if(top==NULL)
		printf("\n\t\t!!! Empty Stack !!!\n");
	else
	{
		printf("\n");
		Stack_Node *current = top;
		while(current!=NULL)
		{	
			printf("\t\t| %10d |\n",current->data);
			printf("\t\t--------------\n");
			current = current->prev;
		}
	}
}
void invertStack()
{
	if(top==NULL)
		printf("\n\t\t!!! Empty Stack !!!\n");
	else
	{
		Stack_Node *current = top->prev , *tmp = top;
		tmp->prev = NULL;
		while (current != NULL)
		{
			top = current;
			current = current->prev;
			top->prev = tmp;
			tmp = top;
		}
	}
}
int stackLength()
{
	int len = 0;
	Stack_Node *current = top;
	while(current!=NULL)
	{
		len++;
		current = current->prev;
	} 
	return len;
}

//Queue Functions
void load(int val)
{
	Queue_Node *newNode = (Queue_Node *) malloc(sizeof(Queue_Node));
	
	if(newNode==NULL)
		printf("\n\t\t!!! Queue Overflow !!!\n");
	else
	{
		newNode->data = val;
		newNode->next = NULL;
		if(front == NULL)
		{	
			front = rear = newNode;		
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}
}
int retrieve()
{
	int n = ERRORCODE;
	if(front==NULL)
		printf("\n\t\t!!! Queue Underflow !!!\n");
	else
	{
		Queue_Node *tmp;
		tmp = front;
		n = front->data;
		front = front->next;
		free(tmp);
	}
	return n;
}
void displayQueue()
{
	if(front==NULL)
		printf("\n\t\tEmpty Queue\n");
	else
	{
		Queue_Node *current = front;
		printf("\n\t\tFRONT| ");
		while(current!=rear)
		{
			printf("%d <= ",current->data);
			current = current->next;
		}
		printf("%d\n",current->data);
	}
}
void reverseQueue()
{
	if (front == NULL)
		printf("\n\t\t!!! Empty Queue !!!\n");
	else
	{
		rear = front;
		Queue_Node *current = front->next , *tmp = front;
		tmp->next = NULL;
		while (current != NULL)
		{
			front = current;
			current = current->next;
			front->next = tmp;
			tmp = front;
		}
	}
}
int queueLength()
{
	int len = 0;
	Queue_Node *current = front;
	while(current!=NULL)
	{
		len++;
		current = current->next;
	}
	return len;
}

//Linear Linked List Functions
void append(int val)
{
	List_Node *newNode = (List_Node *) malloc(sizeof(List_Node));
	if(newNode==NULL)
		printf("\n\t\t!!! List Overflow !!!\n");
	else
	{
		newNode->data = val;
		newNode->next = NULL;
		
		if(head==NULL)
			head = newNode;
		else
		{
			List_Node *current = head;
			while(current->next!=NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
}
void addNodeAt(int val , int index)
{
	List_Node *newNode = (List_Node *) malloc(sizeof(List_Node));
	if(newNode==NULL)
		printf("\n\t\t!!! List Overflow !!!\n");
	else
	{
		newNode->data = val;
		if (index==0)
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		else
		{
			int current_index=0;
			List_Node *current = head;
			while(current!=NULL)
			{
				if(current_index==index-1)
				{
					newNode->next = current->next;
					current->next = newNode;
					return;
				}
				current = current->next;
				current_index++;
			}
			printf("\n\t\t!!! Illegal Index !!!\n");
		}
	}
}
void removeNodeAt(int index)
{
	List_Node *tmp;
	if(head==NULL)
		printf("\n\t\t!!! List Underflow !!!\n");
	else
	{
		if(index==0)
		{
			tmp = head;
			head = head->next;
			free(tmp);
			return;
		}
		else
		{
			int current_index=0;
			List_Node *current = head;
			while(current!=NULL)
			{
				if(current_index==index-1 && current->next != NULL)
				{
					tmp = current->next;
					current->next = current->next->next;
					free(tmp);
					return;
				}
				current = current->next;
				current_index++;
			}
			printf("\n\t\t!!! Illegal Index !!!\n");
		}
	}
}
void removeLastNode()
{
	List_Node *tmp;
	if(head==NULL)
		printf("\n\t\t!!! List Underflow !!!\n");
	else if(head->next==NULL)
	{
		tmp = head;
		head = NULL;
		free(tmp);
	}
	else
	{
		List_Node *current = head;
		while(current->next->next!=NULL)
		{
			current = current->next;
		}
		tmp = current->next;
		current->next = NULL;
		free(tmp);
		
	}
}
void removeAllOccurences(int val)
{
	List_Node *tmp , *current;
	if(head==NULL)
		printf("\n\t\t!!! List Underflow !!!\n");
	else
	{
		current = head;
		while(current!=NULL)
		{
			if(head->data==val)
			{
				tmp = head;
				head = head->next;
				current = head;
				free(tmp);
				continue;
			}
			else if(current->next!=NULL)
			{
				if(current->next->data==val)
				{
					tmp = current->next;
					current->next = current->next->next;
					free(tmp);
					continue;
				}
			}
			current = current->next;
		}
	}
}
int valueAt(int index)
{
	if(head==NULL)
	{
		printf("\n\t\t!!! Empty List !!!\n");
		return ERRORCODE;
	}
	else
	{
		List_Node *current =  head;
		int current_index = 0;
		while(current!=NULL)
		{
			if(current_index==index)
				return current->data;
			current = current->next;
			current_index++;
		}
		printf("\n\t\t!!! Illegal Index !!!\n");
		return ERRORCODE;
	}
}
int indexOf(int val)
{
	int current_index = 0;
	List_Node *current =  head;
	while(current!=NULL)
	{
		if(current->data==val)
			return current_index;
		current = current->next;
		current_index++;
	}
	return -1;
}
void displayList()
{
	if(head==NULL)
		printf("\n\t\t!!! Empty List !!!\n");
	else
	{
		List_Node *current = head;
		printf("\n\t\t");
		while(current->next!=NULL)
		{
			printf("%d => ",current->data);
			current = current->next;
		}
		printf("%d\n",current->data);
	}
}
void reverseList()
{
	List_Node *current = head->next , *tmp = head;
	head->next = NULL;
	while(current!=NULL)
	{
		head = current;
		current = current->next;
		head->next = tmp;
		tmp = head;
	}
}
int listLength()
{
	int len = 0;
	List_Node *current = head;
	while(current!=NULL)
	{
		len++;
		current = current->next;
	}
	return len;
}
