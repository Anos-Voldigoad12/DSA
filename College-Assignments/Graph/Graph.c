#include "graph_al.h"

short int isEqual(void *data, void *se)
{
	vertex* v = (vertex *) data;
	return v->id == *(int *)se;
}
void fillGraph(int N, List* graph)
{
	int i,j;
	node* found_node;
	vertex *v1=NULL,*v2=NULL;
	//Vertices
	for(i=0;i<N;i++)
	{
		addVertex(i+1,graph);
	}
	//EDGES
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(i==j) continue;
			
			if(i%j==0)
			{
				found_node = find(&i, graph, isEqual);
				if(found_node) v1 = (vertex *)found_node->data;
				found_node = find(&j, graph, isEqual);
				if(found_node) v2 = (vertex *)found_node->data;
				
				if(v1&&v2)
				{
					addEdge(v1->id,v2->id,v1->edgeList);
					addEdge(v2->id,v1->id,v2->edgeList);	
				}
			}
		}
	}
}
void printDegree(void *data)
{
	vertex *v = (vertex *) data;
	int degree = 0;
	node* cur;
	for(cur=v->edgeList->head; cur!=NULL; cur=cur->next)
	{
		if( ( (edge *)(cur->data) )->dest == v->id )
			degree += 2;
		else 
			degree++;
	}
	printf("[%d] : %d\n",v->id,degree);
}
void printAllDegrees(List *graph)
{
	forEach(graph, printDegree);
}
void printNeighbour(void *data)
{
	edge* e = (edge *) data;
	printf("%d, ",e->dest);
}
void printAllNeighbours(vertex *v)
{
	printf("[%d] : ",v->id);
	if(v->edgeList)
	{
		forEach(v->edgeList,printNeighbour);
		printf("\b\b \n");
	}
	else
		printf("\n");
}
short int isEqualDest(void *data, void *se)
{
	edge* e = (edge *) data;
	return e->dest == *(int *)se;
}
short int isEqualInt(void *data, void *se)
{
	return *(int*)data == *(int*)se;
}
void printInt(void *data)
{
	printf("%d, ",*(int*)data);
}
void printAllNeighboursOfNeighbours(vertex *v, List *graph)
{
	List *result = createList();
	vertex *v2;
	edge *e, *e2;
	node *cur, *cur2, *found_node, *found_node2;
	printf("[%d] : ",v->id);
	for(cur=v->edgeList->head;cur!=NULL;cur=cur->next)
	{
		e = (edge *) cur->data;
		found_node = find(&e->dest, graph, isEqual);
		if(found_node) v2 = (vertex *)found_node->data;
		for(cur2=v2->edgeList->head;cur2!=NULL;cur2=cur2->next)
		{
			e2 = (edge *) cur2->data;
			if(e2->dest==v->id) continue;
			found_node2 = find(&e2->dest, v->edgeList, isEqualDest);
			if(found_node2==NULL) 
			{
				found_node2 = find(&e2->dest, result, isEqualInt);
				if(found_node2==NULL) addNode(&e2->dest,result);
			}
		}
	}
	forEach(result,printInt);
	printf("\b\b \n");
}
void printCommonNeighbours(vertex *v, vertex *v2, List *graph)
{
	List *result = createList();
	edge *e;
	node *cur, *found_node;
	printf("Common Nodes of [%d] & [%d] : ",v->id,v2->id);
	for(cur=v->edgeList->head;cur!=NULL;cur=cur->next)
	{
		e = (edge *) cur->data;
		found_node = find(&e->dest, v2->edgeList, isEqualDest);
		if(found_node)
		{
			found_node = find(&e->dest, result, isEqualInt);
			if(found_node==NULL) addNode(&e->dest,result);
		}
	}
	forEach(result,printInt);
	printf("\b\b \n");
}
void main()
{
	int N, temp, temp2;
	node* found_node;
	vertex *v1=NULL, *v2=NULL;
	List* graph_al = createGraph_AL();
	printf("N: "); scanf("%d",&N);
	fillGraph(N, graph_al);
	printGraph_AL(graph_al);
	printf("\n");
//	printAllDegrees(graph_al);
	printf("Enter Id of Vertex to print Neighbours: "); scanf("%d", &temp);
	found_node = find(&temp, graph_al, isEqual);
	if(found_node) v1 = (vertex *)found_node->data;
//	printAllNeighbours(v1);
	printAllNeighboursOfNeighbours(v1, graph_al);
	printf("Enter Id of Vertex to print Neighbours: "); scanf("%d", &temp2);
	found_node = find(&temp2, graph_al, isEqual);
	if(found_node) v2 = (vertex *)found_node->data;
	printCommonNeighbours(v1,v2,graph_al);
	
}
