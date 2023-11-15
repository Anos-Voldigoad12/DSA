#include <stdio.h>
#include "heter_list.h"
#include "utilities.h"

int isEqualNodeData(void* data, void* ref)
{
	heter_node* n = (heter_node *)data;
	if(n->printData==printInt)
		return isEqualInt(n->data,ref);
	else if(n->printData==printDouble)
		return isEqualDouble(n->data,ref);
	else if(n->printData==printChar)
		return isEqualChar(n->data,ref);
	else if(n->printData==printString)
		return isEqualString(n->data,ref);
	else
		return 0;
}
void main()
{
	int i;
	void *j;
	char c;
	double d;
	char s[20];
	HeterList* h = newHeterList();
	i = 10;
	addHeterNodeRear(h,&i,cpyInt,printInt);
	c = 'z';
	addHeterNodeRear(h,&c,cpyChar,printChar);
	d = 12.67;
	addHeterNodeRear(h,&d,cpyDouble,printDouble);
	strcpy(s, "test");
	addHeterNodeRear(h,s,cpyString,printString);
	printf("List: "); printHeterList(h);
	
	printf("Add node at Front: \'a\'...\n");
	
	c = 'a';
	addHeterNodeFront(h,&c,cpyChar,printChar);
	printf("List: "); printHeterList(h);
	
	printf("Add node at index 3: 3...\n");
	
	i = 3;
	addHeterNode(h,3,&i,cpyInt,printInt);
	printf("List: "); printHeterList(h);
	
	printf("\n");
	
	reverseHeterList(h);
	printf("Reversed List: "); printHeterList(h);
	
	printf("\n");
	
	printf("Remove node at Front...\n");
	
	removeHeterNodeFront(h);
	printf("List: "); printHeterList(h);
	
	printf("Remove node at Rear...\n");
	
	removeHeterNodeRear(h);
	printf("List: "); printHeterList(h);
	
	printf("Remove node at index 2...\n");
	
	removeHeterNode(h,2);
	printf("List: "); printHeterList(h);
	
	printf("\n");
	
	iterator* itr = heterList2Iter(h);
	
	printf("Searching for : \"test\"...\n");
	iter_node* found_node = findIter(itr,s,isEqualNodeData);
	if(found_node)
	{
		heter_node* found = (heter_node *)found_node->data;
		printf("Data: "); found->printData(found->data); printf("\n");
		
		printf("Previous Data: "); 
		if(found->prev) found->prev->printData(found->prev->data); 
		else printf("NIL");
		printf("\n");
		
		printf("Next Data: "); 
		if(found->next) found->next->printData(found->next->data); 
		else printf("NIL");
		printf("\n");
	}
	else
		printf("Not Found!\n");
	
	printf("\n");
		
	printf("Searching for : 10...\n");
	i = 10;
	found_node = findIter(itr,&i,isEqualNodeData);
	if(found_node)
	{
		heter_node* found = (heter_node *)found_node->data;
		printf("Data: "); found->printData(found->data); printf("\n");
		
		printf("Previous Data: "); 
		if(found->prev) found->prev->printData(found->prev->data); 
		else printf("NIL");
		printf("\n");
		
		printf("Next Data: "); 
		if(found->next) found->next->printData(found->next->data); 
		else printf("NIL");
		printf("\n");
	}
	else
		printf("Not Found!\n");
	printf("Index: "); scanf("%d",&i);
	heter_node* found = getNodeAt(h,i);
	if(found)
	{
		printf("Data: "); found->printData(found->data); printf("\n");
	}
	HeterList* h2 = newHeterList();
	strcpy(s,"new");
	addHeterNodeRear(h2,s,cpyString,printString);
	i = 17;
	printf("\n");
	addHeterNodeRear(h2,&i,cpyInt,printInt);
	printf("List2: "); printHeterList(h2);
	appendHeterList(h2,h);
	printf("\n");
	printf("New List2: "); printHeterList(h2);
}
