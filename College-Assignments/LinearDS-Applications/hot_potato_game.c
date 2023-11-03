#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode
{
	char *name;
	struct QueueNode *next;
}QueueNode;
typedef struct Queue
{
	QueueNode *front;
	QueueNode *rear;
}Queue;
Queue* createQueue()
{
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->front = NULL;
	q->rear  = NULL;
	return q;
}
unsigned short int isEmpty(Queue *q)
{
	return (q->front==NULL);
}
void enqueuePlayer(const char *player, Queue *q)
{
	QueueNode* newPlayer = (QueueNode *) malloc(sizeof(QueueNode));
	newPlayer->name = (char *) malloc( sizeof( (strlen(player)+1)*sizeof(char) ) );
	strcpy(newPlayer->name,player);
	newPlayer->next = NULL;
	
	if(q->front==NULL)
	{
		q->front = newPlayer;
		q->rear  = newPlayer;
	}
	else
	{
		q->rear->next = newPlayer;
		q->rear = q->rear->next;
	}
}
char* dequeuePlayer(Queue *q)
{
	char *player;
	if(isEmpty(q))
	{
		*player = '\0';
	}
	else if(q->front==q->rear)
	{
		QueueNode *temp = q->front;
		q->front = NULL;
		q->rear  = NULL;
		player = (char *) malloc( (strlen(temp->name)+1)*sizeof(char) );
		strcpy(player,temp->name);
		free(temp->name);
		free(temp);
	}
	else
	{
		QueueNode *temp = q->front;
		q->front = q->front->next;
		player = (char *) malloc( (strlen(temp->name)+1)*sizeof(char) );
		strcpy(player,temp->name);
		free(temp->name);
		free(temp); 
	}
	return player;
}
void displayPlayers(Queue *q)
{
	if(!isEmpty(q))
	{
		QueueNode *cur;
		for(cur=q->front;cur!=q->rear;cur=cur->next)
			printf("%s <= ",cur->name);
		printf("%s\n",cur->name);
	}
	else
		printf("Empty Queue!");
}
void getPlayers(int n, Queue *q)
{
	int i;
	char player[30];
	printf("Enter names of %d players...\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%s",player);
		enqueuePlayer(player,q);
	}
}
void playHotPotato()
{
	Queue *q = createQueue();
	int i,n,passCount;
	printf("Enter number of players: "); scanf("%d",&n);
	getPlayers(n,q);
	
	while(q->front!=q->rear)
	{
		printf("Pass Count: "); scanf("%d",&passCount);
		for(i=0;i<passCount;i++)
		{
			enqueuePlayer(dequeuePlayer(q),q);
			printf("Arrangement: "); displayPlayers(q);
		}
		dequeuePlayer(q);
	}
	printf("Winner : %s\n",dequeuePlayer(q));
}
void main()
{
	playHotPotato();
}
