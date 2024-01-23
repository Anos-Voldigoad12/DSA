#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	unsigned int pid;
	struct List *next; 
}Frame;
void addFrame(int pid, Frame **head)
{
	Frame *newFrame = (Frame *) malloc( sizeof(Frame) );
	
	if(newFrame!=NULL)
	{
		newFrame->pid = pid;
		newFrame->next = NULL;
		
		if(*head==NULL)
			*head = newFrame;
		else
		{
			while((*head)->next!=NULL)
				head = &((*head)->next);
			(*head)->next = newFrame;
		}
	}
}
void removeFirstFrame(Frame **head)
{
	if(*head!=NULL)
	{
		Frame *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

typedef struct 
{
	Frame *list;
	Frame *recent;
	unsigned int cache_size;
	unsigned int frames_count;
	unsigned int number_of_hits;
	unsigned int number_of_faults;
}MRU_Cache;

void initializeCache(MRU_Cache *cache, unsigned int cache_size)
{
	cache->list = NULL;
	cache->recent = NULL;
	cache->cache_size = cache_size;
	cache->number_of_faults = 0;
	cache->number_of_hits = 0;
	cache->frames_count = 0;
}
void accessProcess(unsigned int pid, MRU_Cache *cache)
{
	Frame *head = cache->list;
	while(head!=NULL)
	{
		if(pid==head->pid)
		{
			cache->number_of_hits++;
			cache->recent = head;
			return;
		}
		head = head->next;
	}
	if(cache->frames_count<cache->cache_size)
	{
		addFrame( pid, &(cache->list) );
		cache->frames_count++;
		
		head = cache->list;
		while(head->next!=NULL)
			head = head->next;
		cache->recent = head;
	}
	else
	{
		cache->recent->pid = pid;
	}
	cache->number_of_faults++;
}
void clearCache(MRU_Cache *cache)
{
	while(cache->frames_count>0)
	{
		removeFirstFrame(&(cache->list));
		cache->frames_count--;
	}
	
	cache->recent = NULL;
	cache->number_of_faults = 0;
	cache->number_of_hits = 0;
	cache->frames_count = 0;
}

void printArray(unsigned int array[], int length)
{
	int i;
	printf("[ ");
	for(i=0;i<length-1;i++)
		printf("%u | ",array[i]);
	printf("%u ]\n",array[i]);
}
void main()
{
	int i;
	unsigned cache_size;
	unsigned int processes[] = {0,1,4,2,1,0,11,3,2,5};

	int length = sizeof(processes)/sizeof(processes[0]);
	
	printf("Set Cache Size : "); scanf("%u",&cache_size);
	
	MRU_Cache *cache = (MRU_Cache *) malloc( sizeof(MRU_Cache) );
	initializeCache(cache,cache_size);
	
	printf("Processes : "); printArray(processes,length);
	for(i=0;i<length;i++)
	{
		accessProcess(processes[i],cache);
	}
	
	printf("\nNumber Of Hits : %u\n",cache->number_of_hits);
	printf("Number Of Faults : %u\n",cache->number_of_faults);	 
}
