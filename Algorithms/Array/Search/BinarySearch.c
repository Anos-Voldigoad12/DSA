#include <stdio.h>

//Binary Search Function Without Using Recursion
int binarySearch(int search_element , int array[] , int length)
{
	int start=0 , end = length-1 , mid; //Sub Array Positions viz. start, end and mid
	while(start<=end)
	{
		mid = (start+end)/2;
		if(search_element == array[mid])
			return mid;
		else if(search_element < array[mid])
			end = mid - 1;
		else if(search_element > array[mid])
			start = mid + 1;
	}
	return -1;
}
//Binary Search Function Using Recursion
int recursiveBinarySearch(int search_element , int array[] , int start , int end)
{
	int mid = (start+end)/2;
	if (start>end)
		return -1;
	else if(search_element == array[mid])
		return mid;
	else if(search_element < array[mid])
	{
		end = mid - 1;
		return recursiveBinarySearch(search_element,array,start,end);
	}
	else if(search_element > array[mid])
	{
		start = mid + 1;
		return recursiveBinarySearch(search_element,array,start,end);
	}
}
//Sort Functions
void sort(int array[] , int length)
{
	int i,j; //Loop Counters
	int temp;
	for(i=0;i<length-1;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
void selectionSort(int array[] , int length)
{
	int i,j; //Loop Counters 
	int temp,temp_index;
	for(i=0;i<length-1;i++)
	{
		temp = array[i];
		temp_index = i;
		for(j=i+1;j<length;j++)
		{
			if(array[j] < temp)
			{
				temp = array[j];
				temp_index = j;
			}
		}		
		array[temp_index] = array[i];
		array[i] = temp;
	}
}
void bubbleSort(int array[] , int length)
{
	int i; //Loop Counter
	int temp;
	unsigned int flag;
	do
	{
		flag = 0;
		for(i=0;i<length-1;i++)
		{
			if(array[i]>array[i+1])
			{
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				flag++;
			}
		}
	}while(flag!=0);
}
//Driver Code / Main Function
void main()
{
	int i; //Loop Counter
//	int array[] = {1,2,3,4,5,6,7,8,9,10/*,11,12,13,14,15,16*/};
	int length/* = sizeof(array)/sizeof(int)*/;
	int search_element;
	
	printf("Enter length of Array : "); scanf("%d",&length);
	int array[length];
	printf("Enter %d elements to the Array\n",length);
	for(i=0;i<length;i++)
		scanf("%d",&array[i]);
	
	//sort(array,length);
	//selectionSort(array,length);
	bubbleSort(array,length);
		
	printf("\nArray : [\t");
	for(i=0;i<length-1;i++)
	{
		printf("%d\t|\t",array[i]);
	}
	printf("%d\t]\n\n",array[i]);
	
	printf("Enter element to be searched : "); scanf("%d",&search_element);
	printf("%d was found at Index : %d\n", search_element,binarySearch(search_element,array,length) );
// 	printf("%d was found at Index : %d\n", search_element,recursiveBinarySearch(search_element,array,0,length-1) );
}
