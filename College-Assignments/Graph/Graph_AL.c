#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void *data;
	struct node *next;
}node;
typedef struct
{
	node *head;
	int length;
}List;
List* createList()
{
	List *l = (List *) malloc(sizeof(List));
	l->head = NULL;
	l->length = 0;
	return l;
}
void addNode(void *data, List *l)
{
	node *newNode = (node *) malloc(sizeof(node));
	if(newNode)
	{
		newNode->data = data;
		newNode->next = NULL;
		
		if(l->head==NULL)
			l->head = newNode;
		else
		{
			node* cur;
			for(cur=l->head; cur->next!=NULL; cur=cur->next)
			{}
			cur->next = newNode;
		}
		l->length++;
	}
}
void forEach(List *l, void (*fn)(void *))
{
	node* cur;
	for(cur=l->head; cur!=NULL; cur=cur->next)
	{
		fn(cur->data);
	}
}
node* find(void *search_element, List *l, short int (*compare)(void *, void *))
{
	node* cur;
	for(cur=l->head; cur!=NULL; cur=cur->next)
	{
		if(compare(cur->data,search_element))
			return cur;
	}
	return NULL;
}

typedef struct
{
	int src;
	int dest;
}edge; 
typedef struct
{
	int id;
	List* edgeList;
}vertex;
void addVertex(int id, List *vl)
{
	vertex* v = (vertex *) malloc(sizeof(vertex));
	v->id = id;
	v->edgeList = createList();
	addNode(v,vl);
}
void addEdge(int src, int dest, List *el)
{
	edge* e = (edge *) malloc(sizeof(edge));
	e->src = src;
	e->dest = dest;
	addNode(e,el);
}

void printEdge(void *data)
{
	edge* e = (edge *) data;
	printf("{%d, %d}, ",e->src,e->dest);
}
void printVertex(void *data)
{
	vertex* v = (vertex *) data;
	printf("[%d] : ",v->id);
	forEach(v->edgeList,printEdge);
	printf("\b\b \n");
}

List* createGraph_AL()
{
	List* vertices = createList();
	return vertices;
}
void getEdges(void *data)
{
	vertex* v = (vertex *) data;
	int i,n,src,dest;
	
	printf("Enter number of Edges for Vertex %d: ",v->id);
	scanf("%d",&n);
	
	if(n<=0) return;
	
	printf("Enter the destinations only...\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&dest);
		addEdge(v->id, dest, v->edgeList);
	}
}
void getGraph_AL(List *graph)
{
	int i,j;
	printf("Keep entering Vertices (entering a -ve number will stop input)...\n");
	scanf("%d",&i);
	while(i>=0)
	{
		addVertex(i,graph);
		scanf("%d",&i);		
	}
	forEach(graph,getEdges);
}
void printGraph_AL(List *graph)
{
	printf("GRAPH:\n");
	forEach(graph,printVertex);
}

void setSampleGraph_AL(List *graph)
{
	//VERTICES
	addVertex(1,graph);
	addVertex(2,graph);
	addVertex(3,graph);
	addVertex(4,graph);
	addVertex(5,graph);
	addVertex(6,graph);
	
	node* cur = graph->head;
	vertex* v = (vertex *) cur->data;
	
	//EDGES OF VERTEX 1
	addEdge(1,2,v->edgeList);
	addEdge(1,6,v->edgeList);
	
	cur = cur->next;
	v = (vertex *) cur->data;
	
	//EDGES OF VERTEX 2
	addEdge(2,1,v->edgeList);
	addEdge(2,3,v->edgeList);
	addEdge(2,4,v->edgeList);
	
	cur = cur->next;
	v = (vertex *) cur->data;
	
	//EDGES OF VERTEX 3
	addEdge(3,2,v->edgeList);
	addEdge(3,4,v->edgeList);
	addEdge(3,5,v->edgeList);
	
	cur = cur->next;
	v = (vertex *) cur->data;
	
	//EDGES OF VERTEX 4
	addEdge(4,2,v->edgeList);
	addEdge(4,3,v->edgeList);
	addEdge(4,5,v->edgeList);
	addEdge(4,6,v->edgeList);
	
	cur = cur->next;
	v = (vertex *) cur->data;
	
	//EDGES OF VERTEX 5
	addEdge(5,3,v->edgeList);
	addEdge(5,4,v->edgeList);
	
	cur = cur->next;
	v = (vertex *) cur->data;
	
	//EDGES OF VERTEX 6
	addEdge(6,1,v->edgeList);
	addEdge(6,4,v->edgeList);
}
void main()
{
	List* graph_al = createGraph_AL();
	getGraph_AL(graph_al);
	//setSampleGraph_AL(graph_al);
	printf("\n");
	printGraph_AL(graph_al);
	printf("\n");
}
