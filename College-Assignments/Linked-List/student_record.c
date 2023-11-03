#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	char* name;
	int rollNumber;
	float marks;
	struct Student *next;
};
struct Student *head = NULL;

void addStudent(char name[], int rollNumber, float marks); //This function should add a new student record to the linked list.
void deleteStudent(int rollNumber); //This function should delete the student record with the given roll number from the linked list.
void displayStudents(); //This function should display the details of all the students in the linked list.
int searchStudent(int rollNumber); //This function should search for a student record with the given roll number in the linked list and return its position (index) if found, or -1 if not found

void addStudent(char name[], int rollNumber, float marks)
{
	if(head!=NULL)
	{
		if(searchStudent(rollNumber)!=-1)
		{
			printf("\nStudent Already Exists!\n");
			return;
		}
	}
	struct Student* newStudent = (struct Student*) malloc(sizeof(struct Student));
	newStudent->rollNumber = rollNumber;
	newStudent->name = (char *) malloc((strlen(name)+1)*sizeof(char));
	strcpy(newStudent->name,name);
	newStudent->marks = marks;
	newStudent->next = NULL;
	
	if(head==NULL)
		head = newStudent;
	else
	{
		struct Student* cur = head;
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = newStudent;
	}
}
void deleteStudent(int rollNumber)
{
	if(head==NULL)
	{
		printf("\nEmpty StudentList Exception!\n");
		return;
	}
	if(head->rollNumber==rollNumber)
	{
		head = head->next;
	}
	else if(head->next==NULL)
	{
		printf("\nStudent Not Found Exception!\n");
		return;
	}
	else
	{
		struct Student* cur = head;
		while(cur->next!=NULL)
		{
			if(cur->next->rollNumber!=rollNumber)
				cur = cur->next;
			else
			{
				struct Student* temp = cur->next; 
				cur->next = cur->next->next;
				free(temp->name);
				free(temp);
				return;		
			}			
		}
		printf("\nStudent Not Found Exception!\n");
	}
}
void displayStudents()
{
	if(head==NULL)
		printf("\nEmpty StudentList!\n");
	else
	{
		struct Student* cur = head;
		printf("===========================\n");
		printf("         STUDENTLIST       \n");
		printf("===========================\n");
		while(cur!=NULL)
		{
			printf("\nRoll     : %d\n",cur->rollNumber);
			printf("Name 	 : %s\n",cur->name);
			printf("Marks    : %f\n",cur->marks);
			cur = cur->next;
		}
		printf("===========================\n");
	}
}
int searchStudent(int rollNumber)
{
	if(head!=NULL)
	{
		int i;
		struct Student* cur = head;
		for(i=0;cur!=NULL;i++)
		{
			if(cur->rollNumber==rollNumber)
				return i;
			cur = cur->next;
		}
		return -1;
	}
	else
	{
		printf("\nEmpty StudentList Exception!\n");
		return -1;
	}
}
void main()
{
	int n;
	char name[20];
	float marks;
	while(1)
	{
		printf("\n\n\tMenu\t\n");
		printf("1. Add a Student Record\n");
		printf("2. Delete a Student Record\n");
		printf("3. Display all Student Record\n");
		printf("4. Search Student Record\n");
		printf("5. Exit Program\n");
		printf("\nChoose a List Operation: "); scanf("%d",&n);
		switch(n)
		{
			case 1: 
				printf("Enter roll number of the Student to insert: "); scanf("%d",&n);
				printf("Enter name of the Student to insert: "); scanf(" %[^\n]s",name);
				printf("Enter marks of the Student to insert: "); scanf("%f",&marks);
				addStudent(name,n,marks);
				break;
			case 2:
				printf("Enter Student roll number to delete: "); scanf("%d",&n);
				deleteStudent(n);
				break;
			case 3: 
				displayStudents();
				break;
			case 4:
				printf("Enter roll number to search: "); scanf("%d",&n);
				printf("%d found at: position %d\n",n,searchStudent(n));
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Choice! Please try again!\n");
		}
	}
	
}
