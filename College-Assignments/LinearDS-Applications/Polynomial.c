#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	int coefficient;
	int exponent;
	struct List *next;
}Polynomial;

void insertTerm(int coefficient, int exponent, Polynomial **head)
{
	Polynomial *newTerm = (Polynomial *) malloc( sizeof(Polynomial) );
	newTerm->coefficient = coefficient;
	newTerm->exponent = exponent;
	if(*head==NULL)
	{
		newTerm->next = NULL;
		*head = newTerm;
	}
	else	
	{
		
		if(newTerm->exponent<(*head)->exponent)
		{
			newTerm->next = *head;
			(*head) = newTerm;
			return;
		}
		while((*head)->next!=NULL)
		{
			if(newTerm->exponent==(*head)->exponent)
			{
				(*head)->coefficient += newTerm->coefficient;
				return;
			}
			else if(newTerm->exponent>(*head)->exponent)
			{
				if(newTerm->exponent<(*head)->next->exponent)
				{
					newTerm->next = (*head)->next;
					(*head)->next = newTerm;
					return;
				}
			}
			head = &((*head)->next);
		}
		if(newTerm->exponent==(*head)->exponent)
		{
			(*head)->coefficient += newTerm->coefficient;
			return;
		}
		newTerm->next = NULL;
		(*head)->next = newTerm;
	}
}
void displayPolynomial(Polynomial *head)
{
	if(head==NULL)
		printf("\nEMPTY POLYNOMIAL!\n");
	else
	{
		if(head->coefficient==1)
			printf("x^%d ",head->exponent);
		else if(head->exponent==0)
			printf("%d ",head->coefficient);
		else
		{
			while(head->coefficient==0)
				head = head->next;
			printf("%d x^%d ",head->coefficient,head->exponent);
		}
		head = head->next;
		while(head!=NULL)
		{
			if(head->coefficient==1)
				printf("+ x^%d ",head->exponent);
			else if(head->exponent==0)
					printf("+ x^%d ",head->coefficient);
			else if(head->coefficient>0)
				printf("+ %d x^%d ",head->coefficient,head->exponent);
			else if(head->coefficient<0)
				printf("- %d x^%d ",-1*head->coefficient,head->exponent);
				
			head = head->next;
		}
	}
	printf("\n");
}
Polynomial* addPolynomials(Polynomial *poly1, Polynomial *poly2)
{
	if(poly1==NULL||poly2==NULL)
		return NULL;
	else
	{
		Polynomial *newPoly = NULL;
		while(poly1!=NULL)
		{
			insertTerm(poly1->coefficient,poly1->exponent,&newPoly);
			poly1 = poly1->next;
		}
		while(poly2!=NULL)
		{
			insertTerm(poly2->coefficient,poly2->exponent,&newPoly);
			poly2 = poly2->next;
		}
		return newPoly;
	}
}
Polynomial* substractPolynomials(Polynomial *poly1, Polynomial *poly2)
{
	if(poly1==NULL||poly2==NULL)
		return NULL;
	else
	{
		Polynomial *newPoly = NULL;
		while(poly1!=NULL)
		{
			insertTerm(poly1->coefficient,poly1->exponent,&newPoly);
			poly1 = poly1->next;
		}
		while(poly2!=NULL)
		{
			insertTerm(-1*poly2->coefficient,poly2->exponent,&newPoly);
			poly2 = poly2->next;
		}
		return newPoly;
	}
}
Polynomial* multiplyPolynomials(Polynomial *poly1, Polynomial *poly2)
{
	if(poly1==NULL||poly2==NULL)
		return NULL;
	else
	{
		Polynomial *newPoly = NULL;
		Polynomial *current;
		while(poly1!=NULL)
		{
			current = poly2;
			while(current!=NULL)
			{
				insertTerm(poly1->coefficient*current->coefficient,poly1->exponent+current->exponent,&newPoly);
				current = current->next;
			}
			poly1 = poly1->next;
		}
		return newPoly;
	}
}
double evaluatePolynomial(int x, Polynomial *poly)
{
	if(poly==NULL)
		return 0;
	else
	{
		double res = 0;
		Polynomial *cur;
		for(cur=poly;cur!=NULL;cur=cur->next)
		{
			res += cur->coefficient * pow(x,cur->exponent);
		}
		return res;
	}
}
void main()
{
	Polynomial *poly1 = NULL, *poly2 = NULL, *sum = NULL, *difference = NULL, *product = NULL;
	
	insertTerm(1,4,&poly1); insertTerm(5,2,&poly2); 
	insertTerm(5,3,&poly1); insertTerm(10,3,&poly2);
	insertTerm(6,1,&poly1); insertTerm(2,0,&poly2);
	insertTerm(4,0,&poly1); insertTerm(1,0,&poly2);
	
	printf("\nPolynomial 1 : "); displayPolynomial(poly1);
	printf("Polynomial 2 : "); displayPolynomial(poly2);
	
	sum =  addPolynomials(poly1,poly2);
	difference = substractPolynomials(poly1,poly2);
	product = multiplyPolynomials(poly1,poly2);
	
	printf("\nSum of Polynomials 1 & 2 : "); displayPolynomial(sum);
	printf("Difference of Polynomials 1 & 2 : "); displayPolynomial(difference);
	printf("Product of Polynomials 1 & 2 : "); displayPolynomial(product);
	
	printf("\n[For x=2] Polynomial 1: %0.3lf",evaluatePolynomial(2,poly1));
	printf("\n[For x=3] Polynomial 2: %0.3lf",evaluatePolynomial(3,poly2));
}
