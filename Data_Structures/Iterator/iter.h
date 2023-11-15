#include <stdio.h>
#include <stdlib.h>

typedef struct iter_node
{
	void *data;
	struct iter_node *prev, *next;
}iter_node;
typedef struct
{
	iter_node* start;
	iter_node* cur;
	iter_node* end;
}iterator;

iterator* newIterator(); //Creates a new iterator
void addIter(iterator* iter, void *data); //Adds a new node to the iterator
void removeIterFront(iterator* iter); //Removes a node from the front of the iterator
void removeIterRear(iterator* iter); //Removes a node from the rear of the iterator
int hasNextIter(iterator* iter); //Checks if the iterator has a next node
void* nextIter(iterator* iter); //Returns the data of the current node, and moves to the next node
void* prevIter(iterator* iter); //Returns the data of the current node, and moves to the prev node
void* peekIter(iterator* iter); //Returns the data of the current node

void forEachIter(iterator* iter, void (*fn)(void *)); //Applies a void function fn(void *) on each data on the iterator 
iter_node* findIter(iterator* iter, void* ref, int (*cmp)(void *, void *)); //Finds the node which causes the function: void cmp(void* data, void *ref) to be true
void reduceIter(iterator* iter, void* result, void (*op)(void*, void*)); //Applies the function void op(void* result, void *data) on each data on the iterator  
void reverseIter(iterator *iter); //Reverses the iterator

void addIter(iterator* iter, void *data)
{
	iter_node* ni = (iter_node *) malloc(sizeof(iter_node));
	if(ni)
	{
		ni->data = data;
		ni->next = NULL;
		ni->prev = iter->end;
		if(iter->start==NULL)
		{
			iter->start = ni;
			iter->cur = ni;
		}
		else
		{
			iter->end->next = ni;
		}	
		iter->end = ni;
	}
}
void removeIterFront(iterator* iter)
{
	if(iter->start!=NULL)
	{
		iter_node* temp = iter->start;
		iter->start = iter->start->next;
		if(iter->cur==temp) iter->cur = iter->start;
		free(temp);
	}
}
void removeIterRear(iterator* iter)
{
	if(iter->end!=NULL)
	{
		iter_node* temp = iter->end;
		iter->end = iter->end->next;
		if(iter->cur==temp) iter->cur = iter->end;
		free(temp);
	}
}
int hasNextIter(iterator* iter)
{
	return (iter->next!=NULL);
}
void* nextIter(iterator* iter)
{
	if(iter->start)
	{
		iter_node* temp = iter->cur;
		iter->cur = iter->cur->next;
		return temp->data;
	}
	else
		return NULL; 
}
void* prevIter(iterator* iter)
{
	if(iter->start)
	{
		iter_node* temp = iter->cur;
		iter->cur = iter->cur->prev;
		return temp->data;
	}
	else
		return NULL; 
}
void* peekIter(iterator* iter)
{
	if(iter->cur)
		return iter->cur->data;
	else
		return NULL;
}
iterator* newIterator()
{
	iterator* iter = (iterator *) malloc(sizeof(iterator));
	if(iter)
	{
		iter->start = NULL;
		iter->cur = NULL;
		iter->end = NULL;
	}
	return iter;
}
void forEachIter(iterator* iter, void (*fn)(void *))
{
	if(iter->start)
	{
		iter_node* cur;
		for(cur=iter->start;cur!=iter->end->next;cur=cur->next)
		{
			fn(cur->data);
		}
	}
}
iter_node* findIter(iterator* iter, void* ref, int (*cmp)(void *, void *))
{
	if(iter->start)
	{
		iter_node* cur;
		for(cur=iter->start;cur!=iter->end->next;cur=cur->next)
		{
			if(cmp(cur->data,ref))
				return cur;
		}
		return NULL;
	}
}
void reduceIter(iterator* iter, void* result, void (*op)(void*, void*))
{
	if(iter->start)
	{
		iter_node* cur;
		for(cur=iter->start;cur!=iter->end->next;cur=cur->next)
		{
			op(result,cur->data);
		}
	}
}
void swapIterNode(iter_node** i1, iter_node** i2)
{
	iter_node* temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}
void reverseIter(iterator *iter)
{
	if(iter->start)
	{
		iter_node *cur;
		for(cur=iter->start;cur!=NULL;cur=cur->prev)
		{
			swapIterNode(&(cur->prev),&(cur->next));
		}
		swapIterNode(&(iter->start),&(iter->end));
	}
}
