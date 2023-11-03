#include <stdio.h>
#include <stdlib.h>

#define LEN(X)(sizeof(X)/sizeof(X[0]))

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionSort(int *arr, int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
				temp = j;
		}
		swap(arr+i,arr+temp);
	}
}
int linSearch(int se, int *arr, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(se==arr[i])
			return i;
	}
	return -1;
}
int linSearch_R(int se, int *arr, int n)
{
	if(n<=0)
		return -1;
	else if (arr[n-1]==se)
		return n-1;
	else
		return linSearch_R(se,arr,n-1);
}
int binSearch(int se, int *arr, int n)
{
	int i,l=0,u=n-1,mid;
	
	while(l<=u)
	{
		mid = l + (u-l)/2 ;
		if(se==arr[mid])
			return mid;
		else if(se > arr[mid])
			l = mid + 1 ;
		else
			u = mid - 1;
	}
	return -1;
}
int binSearch_R(int se, int *arr, int l, int u)
{
	if(l>u)
		return -1;
	
	int mid = l + (u-1-l)/2 ;
	if (se==arr[mid])
		return mid;
	else if(se > arr[mid])
		return binSearch_R(se,arr,mid+1,u);
	else
		return binSearch_R(se,arr,l,mid-1);
}

void printArray(int *arr, int n)
{
	int i;
	printf("[ ");
	for(i=0;i<n-1;i++)
		printf("%d | ",*(arr+i));
	printf("%d ]\n",*(arr+i));
}
void main()
{
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	//int arr[] = {1,2,3,4,5,6,7,8,9,10};
	printf("Unsorted Array: "); printArray(arr,LEN(arr));
	selectionSort(arr,LEN(arr));
	printf("Sorted Array: "); printArray(arr,LEN(arr));
	int se = 4;
	printf("%d Found At: %d using linSearch\n",se,linSearch(se,arr,LEN(arr)));
	printf("%d Found At: %d using linSearch_R\n",se,linSearch_R(se,arr,LEN(arr)));
	printf("%d Found At: %d using binSearch\n",se,binSearch(se,arr,LEN(arr)));
	printf("%d Found At: %d using binSearch_R\n",se,binSearch_R(se,arr,0,LEN(arr)));
}
