#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
	int **am;
	int N;
}Graph;
Graph* createGraph_AM(int N)
{
	int i, j;
	Graph* g = (Graph *) malloc(sizeof(Graph));
	g->N = N;
	if(N>MAX)
	{
		g->am = (int **) malloc(sizeof(int*)*N);
		for(i=0;i<N;i++)
		{
			*(g->am + i) = (int *) malloc(sizeof(int)*N);
			for(j=0;j<N;j++)
			{
				*(*(g->am + i)+j) = 0;
			}
		}
	}
	else
	{
		g->am = (int **) malloc(sizeof(int*)*MAX);
		for(i=0;i<MAX;i++)
		{
			*(g->am + i) = (int *) malloc(sizeof(int)*MAX);
			for(j=0;j<MAX;j++)
			{
				*(*(g->am + i)+j) = 0;
			}
		}
	}
	return g;
}
void addEdge(int v1, int v2, int wt , Graph* g)
{
	*(*(g->am+v1-1)+v2-1) = wt;
}
void addVertex(Graph* g)
{
	if(g->N>=MAX)
		printf("ERROR: CAN'T ADD MORE VERTICES!\n'");
	else
	{
		g->N++;
	}	
}
void printGraph_AM(Graph* g)
{
	int i,j;
	printf("GRAPH:\n");
	printf("__| ");
	for(i=0;i<g->N;i++)
	{
		printf("%2d | ",i+1);
	}
	printf("\n");
	for(i=0;i<g->N;i++)
	{
		printf("%2d| ",i+1);
		for(j=0;j<g->N;j++)
		{
			printf("%2d | ",*(*(g->am+i)+j));
		}
		printf("\n");
	}
	printf("\n");
}
void main()
{
	int N = 5;
	Graph* g = createGraph_AM(N);
	printGraph_AM(g);
	addEdge(1,2,1,g);
	addEdge(1,3,1,g);
	addEdge(1,4,1,g);
	addEdge(2,4,1,g);
	addEdge(2,1,1,g);
	addEdge(3,1,1,g);
	addEdge(4,1,1,g);
	printGraph_AM(g);
	addVertex(g);
	printGraph_AM(g);
}
