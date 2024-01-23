/*
	This Program Implements The Bucket Sort Algorithm For Floating Point
	Integers Lying In Range(0,1) By Maintaining An Array Of 'b' Buckets,
	Where, 
		Each Bucket Is Essentially A Double Linked List, And,
		b = 1st Digit After Decimal Point Of The Max Element + 1 {inc, Zero}
	COMPLEXITIES :
	<1> Time  : O(b*n^2)	;	b = number_of_buckets, n = length_of_array
	<2> Space : O(n)	;	n = length_of_array 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
	float data;
	struct LinkedList *prev;
	struct LinkedList *next;
}List;

void addNode(float data, List **head)
{
	List *newNode = (List *) malloc( sizeof(List) );
	newNode->data = data;
	newNode->next = NULL;
	
	if(*head == NULL)
	{
		newNode->prev = *head;
		*head = newNode;
	}
	else
	{
		while((*head)->next!=NULL)
		{
			head = &( (*head)->next );
		}
		newNode->prev = *head;
		(*head)->next = newNode;
	}
}
void removeHead(List **head)
{
	if(head==NULL)
		printf("\nEmpty List!\n");
	else
	{
		List *tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
void displayList(List *head)
{
	if(head==NULL)
		printf("\nEmpty List!\n");
	else
	{
		// printf("List : ");
		while(head->next!=NULL)
		{
			printf("%g => ", head->data);
			head = head->next;
		}
		printf("%g\n", head->data);
	}
}
void insertionSortList(List *head)
{
	List *end;
	float temp;
	head = head->next;
	while(head!=NULL)
	{
		end = head->prev;
		if( head->data < end->data )
		{
			temp = head->data;
			head->data = end->data;
			while(end->prev!=NULL)
			{
				if( temp < end->prev->data )
					end->data = end->prev->data;
				else
					break;
				end = end->prev;
			}
			end->data = temp;
		}
		head = head->next;
	}
}
float getMax(float array[], int length)
{
	int i; float max=array[0];
	for(i=1;i<length;i++)
		if(array[i]>max)
			max = array[i];
	return max;
}
unsigned short int isEligibleForBucketSort(float array[], int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		if(array[i]<0 || array[i]>=1)
				return 0;
	}
	return 1;
}
void bucketSort(float array[], int length)
{
	if( !( isEligibleForBucketSort(array,length) ) )
	{
		printf("\n\nNot Eligible For Bucket Sort!\n");
		printf("Suggestion : Use A Different Sort.\n\n");
		exit(0);
	}

	int i,j;
	
	int num_buckets = (int) ( getMax(array,length) * 10 ) + 1;
	List* buckets[num_buckets];
	
	for(i=0;i<num_buckets;i++)
		buckets[i] = NULL;

	for(i=0;i<length;i++)
		addNode( array[i],&buckets[ (int)(10*array[i]) ] );
	
	// Uncomment The Lines Below To Display The Array of Buckets 
	for(i=0;i<num_buckets;i++)
	{
		// printf("%d : ",i);
		if(buckets[i]!=NULL)
		{
			// displayList(buckets[i]);
			insertionSortList(buckets[i]);
		}
		// else
		// 	printf("NULL\n");
	}
	
	printf("\n\n");
	j = 0;
	
	for(i=0;i<num_buckets;i++)
	{
		// printf("%d : ",i);
		if(buckets[i]!=NULL)
		{
			// displayList(buckets[i]);
			while(buckets[i]!=NULL)
			{
				array[j++] = buckets[i]->data;
				removeHead(&buckets[i]);
			}
		}
		// else
		// 	printf("NULL\n");
	}
}
void printArray(float array[], int length)
{
	int i;
	printf("[ ");
	for(i=0;i<length-1;i++)
	{
		printf("%g | ",array[i]);
	}
	printf("%g ]",array[i]);
}
void main()
{
	float a[] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
	// float a[] = {0.49,0.33,0.46,0.23};
	// float a[] = {-2,-200,-6,8,0,0,0,0,7,777};
	int length = sizeof(a)/sizeof(a[0]);

	printf("Unsorted Array : "); printArray(a,length); /*printf("\n\n");*/
	bucketSort(a,length); /*printf("\n\n");*/
	printf("Sorted Array   : "); printArray(a,length); printf("\n\n");
}
