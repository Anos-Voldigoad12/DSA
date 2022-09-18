#include <stdio.h>
unsigned inversion_count = 0;

void merge(int array[], int low, int mid ,int high)
{
	int i,j,k;
	int temp_array[high-low+1];
	j = low; k = mid+1;
	
	for( i=0; j<=mid && k<=high ; i++ )
	{	
		if(array[j]<array[k])
		{
			temp_array[i] = array[j++];
		}
		else
		{
			temp_array[i] = array[k++];
			inversion_count++;
		}
	}
	while(j<=mid)
		temp_array[i++] = array[j++];
	while(k<=high)
		temp_array[i++] = array[k++];
	
	k=0;
	for(i=low;i<high+1;i++)
	{
		array[i] = temp_array[k++];	
	}	
}
void mergeSort(int array[], int low, int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		mergeSort(array,low,mid);
		inversion_count++;
		mergeSort(array,mid+1,high);
		inversion_count++;
		merge(array,low,mid,high);
	}
}
void main()
{
	int i;
//	int a[] = {2,5,3,8,7,1,0,6};								//TEST_CASE : SUCCESS
//	int a[] = {1,2,3,4,5,6,7};									//TEST_CASE : SUCCESS
//	int a[] = {6,5,4,3,2,1,0};									//TEST_CASE : SUCCESS
//	int a[] = {0,0,0,0,0};										//TEST_CASE : SUCCESS
	int a[] = {0};												//TEST_CASE : SUCCESS
//	int a[] = {9,0};  											//TEST_CASE : SUCCESS
//	int a[] = {1,9,0,1,5,7};  									//TEST_CASE : SUCCESS
//	int a[] = {24,52,25,9,98,78,65,8,0,9,3,55,30,41};  			//TEST_CASE : SUCCESS
//	int a[] = {-2,-200,-6,8,0,0,0,0,7,777};						//TEST_CASE : SUCCESS
	
	int length = sizeof(a)/sizeof(int);
	
	printf("UnSorted array : [ ");
	for(i=0;i<length-1;i++)
		printf("%d | ",a[i]);
	printf("%d ]\n",a[i]);
	
	mergeSort(a,0,length-1);
	
	printf("Sorted array : [ ");
	for(i=0;i<length-1;i++)
		printf("%d | ",a[i]);
	printf("%d ]\n",a[i]);
	
	printf("Number of comparisons : %u\n",inversion_count);
}
