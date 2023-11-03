#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN(X) (sizeof(X)/sizeof(X[0]))
#define BOOL(X) (X? "TRUE" : "FALSE")

int arraySum(int a[], int n)
{
	if(n == 0)
		return 0;
	else
		return *a + arraySum(a+1,n-1);
}
void reverseString(char* dest, const char *src, int n)
{
	if(n==0)
		*dest = '\0';
	else
	{
		*dest = *(src+n-1);
		reverseString(dest+1,src,n-1);
	}
}
unsigned int equalsIgnoreCase(char c1, char c2)
{
	return (c1==c2 || c1+32==c2 || c1==c2+32);
}
unsigned int isPunctuationOrSpace(char c)
{
	switch(c)
	{
		case ';':
		case '.':
		case ',':
		case '-':
		case ':':
		case ' ':
				return 1;
		default : return 0;
	}
}
unsigned int checkPalindrome(char *src, int n)
{
	if(n<=2)
		return 1;
	else if( isPunctuationOrSpace(*src) )
		return checkPalindrome(src+1,n-1);
	else if( isPunctuationOrSpace(*(src+n-1)) )
		return checkPalindrome(src,n-1);
	else
		return equalsIgnoreCase(*src,*(src+n-1) ) && checkPalindrome(src+1,n-2);
}
unsigned long long int power(unsigned int b, unsigned int n)
{
	if(n==0)
		return 1;
	else
		return b * power(b,n-1);
}
void TOH(int n, char src, char aux, char dest)
{
	if(n==1)
		printf("Move disk from %c -> %c\n",src,dest);
	else
	{
		TOH(n-1,src,dest,aux);
		printf("Move disk from %c -> %c\n",src,dest);
		TOH(n-1,aux,src,dest);
	}
}
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}
void generatePermutations(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }
	int i;
    for (i = start; i <= end; i++) {
        swap(&str[start], &str[i]);
        generatePermutations(str, start + 1, end);
        swap(&str[start], &str[i]); // backtrack
    }
}

//Driver
void getArray(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",a+i);
}
void displayArray(int *a, int n)
{
	int i;
	printf("[ ");
	for(i=0;i<n-1;i++)
		printf("%d | ",a[i]);
	printf("%d ]\n",a[i]);
}
void displayMenu()
{
	printf("          MENU         \n");
	printf("1. Array Sum\n");       
	printf("2. Reverse String\n");  
	printf("3. Check Palindrome\n");
	printf("4. Power\n");           
	printf("5. Tower of Hanoi\n");  
	printf("6. Permutations of String\n");
	printf("\n");
	printf("Choice: ");
}
void main()
{
	int n,b;
	char str[20];
	char rev[20];
	int *a;
	
	do
	{
		displayMenu();
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Array Length: "); scanf("%d",&n);
				a = (int *) malloc(sizeof(int)*n);
				printf("Array: "); getArray(a,n);
				printf("Sum: %d\n",arraySum(a,n));
				break;
			case 2:
				printf("Enter Word: "); scanf("%s",str);
				reverseString(rev,str,strlen(str));
				printf("Reversed String: %s\n",rev);
				break;
			case 3:
				printf("Enter Word: "); scanf(" %[^\n]s",str);
				printf("Is Palindrome? %s\n",BOOL(checkPalindrome(str,strlen(str))));
				break;
			case 4:
				printf("Base(b)     : "); scanf("%d",&b);
				printf("Exponent(n) : "); scanf("%d",&n);
				printf("b^n = %d\n",power(b,n));
				break;
			case 5:
				printf("[The Pegs Are : A, B, C]\n");
				printf("[Source: A, Auxiliary: B, Destination:C ]\n\n");
				printf("Number of Discs(n): "); scanf("%d",&n);
				TOH(n,'A','B','C');
				break;
			case 6:
				printf("Word: "); scanf("%s",str);
				printf("\nThe Permutations are:\n"); generatePermutations(str,0,strlen(str)-1);
				break;
			default:
				printf("INVALID CHOICE!");
		}
		printf("\nContinue(Yes = 1, No = 0)? "); scanf("%d",&n);
		printf("\n");
	}while(n);
	
			
}
