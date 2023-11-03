#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Sort.h" 

#define LEN(X) (sizeof(X)/sizeof(X[0]))

void printArray(int *a, int n)
{
	int i;
	printf("[ ");
	for(i=0;i<n-1;i++)
		printf("%d |",a[i]);
	printf("%d ]\n",a[i]);
}
int main (int argc , char* argv[])
{
	int i;
    if (argc != 4)
    {
        printf("incorrect number of arguments\n");
        printf("given arguments are as follows:\n");
        for(i =0; i <argc; i++)
            printf("%s\n", argv[i]);
        exit(0);
    }
    FILE* fp = fopen (argv[1], "r"); //first line int the line is the size
    int size, *arr;
    i =0;
    if (fp)
    {
        size = atoi(argv[2]);
		arr = (int*)malloc(sizeof(int)*size);
        while (!feof(fp) && i < size)
            fscanf(fp, "%d", &arr[i++]);
        if(i!=size) 
        {
        	printf("%d\n",i);
            printf("insufficient number of inputs, expected %d inputs\n",size); 
            exit(0);
        }
        fclose(fp);
    }
    else
    {
        perror("FILE open error");
        exit(0);
    }
    
    //printf("UnSorted Array: "); printArray(arr,size);
    clock_t start,end;
    double time_used;
    char c = *(argv[3]);
    start = clock();
    sort(arr,size,c);
    end = clock();
    //printf("Sorted Array: "); printArray(arr,size);
    time_used = ( (double) (end - start) ) / CLOCKS_PER_SEC;
    printf("Time Taken: %0.5lf\n",time_used);
    for(i=0;i<size-1;i++)
    {
    	if(arr[i]>arr[i+1])
    	{
    		printf("\nPROBLEM DETECTED!\n");
    		printf("a[%d]: %d\ta[%d+1]: %d\n",i,arr[i],i,arr[i+1]);
    		break;
		}
	}
    free(arr);

}
