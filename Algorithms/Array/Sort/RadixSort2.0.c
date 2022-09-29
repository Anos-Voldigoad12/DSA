#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int data;
	struct Queue *next;
}Queue;
typedef struct Stack
{
	int data;
	struct Stack *prev;
}Stack;
typedef struct
{
	Stack *negatives;
	Queue *positives;
}Bucket;

Bucket* table[10] = {NULL};

void createBucket(int key)
{
	Bucket *newBucket = (Bucket *) malloc( sizeof(Bucket) );
	if(newBucket==NULL)
		printf("\n!!!  OUT OF MEMORY  !!!\n");
	else
	{
		table[key] = newBucket;
		table[key]->positives = NULL;
		table[key]->negatives = NULL;
	} 
}
void push(int key, int data)
{
	if(table[key]==NULL)
		createBucket(key);
		
	Stack *newNode = (Stack *) malloc( sizeof(Stack) );
	if(newNode==NULL)
		printf("\n!!!  OUT OF MEMORY  !!!\n");
	else
	{
		newNode->data = data;
		newNode->prev = table[key]->negatives;
		table[key]->negatives = newNode;
	}
}
void pop(int key)
{
	Stack *tmp;
	if(table[key]->negatives==NULL)
		printf("\n!!!  EMPTY STACK  !!!\n");
	else
	{
		tmp = table[key]->negatives;
		table[key]->negatives = table[key]->negatives->prev;
		free(tmp);
	}	
}
void enqueue(int key, int data)
{
	if(table[key]==NULL)
		createBucket(key);
		
	Queue *newNode = (Queue *) malloc( sizeof(Queue) );
	if(newNode==NULL)
		printf("\n!!!  OUT OF MEMORY  !!!\n");
	else
	{
		newNode->data = data;
		newNode->next = NULL;
		if(table[key]->positives == NULL)
			table[key]->positives = newNode;
		else
		{
			Queue *current = table[key]->positives;
			while(current->next!=NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
}
void dequeue(int key)
{
	Queue *tmp;
	if(table[key]->positives==NULL)
		printf("\n!!!  EMPTY QUEUE  !!!\n");
	else
	{
		tmp = table[key]->positives;
		table[key]->positives = table[key]->positives->next;
		free(tmp);
	}
}
int getMax(int array[], int length)
{
	int i, max=array[0];
	for(i=1;i<length;i++)
	{
		if(array[i]>max)
			max = array[i];
	}
	return max;
}
int getLength(int n)
{
	int len = 0;
	while(n>0)
	{
		n /= 10;
		len++;
	}
	return len;
}
void radixSort(int array[], int length)
{
	int temp_array[length]; 
	int i,j,k,temp,is_negative=0;
	int num_digits = getLength(getMax(array,length));
	//Cloning the array
	for(i=0;i<length;i++)
	{
		temp_array[i] = array[i];		
	}
	//Main Logic				 
	for(i=1;i<=num_digits;i++) 
	{
		// temp_array --> Bucket
		for(j=0;j<length;j++) 
		{
			temp = temp_array[j];
			
			if(temp<0)
			{
				temp *= -1;
				is_negative = 1;
			}
			for(k=1;k<=i-1;k++)
			{
				temp/=10;
			}
			if(is_negative)
			 	push(temp%10,temp_array[j]);
			else
				enqueue(temp%10,temp_array[j]);
			
			is_negative = 0;
		}
		
		k = 0;
		// Bucket(Stack) --> temp_array {In Reverse Order i.e., from last Bucket to 1st}
		for(j=9;j>=0;j--) 
		{
			if(table[j]==NULL) continue;
			
			while(table[j]->negatives!=NULL)
			{
				temp_array[k++] = table[j]->negatives->data;
				pop(j);
			}
		}
		// Bucket(Queue) --> temp_array {In Regular Order i.e., from 1st Bucket to last}
		for(j=0;j<10;j++) 
		{
			if(table[j]==NULL) continue;
			
			while(table[j]->positives!=NULL)
			{
				temp_array[k++] = table[j]->positives->data;
				dequeue(j);
			}
		}
	}
	//Updating the original array
	for(i=0;i<length;i++)
	{
		array[i] = temp_array[i];		
	}
}
void printArray(int array[], int length)
{
	int i;
	printf("\nArray : [ ");
	for(i=0;i<length-1;i++)
	{
		printf("%d | ",array[i]);
	}
	printf("%d ]",array[i]);
}
void getArray(int array[], int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		scanf("%d",&array[i]);
	}
}

void main()
{
	
//	int a[] = {2,5,3,8,7,1,0,6};								
//	int a[] = {1,2,3,4,5,6,7};									
//	int a[] = {6,5,4,3,2,1,0};									
//	int a[] = {0,0,0,0,0};									
//	int a[] = {0};												
//	int a[] = {9,0};  											
//	int a[] = {1,9,0,1,5,7};  									
//	int a[] = {24,52,25,9,98,78,65,8,0,9,3,55,30,41};  			
//	int a[] = {55,33,222,66,88,2,115};
	int a[] = {-2,-200,-6,8,0,0,0,0,7,777};
	int length = sizeof(a)/sizeof(a[0]);
	
	printArray(a,length); printf("\n");
	radixSort(a,length);
	printArray(a,length); printf("\n");
}
