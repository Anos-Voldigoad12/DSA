#include <stdio.h>
#include <stdlib.h>

#define LEN(X) ( sizeof(X)/sizeof(X[0]) )

struct Person
{
    char name[20];
    int age;
};

void changeValue(int n)
{
    n = 10;
}
void printArray(int arr[], int n)
{
    int i;
    printf("[ ");
    for(i=0;i<n-1;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("%d ]\n",arr[i]);
}
void modifyArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        arr[i]++;
}
void doubleValue(int *n)
{
    *n *= 2; 
}
void changePersonAge(struct Person p)
{
    p.age ++;
}
void main()
{
    int n  = 20;
    printf("\nValue before changeValue(): %d\n",n);
    changeValue(n);
    printf("Value after changeValue(): %d\n",n);

    int arr[] = {1,2,3,4,5};
    printf("\nArray before modifyArray(): "); printArray(arr,LEN(arr));
    modifyArray(arr,LEN(arr));
    printf("Array after modifyArray(): "); printArray(arr,LEN(arr));

    int *ptr = (int *) malloc(sizeof(int));
    printf("\nEnter an integer: "); scanf("%d",ptr);
    printf("Value before doubleValue(): %d\n",*ptr);
    doubleValue(ptr);
    printf("Value after doubleValue(): %d\n",*ptr);

    struct Person p = {"Bhaskar Saha",20};
    printf("\nBefore changePersonAge()\n");
    printf("Name: %s\tAge: %d\n",p.name,p.age);
    changePersonAge(p);
    printf("After changePersonAge()\n");
    printf("Name: %s\tAge: %d\n",p.name,p.age);
}