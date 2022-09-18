#include <stdio.h>

int count = 0;

void insertionSort(int array[], int length)
{
	int i,j,end=0,tmp;
	for(i=1;i<length;i++)
	{
		end = i-1;
		if(array[i]<array[end])
		{
			tmp = array[i];
			array[i] = array[end];				
			for(j=end;j>0;j--)
			{
				count++;
				if(tmp<array[j-1])
				{
					array[j] = array[j-1];					
				}
				else
					break;				
			}
			
			array[j] = tmp;			
		}
	}
}

void main()
{
	int i; //Loop Counter
	int length;
	int search_element;
	
	printf("Enter length of Array : "); scanf("%d",&length);
	int array[length];
	printf("Enter %d elements to the Array\n",length);
	for(i=0;i<length;i++)
		scanf("%d",&array[i]);
	
	//sort(array,length);
	//selectionSort(array,length);
	//bubbleSort(array,length);
	//bubbleSortN(array,length);
	insertionSort(array,length);
	
	printf("count = %d\n",count);	
	printf("\nArray : [\t");
	for(i=0;i<length-1;i++)
	{
		printf("%d\t|\t",array[i]);
	}
	printf("%d\t]\n\n",array[i]);
}
