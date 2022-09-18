#include <stdio.h>

typedef struct
{
	int max;
	int min;
}Bounds;

Bounds getBounds(int array[], int length)
{
	int i;
	Bounds result;
	result.max = result.min = array[0];
	for(i=1;i<length;i++)
	{
		if(array[i]>result.max)
			result.max = array[i];
		else if(array[i]<result.min)
			result.min = array[i];
	}
	return result;
}
void countingSortWithRange(int array[], int length,int range)
{
	int i,j;
	int freq[range+1];
	for(i=0; i<=range; i++)
		freq[i] = 0;
	for(i=0;i<length;i++)
	{
		freq[array[i]]++;
	}
	for(i=0,j=0; i<=range; i++)
	{
		while(freq[i]!=0)
		{
			array[j++] = i;
			freq[i]--;
		}
	}
}
void countingSortWithBounds(int array[], int length,int lb, int ub)
{
	if(lb<0)
	{
		int i,j;
		int freq[ub-lb+1];
		for(i=0; i<=ub-lb; i++)
			freq[i] = 0;
		for(i=0;i<length;i++)
		{
			freq[ array[i] - lb ]++;
		}
		for(i=0,j=0; i<=ub-lb; i++)
		{
			while(freq[i]!=0)
			{
				array[j++] = i + lb;
				freq[i]--;
			}
		}
	}
	else
	{
		countingSortWithRange(array,length,ub);
	}
}
void main()
{
	int i;
//	int a[] = {2,5,3,8,7,1,0,6};								//TEST_CASE : SUCCESS
//	int a[] = {1,2,3,4,5,6,7};									//TEST_CASE : SUCCESS
//	int a[] = {6,5,4,3,2,1,0};									//TEST_CASE : SUCCESS
//	int a[] = {0,0,0,0,0};										//TEST_CASE : SUCCESS
//	int a[] = {0};												//TEST_CASE : SUCCESS
//	int a[] = {9,0};  											//TEST_CASE : SUCCESS
//	int a[] = {1,9,0,1,5,7};  									//TEST_CASE : SUCCESS
//	int a[] = {24,52,25,9,98,78,65,8,0,9,3,55,30,41};  			//TEST_CASE : SUCCESS
	int a[] = {-2,-200,-6,8,0,0,0,0,7,777};						//TEST_CASE : SUCCESS
	
	int length = sizeof(a)/sizeof(int);
	Bounds temp = getBounds(a, length);
	
	printf("UnSorted array : [ ");
	for(i=0;i<length-1;i++)
		printf("%d | ",a[i]);
	printf("%d ]\n",a[i]);
	
	countingSortWithBounds(a,length,temp.min,temp.max);
	
	printf("Sorted array : [ ");
	for(i=0;i<length-1;i++)
		printf("%d | ",a[i]);
	printf("%d ]\n",a[i]);
}
