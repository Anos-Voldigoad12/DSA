#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task
{
	int taskId;
	char *description;
	int priority;
	struct Task *next;
};
typedef struct
{
	struct Task* head;
	int length;
}TaskList;

TaskList* createTaskList();
void addTask(int taskId, char description[], int priority, TaskList *t);
void deleteTask(int taskId, TaskList *t);
void displayTasks(TaskList *t);
int searchTask(int taskId, TaskList *t);
void prioritizeTasks(TaskList *t);

TaskList* createTaskList()
{
	TaskList* newTaskList = (TaskList *) malloc(sizeof(TaskList));
	newTaskList->head = NULL;
	newTaskList->length = 0;
	return newTaskList;
}
void addTask(int taskId, char description[], int priority, TaskList *t)
{
	if(t->head!=0)
	{
		if(searchTask(taskId,t)!=-1)
		{
			printf("\nTask Already Exists!\n");
			return;
		}
	}
	
	struct Task* newTask = (struct Task*) malloc(sizeof(struct Task));
	newTask->taskId = taskId;
	newTask->description = (char *) malloc((strlen(description)+1)*sizeof(char));
	strcpy(newTask->description,description);
	newTask->priority = priority;
	newTask->next = NULL;
	
	if(t->head==NULL)
		t->head = newTask;
	else
	{
		struct Task* cur = t->head;
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = newTask;
	}
	t->length++;
}
void deleteTask(int taskId, TaskList *t)
{
	if(t->head==NULL)
	{
		printf("\nEmpty TaskList Exception!\n");
		return;
	}
	if(t->head->taskId==taskId)
	{
		struct Task* temp = t->head;
		t->head = t->head->next;
		free(temp);
		t->length--;
	}
	else if(t->head->next==NULL)
	{
		printf("\nTask Not Found Exception!\n");
		return;
	}
	else
	{
		struct Task* cur = t->head;
		while(cur->next!=NULL)
		{
			if(cur->next->taskId!=taskId)
				cur = cur->next;
			else
			{
				struct Task* temp = cur->next; 
				cur->next = cur->next->next;
				free(temp->description);
				free(temp);
				t->length--;
				return;		
			}			
		}
		printf("\nTask Not Found Exception!\n");
	}
}
void displayTasks(TaskList *t)
{
	if(t->head==NULL)
		printf("\nEmpty TaskList!\n");
	else
	{
		struct Task* cur = t->head;
		printf("========================\n");
		printf("         TASKLIST       \n");
		printf("========================\n");
		while(cur!=NULL)
		{
			printf("\nTask ID     : %d\n",cur->taskId);
			printf("Description : %s\n",cur->description);
			printf("Priority    : %d\n",cur->priority);
			cur = cur->next;
		}
		printf("========================\n");
	}
}
int searchTask(int taskId, TaskList *t)
{
	if(t->head!=NULL)
	{
		int i;
		struct Task* cur = t->head;
		for(i=0;cur!=NULL;i++)
		{
			if(cur->taskId==taskId)
				return i;
			cur = cur->next;
		}
		return -1;
	}
	else
	{
		printf("\nEmpty TaskList Exception!\n");
		return -1;
	}
}
void swapTask(struct Task *t1, struct Task *t2)
{
	int taskId,priority;
	char description[20];
	
	taskId = t1->taskId;
	priority = t1->priority;
	strcpy(description,t1->description );
	
	t1->taskId = t2->taskId;
	t1->priority = t2->priority;
	strcpy(t1->description,t2->description);
	
	t2->taskId = taskId;
	t2->priority = priority;
	strcpy(t2->description,description);
}
 void prioritizeTasks(TaskList *t)
 {
 	struct Task *start, *cur, *temp;
 	start = t->head;
 	while(start->next!=NULL)
 	{
 		temp = start;
 		cur = start->next;
 		while(cur!=NULL)
 		{
 			if(cur->priority<temp->priority)
 				temp = cur;
 			cur = cur->next;
		}
		swapTask(start,temp);
		start = start->next;
	}
 }
 void main()
 {
 	TaskList *t = createTaskList();
 	int taskId, priority,n;
 	char description[20];
 	
 	//taskId = 1;
 	//priority = 5;
 	//strcpy(description,"manager.exe");
 	//addTask(taskId,description,priority,t);
 	
 	while(1)
	{
		printf("\n\n\tMenu\t\n");
		printf("1. Add Task To TaskList\n");
		printf("2. Delete Task From TaskList\n");
		printf("3. Display TaskList\n");
		printf("4. Prioritize TaskList\n");
		printf("5. Search Task\n");
		printf("6. Exit Program\n");
		printf("\nChoose a List Operation: "); scanf("%d",&n);
		switch(n)
		{
			case 1: 
				printf("Enter task id to insert: "); scanf("%d",&taskId);
				printf("Enter task description to insert: "); scanf(" %[^\n]s",description);
				printf("Enter task priority to insert: "); scanf("%d",&priority);
				addTask(taskId,description,priority,t);
				break;
			case 2:
				printf("Enter task id to delete: "); scanf("%d",&taskId);
				deleteTask(taskId,t);
				break;
			case 3: 
				displayTasks(t);
				break;
			case 4:
				prioritizeTasks(t);
				break;
			case 5:
				printf("Enter task id to search: "); scanf("%d",&taskId);
				printf("Task %d found at: position %d\n",taskId,searchTask(taskId,t));
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid Choice! Please try again!\n");
		}
	}
 }

