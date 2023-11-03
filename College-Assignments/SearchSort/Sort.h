#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b);

void heapify(int *a, int i,int n);
void unheapify(int *a, int n);
void heapSort(int *a, int n);

void insertionSort(int *a, int n);

int partition(int *a, int l, int h);
void quickSort(int *a, int l, int h);

void merge(int *a, int l, int mid, int h);
void mergeSort(int *a, int l, int h);

void selectionSort(int *a, int n);

void bubbleSort(int *a, int n);
void bubbleSortOpt(int *a, int n);

void sort(int *a, int n, char c);
/*
	c = 'h' => Heap Sort
	c = 'i' => Insertion Sort
	c = 'q' => Quick Sort
	c = 'm' => Merge Sort
	c = 's' => Selection Sort
	c = 'b' => Bubble Sort
	c = 'o' => Optimised Bubble Sort
*/



void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int *a, int i,int n)
{
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left<n && a[left]>a[largest])
		largest = left;
	if(right<n && a[right]>a[largest])
		largest = right;
	if(largest!=i)
	{
		swap(a+i,a+largest);
		heapify(a,largest,n);
	}
}
void unheapify(int *a, int n)
{
	int i;
	for(i=n-1;i>0;i--)
	{
		swap(a,a+i);
		heapify(a,0,i);
	}
}
void heapSort(int *a, int n)
{
	int i;
	//Building Max Heap
	for(i=n/2-1;i>=0;i--)
		heapify(a,i,n);
	unheapify(a,n);
}

void insertionSort(int *a, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		j = i;
		while(j>=0&&a[j+1]<a[j])
		{
			swap(a+j,a+j+1);
			j--;
		}
	}
}
int partition(int arr[], int low, int high)
{
 
    // First element as pivot
    int pivot = arr[low];
    int st = low; // st points to the starting of array
    int end = high; // end points to the ending of the array
    int k = high;
    int i;
    for (i = high; i > low; i--) {
        if (arr[i] > pivot)
            swap(&arr[i], &arr[k--]);
    }
    swap(&arr[low], &arr[k]);
    // As we got pivot element index is end
    // now pivot element is at its sorted position
    // return pivot element index (end)
    return k;
}
void quickSort(int *a, int l, int h)
{
	if(l<h)
	{
		int pivot = partition(a,l,h);
		quickSort(a,l,pivot-1);
		quickSort(a,pivot+1,h);
	}	
}
void merge(int *a, int l, int mid, int h)
{
	int i=l,j=mid+1, k=0;
	int *temp = (int *) malloc(sizeof(int)*(h-l+1));
	
	while(i<=mid && j<=h)
	{
		if(a[i]<a[j])
			temp[k++] = a[i++];
		else 
			temp[k++] = a[j++];
	}
	while(i<=mid)
		temp[k++] = a[i++];
	while(j<=h)
		temp[k++] = a[j++];
	
	for(k=l,i=0;k<=h;k++)
		a[k] = temp[i++];
	
	free(temp);
}
void mergeSort(int *a, int l, int h)
{
	if(l<h)
	{
		int mid = l + (h-l)/2 ;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}
void selectionSort(int *a, int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		temp = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[temp])
				temp = j;
		}
		swap(a+i,a+temp);
	}
}
void bubbleSortOpt(int *a, int n)
{
	int i,flag,count=0;
	do
	{
		flag = 0;
		for(i=0;i<n-1;i++)
		{
			count++;
			if(a[i]>a[i+1])
			{
				swap(a+i,a+i+1);
				flag = 1;
			}
		}
	}while(flag);
	printf("\nOptimised Bubble Sort Count: %d\n",count);
}
void bubbleSort(int *a, int n)
{
	int i,j,count=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n-1;i++)
		{
			count++;
			if(a[i]>a[i+1])
				swap(a+i,a+i+1);
		}
	}
	printf("\nBubble Sort Count: %d\n",count);
}

void sort(int *a, int n, char c)
{
	switch(c)
	{
		case 'h' : heapSort(a,n); break;
		case 'i' : insertionSort(a,n); break;
		case 'q' : quickSort(a,0,n-1); break;
		case 'm' : mergeSort(a,0,n-1); break;
		case 's' : selectionSort(a,n); break;
		case 'b' : bubbleSort(a,n); break;
		case 'o' : bubbleSortOpt(a,n); break;
		default: printf("\nInvalid Sort Selected!\n\n");
	}
}
