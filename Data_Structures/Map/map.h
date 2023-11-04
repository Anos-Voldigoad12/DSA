#include <stdio.h>
#include <stdlib.h>

typedef struct map_node
{
	void* key;
	void* data;
}map_node;
typedef struct map_block
{
	map_node block[10];
	struct map_block* next; 
}map_block;
typedef struct map
{
	map_block* first;
	int size;
	int (*genKey)(void*);
	int (*cmp)(void *, void *);
	void (*cpyKey)(void *, void *);
	void (*cpyData)(void *, void *);
}map;

map* newMap(int (*genKey)(void*), int (*cmp)(void*, void*), void (*cpyKey)(void*, void*), void (*cpyData)(void*, void*)); //Used to create a new Map
void addItem(map* m, void* key, void* data); //Used to add a new Key-Value pair to the Map
void* getVal(map* m , void* key); //Get the value corresponding to a given Key in the Map
void** getKeys(map *m); //Returns an array of Keys of the type void *
void** getVals(map *m); //Returns an array of Values of the type void *
void removeItem(map* m , void* key); //Remove the item having the given Key
void printMap(map* m, void (*printKey)(void *), void (*printData)(void *)); //Print the Map

//Internal Functions
map_block* _newMapBlock(); //Create a new Map Block
void _cleanMap(map *m); //Destroy unused Map Blocks
 
map_block* _newMapBlock()
{
	map_block* mb = (map_block *) malloc(sizeof(map_block));
	mb->next = NULL;
	int i;
	for(i=0;i<10;i++)
	{
		mb->block[i].key = NULL;
		mb->block[i].data = NULL;
	}
	return mb;
}
map* newMap(int (*genKey)(void*), int (*cmp)(void*, void*), void (*cpyKey)(void*, void*), void (*cpyData)(void*, void*))
{
	map* m = (map *) malloc(sizeof(map));
	m->first = _newMapBlock();
	m->size = 0;
	m->genKey = genKey;
	m->cmp = cmp;
	m->cpyData = cpyData;
	m->cpyKey = cpyKey;
	return m;
}
void addItem(map* m, void* key, void* data)
{
	int k = m->genKey(key);
	//if the kth item of 1st block is empty
	if(m->first->block[k].key==NULL)
	{
		m->first->block[k].key = malloc(sizeof(void *));
		m->first->block[k].data = malloc(sizeof(void *));
		m->cpyKey(m->first->block[k].key, key);
		m->cpyData(m->first->block[k].data, data);
		m->size++;
	}
	//else if theres no other block
	else if(m->first->next==NULL)
	{
		m->first->next = _newMapBlock();
		m->first->next->block[k].key  = malloc(sizeof(void *));
		m->first->next->block[k].data = malloc(sizeof(void *));
		m->cpyKey(m->first->next->block[k].key, key);
		m->cpyData(m->first->next->block[k].data, data);
		m->size++;
	}
	//else if theres more blocks ; find out the one with space free for kth item
	else
	{
		map_block* cur = m->first->next;
		while(cur->next!=NULL || m->cmp(cur->block[k].key, key))
		{
			cur = cur->next;
		}
		if(cur->block[k].key==NULL)
		{
			cur->block[k].key  = malloc(sizeof(void *));
			cur->block[k].data = malloc(sizeof(void *));
			m->cpyKey(cur->block[k].key, key);
			m->cpyData(cur->block[k].data, data);
		}
		else
		{
			cur->next = _newMapBlock();
			cur->next->block[k].key = malloc(sizeof(void *));
			cur->next->block[k].data = malloc(sizeof(void *));
			m->cpyKey(cur->next->block[k].key, key);
			m->cpyData(cur->next->block[k].data, data);
		}
		m->size++;
	}
}
void* getVal(map* m , void* key)
{
	map_block* cur;
	int k;
	for(cur=m->first;cur!=NULL;cur=cur->next)
	{
		k = m->genKey(key);
		if(cur->block[k].key && m->cmp(cur->block[k].key, key))
		{
			return cur->block[k].data;
		}
	}
	return NULL;
}
void** getKeys(map *m)
{
	void** keys = (void **) calloc(m->size,sizeof(void *));
	map_block *cur;
	int i,j=0;
	for(cur=m->first;cur!=NULL;cur=cur->next)
	{
		for(i=0;i<10;i++)
		{
			if(cur->block[i].key)
			{
				*(keys+j) = malloc(sizeof(void *));
				m->cpyKey(*(keys+j),cur->block[i].key);
				j++;
			}
		}
	}
	return keys;
}
void** getVals(map *m)
{
	void** vals = (void **) calloc(m->size,sizeof(void *));
	map_block *cur;
	int i,j=0;
	for(cur=m->first;cur!=NULL;cur=cur->next)
	{
		for(i=0;i<10;i++)
		{
			if(cur->block[i].key)
			{
				*(vals+j) = malloc(sizeof(void *));
				m->cpyData(*(vals+j),cur->block[i].data);
				j++;
			}
		}
	}
	return vals;
}
void removeItem(map* m , void* key)
{
	map_block* cur;
	int k;
	for(cur=m->first;cur!=NULL;cur=cur->next)
	{
		k = m->genKey(key);
		if(cur->block[k].key && m->cmp(cur->block[k].key, key))
		{
			free(cur->block[k].data);
			free(cur->block[k].key);
			cur->block[k].key = NULL;
			cur->block[k].data = NULL;
			m->size--;
		}
	}
}
void printMap(map* m, void (*printKey)(void *), void (*printData)(void *))
{
	map_block* cur;
	int i;
	printf("{\n");
	for(cur=m->first;cur!=NULL;cur=cur->next)
	{
		for(i=0;i<10;i++)
		{
			if(cur->block[i].key)
			{
				printf("\t["); printKey(cur->block[i].key); printf("] : "); printData(cur->block[i].data); printf("\n");
			}
		}
	}
	printf("}\n");
}
void _cleanMap(map *m)
{
	map_block *cur, *prev;
	int i, count;
	for(cur=m->first;cur!=NULL;prev = cur, cur=cur->next)
	{
		count = 0;
		for(i=0;i<10;i++)
		{
			if(cur->block[i].key)
			{
				count++;
				break;
			}
		}
		if(!count)
		{
			prev->next = cur->next;
			free(cur);
		}
	}
}
