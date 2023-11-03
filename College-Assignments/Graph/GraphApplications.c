#include "graph_al.h"

typedef struct stack_node
{
	void *data;
	struct stack_node* prev;
}stack_node;
typedef struct
{
	stack_node* top;
}Stack;
Stack* createStack()
{
	Stack* s = (Stack*) malloc(sizeof(Stack));
	s->top = NULL;
	return s;
}
short int isEmptyS(Stack *s)
{
	return (s->top==NULL);
}
void push(void* data, Stack* s)
{
	stack_node* newNode = (stack_node*) malloc(sizeof(stack_node));
	if(newNode)
	{
		newNode->data = data;
		newNode->prev = s->top;
		s->top = newNode;
	}
}
void* pop(Stack* s)
{
	if(isEmptyS(s))
		return NULL;
	else
	{
		void* temp = s->top->data;
		s->top = s->top->prev;
		return temp;
	}
}

typedef struct queue_node
{
	void *data;
	struct queue_node* next;
}queue_node;
typedef struct
{
	queue_node* front;
	queue_node* rear;
}Queue;
Queue* createQueue()
{
	Queue* q = (Queue*) malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}
short int isEmptyQ(Queue* q)
{
	return (q->front==NULL);
}
void enqueue(void* data, Queue* q)
{
	queue_node* newNode = (queue_node*) malloc(sizeof(queue_node));
	if(newNode)
	{
		newNode->data = data;
		newNode->next = NULL;
		if(isEmptyQ(q))
		{
			q->front = newNode;
			q->rear = q->front;
		}
		else
		{
			q->rear->next = newNode;
			q->rear = q->rear->next;
		}			
	}
}
void* dequeue(Queue* q)
{
	if(isEmptyQ(q))
		return NULL;
	else if(q->front==q->rear)
	{
		void* temp = q->front->data;
		q->front = NULL;
		q->rear = NULL;
		return temp;
	}
	else
	{
		void* temp = q->front->data;
		q->front = q->front->next;
		return temp;
	}
}

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
void dfs(List* graph)
{
	node *cur, *found;
	vertex *v;
	edge *e;
	int i;
	int visited[graph->length];
	for(i=0;i<graph->length;i++)
		visited[i] = 0;
	Stack* s = createStack();
	v = (vertex *) graph->head->data; 
	push(v,s);
	while(!isEmptyS(s))
	{
		v = (vertex *) pop(s);
		if(visited[v->id-1]==0)
		{
			printf("%d, ",v->id);
			visited[v->id-1] = 1;
		}
		else
			continue;
		for(cur=v->edgeList->head;cur!=NULL;cur=cur->next)
		{
			e = (edge *) cur->data;
			found = find(&e->dest,graph,isEqual); 
			if(found) push(found->data,s);
		}
	}
	printf("\b\b \n");
}
void bfs(List* graph)
{
	node *cur, *found;
	vertex *v;
	edge *e;
	int i;
	int visited[graph->length];
	for(i=0;i<graph->length;i++)
		visited[i] = 0;
	Queue* q = createQueue();
	v = (vertex *) graph->head->data; 
	enqueue(v,q);
	while(!isEmptyQ(q))
	{
		v = (vertex *) dequeue(q);
		if(visited[v->id-1]==0)
		{
			printf("%d, ",v->id);
			visited[v->id-1] = 1;
		}
		else
			continue;
		for(cur=v->edgeList->head;cur!=NULL;cur=cur->next)
		{
			e = (edge *) cur->data;
			found = find(&e->dest,graph,isEqual); 
			if(found) enqueue(found->data,q);
		}
	}
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
	printf("DFS: "); dfs(graph_al);
	printf("BFS: "); bfs(graph_al);
}
