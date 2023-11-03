#include "iter.h"

#define LEN(X) ( sizeof(X)/sizeof(X[0]) )

iterator* intArr2Iter(int *arr, int n)
{
	iterator* iter = newIterator();
	int i = 0;
	for(i=0;i<n;i++)
		addIter(iter,arr+i);
	return iter;
}
void printInt(void *data)
{
	printf("%d, ",*(int*)data);
}
int isEqualInt(void* data, void *ref)
{
	return *(int*)data == *(int*)ref;
}
void getSum(void *res, void* data)
{
	*(int *)res += *(int *)data; 
}
void main()
{
	int se = 17;
	int sum = 0;
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	iterator* iter = intArr2Iter(a, LEN(a));
	printf("Next: ");
	printInt(nextIter(iter));
	printf("\b\b \n");
	printf("Prev: ");
	printInt(prevIter(iter));
	printf("\b\b \n");
	printf("Iterator: ");
	forEachIter(iter,printInt);
	printf("\b\b \n");
	iter_node* iNode = findIter(iter,&se,isEqualInt);
	if(iNode) printf("%d Found!\n",se);
	else printf("%d Not Found!\n",se);
	reduceIter(iter,&sum,getSum);
	printf("Sum: %d\n",sum);
	reverseIter(iter);
	printf("Iterator: ");
	forEachIter(iter,printInt);
	printf("\b\b \n");
}
