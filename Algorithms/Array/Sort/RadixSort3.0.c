/*
	This Program Implements The Radix Sort Algorithm For Signed Integers 
	By Maintaining An Array Of 10(i.e. BASE) Buckets.
	Where, Each Bucket Is A Structure Containing: 
			<1>A Queue, For Keeping The Negative Integers, And,
			<2>A Queue, For Keeping The Positive Integers
	COMPLEXITIES :
	<1> Time  : O(d*(b+n))	;	d = max_number_of_digits, b = base(here 10), n = length_of_array
	<2> Space : O(n)	    ;	n = length_of_array
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int data;
	struct Queue *next;
}Queue;
void enqueue(int data, Queue **head)
{
	Queue *newNode = (Queue *) malloc( sizeof(Queue) );
	
	if(newNode!=NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		
		if(*head==NULL)
			*head = newNode;
		else
		{
			while((*head)->next!=NULL)
				head = &((*head)->next);
			(*head)->next = newNode;
		}
	}
}
void dequeue(Queue **head)
{
	if(*head!=NULL)
	{
		Queue *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
void reverseQueue(Queue **head)
{
	if(*head!=NULL)
	{
		Queue *prev=NULL, *next=(*head)->next;
		while(next!=NULL)
		{
			(*head)->next = prev;
			prev = (*head);
			(*head) = next;
			next = (*head)->next;
		}
		(*head)->next = prev;
	}
}
void displayQueue(Queue *head)
{
	if(head==NULL)
		printf("\nEmpty Queue!\n");
	else
	{
		printf("[ ");
		while(head->next!=NULL)
		{
			printf("%d <= ",head->data);
			head = head->next;
		}
		printf("%d ]\n",head->data);
	}
}

typedef struct Bucket
{
	Queue *negatives;
	Queue *positives;
}Bucket;
void createBucket(Bucket **bucket)
{
	*bucket = (Bucket *) malloc( sizeof(Bucket) );
	(*bucket)->negatives = NULL;
	(*bucket)->positives = NULL;
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
int getMin(int array[], int length)
{
	int i, min=array[0];
	for(i=1;i<length;i++)
	{
		if(array[i]<min)
			min = array[i];
	}
	return min;
}
int getLength(int n)
{
	n = (n<0)? n*-1 : n;
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
	Bucket* table[10] = {NULL};
	int temp_array[length]; 
	int i,j,k,temp,is_negative=0;
	int length_of_min = getLength(getMin(array,length)); int length_of_max = getLength(getMax(array,length));
	int num_digits = (length_of_min>length_of_max)? length_of_min:length_of_max ;
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
			
			if(table[temp%10]==NULL)
				createBucket(&table[temp%10]);
			
			if(is_negative)
			 	enqueue(temp_array[j],&(table[temp%10]->negatives) );
			else
				enqueue(temp_array[j],&(table[temp%10]->positives) );
			
			is_negative = 0;
		}
		
		k = 0;
		if(i!=num_digits)
		{
			// Bucket(Queue *negatives) --> temp_array {In Regular Order i.e., from 1st Bucket to last}
			for(j=0;j<10;j++) 
			{
				if(table[j]==NULL) continue;
				
				while(table[j]->negatives!=NULL)
				{
					temp_array[k++] = table[j]->negatives->data;
					dequeue( &(table[j]->negatives) );
				}
			}	
		}
		else
		{
			// Bucket(Queue *negatives) --> temp_array {In Reverse Order i.e., from last Bucket to 1st}
			for(j=9;j>=0;j--)
			{
				if(table[j]==NULL) continue;
				else reverseQueue( &(table[j]->negatives) );
				
				while(table[j]->negatives!=NULL)
				{
					temp_array[k++] = table[j]->negatives->data;
					dequeue( &(table[j]->negatives) );
				}
			}
		}
		// Bucket(Queue *positives) --> temp_array {In Regular Order i.e., from 1st Bucket to last}
		for(j=0;j<10;j++) 
		{
			if(table[j]==NULL) continue;
			
			while(table[j]->positives!=NULL)
			{
				temp_array[k++] = table[j]->positives->data;
				dequeue( &(table[j]->positives) );
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
	printf("Array : [ ");
	for(i=0;i<length-1;i++)
	{
		printf("%d | ",array[i]);
	}
	printf("%d ]\n",array[i]);
}
void getArray(int array[], int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		scanf("%d",&array[i]);
	}
}

int main()
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
//	int a[] = {-2,-200,-6,8,0,0,0,0,7,777};
//	int a[] = {-2,-200,-6,8,0,0,0,0,7,777,-2000,1478};
	int a[] = {-2,-20,-6,8,0,0,0,0,7,777,-50123};
//	int a[] = {-200,-6,-8,-2,-10};
	int length = sizeof(a)/sizeof(a[0]);
	
	printf("UnSorted "); printArray(a,length); printf("\n");
	radixSort(a,length);
	printf("\nSorted "); printArray(a,length); printf("\n");
	return 0;
}