#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	char dept_name[60];
	char name[60];
	unsigned int roll_number;
	unsigned int total_marks;
	float percentage;
	struct List *next; 
}Student;

unsigned int max_marks = 100;

unsigned int getMaxMarks()
{
	return max_marks;
}
void setMaxMarks(int marks)
{
	max_marks = marks;
}

//String Functions
void toUpper(char* str)
{
	int i;
	for(i=0; str[i]!='\0'; i++)
	{
		if(str[i]>='a' && str[i]<='z')
			str[i] -= 32;
	}
}
unsigned short int isEquals(const char* str1, const char* str2)
{
	int i;
	for(i=0; str1[i]!='\0' || str2[i]!='\0'; i++)
	{
		if( str1[i]!=str2[i] )
			return 0;
	}
	if( str1[i]=='\0' && str2[i]=='\0' )
		return 1;
	else 
		return 0; 
}
void strCpy(char* dest, const char* src)
{
	int i;
	for(i=0; src[i]!='\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}
//Student Functions
Student* createNewStudent()
{
	Student *newStudent = ( Student * ) malloc( sizeof(Student) );
	
	if(newStudent==NULL)
	{
		printf("Memory Unavailable!\n");
	}
	else
	{
		fflush(stdin);
		printf("Enter Name of the Student            : "); scanf("%[^\n]",newStudent->name); fflush(stdin);
		printf("Enter Department Name of the Student : "); scanf("%[^\n]",newStudent->dept_name); toUpper(newStudent->dept_name); fflush(stdin);
		printf("Enter Roll Number of the Student     : "); scanf("%u",&newStudent->roll_number);
		
		while(1)
		{  
		  printf("Enter Total Marks of the Student     : "); scanf("%d",&newStudent->total_marks);
		  if(newStudent->total_marks<=100)
		  	break;
		  printf("\nInvalid Marks! Please Re-enter The Marks!\n\n"); 
		}
		
		newStudent->percentage = ( (float) newStudent->total_marks / getMaxMarks() ) * 100; 
		newStudent->next = NULL;
	}
	return newStudent;
}
void copyStudentDetails(Student *s1, Student *s2)
{
	strCpy(s1->name,s2->name);
	strCpy(s1->dept_name,s2->dept_name);
	s1->roll_number = s2->roll_number;
	s1->total_marks = s2->total_marks;
	s1->percentage = s2->percentage;
	s1->next = NULL;
}
unsigned short int studentExists(Student *s1, Student *head)
{
	if(s1!=NULL)
	{
		while(head!=NULL)
		{
			if( isEquals(s1->dept_name,head->dept_name) && s1->roll_number==head->roll_number )
				return 1;
			head = head->next;
		}
	}
	return 0;
}
void addStudent(Student *newStudent, Student **head)
{
	if(newStudent==NULL)
	{
		printf("Memory Unavailable!\n");
	}
	else
	{
		if(*head==NULL)
		{
			*head = newStudent;
		}
		else
		{
			while((*head)->next!=NULL)
			{
				head = &((*head)->next);
			}
			(*head)->next = newStudent;
		}				
	}
}
void removeStudent(const char* dept_name, unsigned int roll_number, Student **head)
{
	if(*head==NULL)
		printf("\nThere Are No Students In The List.\n");
	else
	{
		Student *temp;
		if( isEquals(dept_name,(*head)->dept_name) && roll_number==(*head)->roll_number )
		{
			temp = *head;
			(*head) = (*head)->next;
			printf("\nStudent Removed : %s\n",temp->name);
			free(temp);
			return;
		}
		while((*head)->next!=NULL)
		{
			if( isEquals(dept_name,(*head)->next->dept_name) && roll_number==(*head)->next->roll_number )
			{
				temp = (*head)->next;
				(*head)->next = (*head)->next->next;
				printf("\nStudent Removed : %s\n",temp->name);
				free(temp);
				return;
			}
			head = &((*head)->next);
		}
		printf("\nStudent Not Found!\n");
	}
}
void generatePassNFailList(Student *head, Student **passList, Student **failList)
{
	if(head==NULL)
	{
		printf("Empty List!\n");
	}
	else
	{
		while(head!=NULL)
		{
			Student *newStudent = ( Student * ) malloc( sizeof(Student) );
			copyStudentDetails(newStudent,head);
			if(head->percentage>=33.0)
			{
				addStudent(newStudent,passList);
			}
			else
			{
				addStudent(newStudent,failList);
			}
			head = head->next;
		}
	}
}
void displayList(Student *head)
{
	if(head==NULL)
	{
		printf("Empty List!\n");
	}
	else
	{
		while(head!=NULL)
		{
			printf("Name        : %s\n",head->name);
			printf("Department  : %s\n",head->dept_name);
			printf("Roll Number : %u\n",head->roll_number);
			printf("Total Marks : %u\n",head->total_marks);
			printf("Percentage  : %g\n",head->percentage);
			printf("\n");
			head = head->next;
		}
	}
}

void displayMenu()
{
	printf("=====================================\n");
	printf("                MENU                 \n");
	printf("=====================================\n");
	printf("<1> Add New Student\n");
	printf("<2> Remove Student\n");
	printf("<3> Generate Pass and Fail Lists\n");
	printf("<4> Display Students List\n");
	printf("<5> Display Pass List\n");
	printf("<6> Display Fail List\n");
	printf("<7> Change Max Marks (Default is 100)\n");
	printf("=====================================\n");
}
int main()
{
	Student *students=NULL, *passList=NULL, *failList=NULL, *temp;
	unsigned int marks, roll_number;
	short int choice;
	char dept_name[60];
	do
	{
		displayMenu();
		printf("Choice : "); scanf("%d",&choice); printf("\n");
		switch(choice)
		{
			case 1: temp = createNewStudent();
					if(!studentExists(temp,students)) { addStudent(temp,&students); }
					else { printf("\nStudent Already Exists!\n"); }
				 	break;
			case 2: 
					fflush(stdin);
					printf("Enter Department Name of the Student : "); scanf("%[^\n]",dept_name); 
						toUpper(dept_name); fflush(stdin);
					printf("Enter Roll Number of the Student     : "); scanf("%u",&roll_number);
					removeStudent(dept_name,roll_number,&students);
					break;
			case 3: generatePassNFailList(students,&passList,&failList); break;
			case 4: printf("\n"); displayList(students); break;
			case 5: printf("\n"); displayList(passList); break;
			case 6: printf("\n"); displayList(failList); break;
			case 7:   
					printf("Max Marks : "); scanf("%u",&marks); 
					setMaxMarks(marks); 
					break;
			default: printf("Invalid Choice!\n");
		}
		printf("\nEnter 0 To Exit, And Any Other Number To Continue. : "); scanf("%d",&choice); printf("\n");
	}while(choice);
}
