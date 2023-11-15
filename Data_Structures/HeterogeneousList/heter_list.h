#include "iter.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct heter_node
{
	void* data;
	struct heter_node* next;
	struct heter_node* prev;
	void (*cpyData)(void *, void *);
	void (*printData)(void *);
}heter_node;
typedef struct HeterList
{
	heter_node* head;
	heter_node* tail;
	int size;
}HeterList;

HeterList* newHeterList(); //Creates a new HeterList 
void addHeterNodeFront(HeterList* h, void* data, void (*cpyData)(void *, void *), void (*printData)(void *)); //Adds a new node at front
void addHeterNodeRear(HeterList* h, void* data, void (*cpyData)(void *, void *), void (*printData)(void *)); //Adds a new node at rear
void addHeterNode(HeterList* h, int index, void* data, void (*cpyData)(void *, void *), void (*printData)(void *)); //Appends a node at a specified index
void appendHeterList(HeterList* h, HeterList* h2); //Appends a HeterList at the tail of another HeterList 
void removeHeterNodeFront(HeterList* h); //Remove a node from the front
void removeHeterNodeRear(HeterList* h); //Remove a node from the rear
void removeHeterNode(HeterList* h, int index); //Remove a node from a specified index
void reverseHeterList(HeterList* h); //Reverse a HeterList
heter_node* getNodeAtFront(HeterList* h, int index); //Get the node at a specified index from front (starts from 0)
heter_node* getNodeAtRear(HeterList* h, int index); //Get the node at a specified index from rear (starts from 1)
heter_node* getNodeAt(HeterList* h, int index); //Get the node at a specidied index; negative index is allowed
void printHeterList(HeterList* h); //Prints the HeterList
iterator* heterList2Iter(HeterList* h); //Converts the HeterList to an Iterator

HeterList* newHeterList()
{
	HeterList* h = (HeterList *) malloc(sizeof(HeterList));
	h->head = NULL;
	h->tail = NULL;
	h->size = 0;
	return h;
}
int isEmptyHeterList(HeterList* h)
{
	return h->head==NULL;
}
void addHeterNodeFront(HeterList* h, void* data, void (*cpyData)(void *, void *), void (*printData)(void *))
{
	heter_node* hNode = (heter_node *) malloc(sizeof(heter_node));
	if(hNode)
	{
		hNode->data = malloc(sizeof(void *));
		cpyData(hNode->data, data);
		hNode->printData = printData;
		hNode->cpyData = cpyData;
		hNode->prev = NULL;
		hNode->next = h->head;
		if(isEmptyHeterList(h)) h->tail = hNode;
		else h->head->prev = hNode;
		h->head = hNode;
		h->size++;
	}
}
void addHeterNodeRear(HeterList* h, void* data, void (*cpyData)(void *, void *), void (*printData)(void *))
{
	heter_node* hNode = (heter_node *) malloc(sizeof(heter_node));
	if(hNode)
	{
		hNode->data = malloc(sizeof(void *));
		cpyData(hNode->data, data);
		hNode->printData = printData;
		hNode->cpyData = cpyData;
		hNode->prev = h->tail;
		hNode->next = NULL;
		if(isEmptyHeterList(h)) h->head = hNode;
		else h->tail->next = hNode;
		h->tail = hNode;
		h->size++;
	}
}
void addHeterNode(HeterList* h, int index, void* data, void (*cpyData)(void *, void *), void (*printData)(void *))
{
	if(index==0)
		addHeterNodeFront(h,data,cpyData, printData);
	else if(index==h->size)
		addHeterNodeRear(h,data,cpyData, printData);
	else if(index>h->size)
		printf("\nLIST OUT OF BOUNDS!\n");
	else
	{
		int i=0;
		heter_node* cur;
		
		heter_node* hNode = (heter_node *) malloc(sizeof(heter_node));
		hNode->data = malloc(sizeof(void *));
		cpyData(hNode->data, data);
		hNode->printData = printData;
		hNode->cpyData = cpyData;
		
		for(i=0,cur=h->head;i<index-1;i++,cur=cur->next)
		{}
		
		hNode->prev = cur;
		hNode->next = cur->next;
		cur->next->prev = hNode; 
		cur->next = hNode;
	}
	h->size++;
}
void appendHeterList(HeterList* h, HeterList* h2)
{
	heter_node* cur;
	for(cur = h2->head;cur!=NULL;cur=cur->next)
		addHeterNodeRear(h,cur->data,cur->cpyData,cur->printData);
}
void removeHeterNodeFront(HeterList* h)
{
	if(isEmptyHeterList(h))
		printf("\nEMPTY LIST!\n");
	else
	{
		heter_node* temp = h->head;
		h->head = h->head->next;
		if(h->head) h->head->prev = NULL;
		else h->tail = NULL;
		free(temp);
		h->size--;
	}
}
void removeHeterNodeRear(HeterList* h)
{
	if(isEmptyHeterList(h))
		printf("\nEMPTY LIST!\n");
	else
	{
		heter_node* temp = h->tail;
		h->tail = h->tail->prev;
		if(h->tail) h->tail->next = NULL;
		else h->head = NULL;
		free(temp);
		h->size--;
	}
}
void removeHeterNode(HeterList* h, int index)
{
	if(isEmptyHeterList(h))
		printf("\nEMPTY LIST!\n");
	else if(index==0)
		removeHeterNodeFront(h);
	else if(index==h->size-1)
		removeHeterNodeRear(h);
	else if(index>=h->size)
		printf("\nLIST OUT OF BOUNDS!\n");
	else
	{
		int i=0;
		heter_node *cur, *temp;
		
		for(i=0,cur=h->head;i<index-1;i++,cur=cur->next)
		{}
		
		temp = cur->next;
		
		if(cur->next->next) cur->next->next->prev = cur;
		
		cur->next = cur->next->next;
		free(temp);
	}
	h->size--;
}
void _swapHeterNode(heter_node** n1, heter_node** n2)
{
	heter_node* temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void reverseHeterList(HeterList* h)
{
	if(!isEmptyHeterList(h))
	{
		heter_node* cur;
		for(cur=h->head;cur!=NULL;cur=cur->prev)
		{
			_swapHeterNode(&(cur->next),&(cur->prev));
		}
		_swapHeterNode(&(h->head),&(h->tail));
	}
}
heter_node* getNodeAtFront(HeterList* h, int index)
{
	if(index>=h->size) {printf("\nLIST OUT OF BOUNDS!\n"); return NULL;}
	heter_node* cur=h->head;
	int i;
	for(i=0;i<index;i++)
	{
		cur = cur->next;
	}
	return cur;
}
heter_node* getNodeAtRear(HeterList* h, int index)
{
	if(index>h->size) {printf("\nLIST OUT OF BOUNDS!\n"); return NULL;}
	heter_node* cur=h->tail;
	int i;
	for(i=1;i<index;i++)
	{
		cur = cur->prev;
	}
	return cur;
}
heter_node* getNodeAt(HeterList* h, int index)
{
	if(index<0)
		getNodeAtRear(h,(-1)*index);
	else
		getNodeAtFront(h,index);
}
void printHeterList(HeterList* h)
{
	if(isEmptyHeterList(h))
		printf("\nEMPTY LIST!\n");
	else
	{
		heter_node* cur;
		for(cur=h->head;cur!=NULL;cur=cur->next)
		{
			cur->printData(cur->data); printf(" => ");
		}
		printf("\b\b\b  \n");
	}
}
iterator* heterList2Iter(HeterList* h)
{
	if(isEmptyHeterList(h))
		return NULL;
	else
	{
		iterator* i = newIterator();
		heter_node* cur;
		for(cur=h->head;cur!=NULL;cur=cur->next)
		{
			addIter(i,cur);
		}
		return i;
	}
}
