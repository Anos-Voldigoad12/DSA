#include <stdio.h>
#include <stdlib.h>

#define MAX_MAP_LENGTH 1000

struct CharMapElement
{
	char key;
	int value;
};
typedef struct 
{
	struct CharMapElement ** elements;
	int length;
}CharMap;
struct IntMapElement
{
	int key;
	int value;
};
typedef struct 
{
	struct IntMapElement ** elements;
	int length;
}IntMap;

//Use this one; its a generic one
typedef union 
{
	CharMap *cmap;
	IntMap  *imap;
}Map;

//Here, size refers to the sizeof(type); where 'type' is the type of the key 

Map* createMap(size_t size) 						//Creates a New Map 
void insert(int key, int value, Map *m, size_t size)			//Insert a new Key-Value Pair into the Map
int getValue(int key, Map *m, size_t size)				//Get Value corresponding to a Key 
void* getKeys(Map *m, size_t size)					//Put Value at Key on the Map
short int containsKey(int key, Map *m, size_t size) 			//Returns true if the Key is present in the Map
short int containsValue(int value, Map *m, size_t size) 		//Returns true if the Value is present in the Map
void displayMap(Map *m, size_t size)					//Prints the Map
void destroyMap(Map **m, size_t size)					//Destroys the Map


//CharMap Functions
void insert_c(char key, int value, CharMap *m)
{
	if(m->length==MAX_MAP_LENGTH)
	{
		printf("\nInsufficient Memory!\n");
		return;
	}
	
	int i=0;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->key==key)
			return;
	}
	(m->elements[m->length]) = (struct CharMapElement *) malloc(sizeof(struct CharMapElement)); 
	(m->elements[m->length])->key = key; 
	(m->elements[m->length])->value = value;
	m->length++;
}
int getValue_c(char key, CharMap *m)
{
	if(m==(CharMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return -1;
	}
	
	int i;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->key==key)
			return (m->elements[i])->value;
	}
	return -1;
}
char* getKeys_c(CharMap *m)
{
	if(m==(CharMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return NULL;
	}
	if(m->length==0) return (char *)NULL;
	
	char *temp = (char *) calloc(m->length,sizeof(char));
	int i;
	for(i=0;i<m->length;i++)
	{
		temp[i] = (m->elements[i])->key;
	}
	return temp;
} 
void put_c(char key, int value, CharMap *m)
{
	if(m==(CharMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return;
	}
	if(m->length==0) return;
	
	int i;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->key==key)
		{
			(m->elements[i])->value = value;
			return;
		}
	}
}
short int containsKey_c(char key, CharMap *m)
{
	if(m==(CharMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return -1;
	}
	
	return getValue_c(key,m)!=-1 ;
}
short int containsValue_c(int value, CharMap *m)
{
	if(m==(CharMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return -1;
	}
	
	int i;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->value==value)
			return 1;
	}
	return 0;
}
void displayMap_c(CharMap *m)
{
	if(m==(CharMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return;
	}
	
	int i;
	for(i=0;i<m->length;i++)
	{
		printf("Key:\'%c\'\tValue:%d\n",(m->elements[i])->key,(m->elements[i])->value);
	}
}
void destroyMap_c(CharMap **m)
{
	if(*m==(CharMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return;
	}
	
	CharMap *temp = *m;
	int i;
	for(i=temp->length-1;i>=0;i--)
	{
		free((temp->elements)[i]);
	}
	free(temp);
	*m = NULL;
}

//IntMap Functions
void insert_i(int key, int value, IntMap *m)
{
	if(m->length==MAX_MAP_LENGTH)
	{
		printf("\nInsufficient Memory!\n");
		return;
	}
	
	int i=0;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->key==key)
			return;
	}
	(m->elements[m->length]) = (struct IntMapElement *) malloc(sizeof(struct IntMapElement)); 
	(m->elements[m->length])->key = key; 
	(m->elements[m->length])->value = value;
	m->length++;
}
int getValue_i(int key, IntMap *m)
{
	if(m==(IntMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return -1;
	}
	
	int i;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->key==key)
			return (m->elements[i])->value;
	}
	return -1;
}
int* getKeys_i(IntMap *m)
{
	if(m==(IntMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return NULL;
	}
	if(m->length==0) return (int *)NULL;
	
	int *temp = (int *) calloc(m->length,sizeof(int));
	int i;
	for(i=0;i<m->length;i++)
	{
		temp[i] = (m->elements[i])->key;
	}
	return temp;
} 
void put_i(int key, int value, IntMap *m)
{
	if(m==(IntMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return;
	}
	if(m->length==0) return;
	
	int i;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->key==key)
		{
			(m->elements[i])->value = value;
			return;
		}
	}
}
short int containsKey_i(int key, IntMap *m)
{
	if(m==(IntMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return -1;
	}
	
	return getValue_i(key,m)!=-1 ;
}
short int containsValue_i(int value, IntMap *m)
{
	if(m==(IntMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return -1;
	}
	
	int i;
	for(i=0;i<m->length;i++)
	{
		if((m->elements[i])->value==value)
			return 1;
	}
	return 0;
}
vo	id displayMap_i(IntMap *m)
{
	if(m==(IntMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return;
	}
	
	int i;
	for(i=0;i<m->length;i++)
	{
		printf("Key:\'%c\'\tValue:%d\n",(m->elements[i])->key,(m->elements[i])->value);
	}
}
void destroyMap_i(IntMap **m)
{
	if(*m==(IntMap *)NULL)
	{
		printf("\nMap does not exist! Create a Map first!\n");
		return;
	}
	
	IntMap *temp = *m;
	int i;
	for(i=temp->length-1;i>=0;i--)
	{
		free((temp->elements)[i]);
	}
	free(temp);
	*m = NULL;
}

//Map Functions
Map* createMap(size_t size)
{
	Map* map = (Map *) malloc(sizeof(Map));
	switch(size)
	{
		case sizeof(int) : 
			map->imap = (IntMap *) malloc(sizeof(IntMap));   
			map->imap->elements = (struct IntMapElement**) calloc(MAX_MAP_LENGTH,sizeof(struct IntMapElement *));
			map->imap->length = 0;
			break;
		case sizeof(char): 
			map->cmap = (CharMap *) malloc(sizeof(CharMap));
			map->cmap->elements = (struct CharMapElement**) calloc(MAX_MAP_LENGTH,sizeof(struct CharMapElement *));
			map->cmap->length = 0;
			break;
		default: 
			printf("Unsupported Type!\n"); 
			return NULL;
	}
	return map;
}
void insert(int key, int value, Map *m, size_t size)
{
	switch(size)
	{
		case sizeof(char) :
			insert_c((char)key,value,m->cmap);
			break;
		case sizeof(int):
			insert_i(key,value,m->imap);
			break;
		default: 
			printf("Unsupported Type!\n"); 
	}		
}
int getValue(int key, Map *m, size_t size)
{
	switch(size)
	{
		case sizeof(char) :
			return getValue_c((char)key,m->cmap);
			break;
		case sizeof(int):
			return getValue_i(key,m->imap);
			break;
		default: 
			printf("Unsupported Type!\n");
			return -1; 
	}
}
void* getKeys(Map *m, size_t size)
{
	switch(size)
	{
		case sizeof(char) :
			return (void*) getKeys_c(m->cmap);
			break;
		case sizeof(int):
			return (void*) getKeys_i(m->imap);
			break;
		default: 
			printf("Unsupported Type!\n"); 
	}	
} 
void put(int key, int value, Map *m, size_t size)
{	
	switch(size)
	{
		case sizeof(char) :
			put_c((char)key,value,m->cmap);
			break;
		case sizeof(int):
			put_i(key,value,m->imap);
			break;
		default: 
			printf("Unsupported Type!\n"); 
	}
}
short int containsKey(int key, Map *m, size_t size)
{
	switch(size)
	{
		case sizeof(char) :
			return containsKey_c((char)key,m->cmap);
			break;
		case sizeof(int):
			return containsKey_i(key,m->imap);
			break;
		default: 
			printf("Unsupported Type!\n");
			return 0; 
	}
}
short int containsValue(int value, Map *m, size_t size)
{	
	switch(size)
	{
		case sizeof(char) :
			return containsValue_c(value,m->cmap);
		case sizeof(int):
			return containsValue_i(value,m->imap);
		default: 
			printf("Unsupported Type!\n");
			return 0; 
	}
}
void displayMap(Map *m, size_t size)
{
	switch(size)
	{
		case sizeof(char) :
			displayMap_c(m->cmap);
			break;
		case sizeof(int):
			displayMap_i(m->imap);
			break;
		default: 
			printf("Unsupported Type!\n"); 
	}
}
void destroyMap(Map **m, size_t size)
{
	switch(size)
	{
		case sizeof(char) :
			destroyMap_c(&((*m)->cmap));
			break;
		case sizeof(int):
			destroyMap_i(&((*m)->imap));
			break;
		default: 
			printf("Unsupported Type!\n"); 
	}
	*m = NULL;
}
