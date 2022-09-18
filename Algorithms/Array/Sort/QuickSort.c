#include <stdio.h>
#include <time.h>

unsigned int inversion_count=0;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int getPivot(int array[], int start,  int end)
{
	int pivot=start;
	
	start++;
	
	while(start<=end)
	{
		if( array[start]>array[pivot] && array[pivot]>array[end] )
		{
			swap(&array[start],&array[end]);
			inversion_count++;
		}
		if(array[start]<=array[pivot])
		{
			start++;
		}
		if(array[end]>=array[pivot])
		{
			end--;
		}
			
	}
	
	if(array[end]<array[pivot])
	{
		swap(&array[end],&array[pivot]);
		inversion_count++;
		pivot = end;
	}
	
	return pivot;
}
void quickSort(int array[], int start,  int end)
{
	if(start>=end)
		return;
	else
	{
		int pivot = getPivot(array,start,end);
		inversion_count++;
		quickSort(array,start,pivot-1);
		inversion_count++;
		quickSort(array,pivot+1,end);
	}
	
}

void main()
{
	int i;	
//	int a[] = {2,5,3,8,7,1,0,6};								//TEST_CASE : SUCCESS
//	int a[] = {1,2,3,4,5,6,7};									//TEST_CASE : SUCCESS
//	int a[] = {5,4,3,2,1,0};									//TEST_CASE : SUCCESS
//	int a[] = {0,0,0,0,0};										//TEST_CASE : SUCCESS
//	int a[] = {0};												//TEST_CASE : SUCCESS
//	int a[] = {9,0};  											//TEST_CASE : SUCCESS
//	int a[] = {1,9,0,1,5,7};  									//TEST_CASE : SUCCESS
//	int a[] = {24,52,25,9,98,78,65,8,0,9,3,55,30,41};  			//TEST_CASE : SUCCESS
	int a[] = {-2,-200,-6,8,0,0,0,0,7,777};						//TEST_CASE : SUCCESS
	
	int length = sizeof(a)/sizeof(int);
	quickSort(a,0,length-1);
	
	printf("Sorted array : [ ");
	for(i=0;i<length-1;i++)
		printf("%d | ",a[i]);
	printf("%d ]\n",a[i]);
	
	printf("Number of comparisons : %u\n",inversion_count);
}
