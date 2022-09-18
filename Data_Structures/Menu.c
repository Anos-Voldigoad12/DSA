#include "data_structures.h"

void displayMainMenu()
{
	printf("\t\t=================================\n");
	printf("\t\t|\tDATA STRUCTURES\t\t|\n");
	printf("\t\t=================================\n");
	printf("\t\t|\t<1>STACK\t\t|\n");
	printf("\t\t|\t<2>QUEUE\t\t|\n");
	printf("\t\t|\t<3>LINKED LIST\t\t|\n");
	printf("\t\t=================================\n\n");
}
void displayStackMenu()
{
	printf("\t\t=================================\n");
	printf("\t\t|\t   STACK\t\t|\n");
	printf("\t\t=================================\n");
	printf("\t\t<1>Push\n");
	printf("\t\t<2>Push Multiple\n");
	printf("\t\t<3>Pop\n");
	printf("\t\t<4>Pop Multiple\n");
	printf("\t\t<5>Height of Stack\n");
	printf("\t\t<6>Invert Stack\n");
	printf("\t\t<7>Display Stack\n\n");
}
void displayQueueMenu()
{
	printf("\t\t=================================\n");
	printf("\t\t|\t   QUEUE\t\t|\n");
	printf("\t\t=================================\n");
	printf("\t\t<1>Load\n");
	printf("\t\t<2>Load Multiple\n");
	printf("\t\t<3>Retrieve\n");
	printf("\t\t<4>Retrieve Multiple\n");
	printf("\t\t<5>Length of Queue\n");
	printf("\t\t<6>Reverse Queue\n");
	printf("\t\t<7>Display Queue\n\n");
}
void displayListMenu()
{
	printf("\t\t=================================\n");
	printf("\t\t|\tLINKED LIST\t\t|\n");
	printf("\t\t=================================\n");
	printf("\t\t<1>Append\n");
	printf("\t\t<2>Append Multiple\n");
	printf("\t\t<3>Add Node At\n");
	printf("\t\t<4>Remove Node At\n");
	printf("\t\t<5>Remove Last Node\n");
	printf("\t\t<6>Remove All Occurences\n");
	printf("\t\t<7>Length of List\n");
	printf("\t\t<8>Search\n");
	printf("\t\t<9>Value At\n");
	printf("\t\t<10>Reverse List\n");
	printf("\t\t<11>Display List\n\n");
}
void main()
{
	unsigned short int choice;
	int data,index;
	int i,n; //Loop Counter and Range Respectively
	
	while(1)
	{
		displayMainMenu();	//To Display The Main Menu
		printf("\t\tChoose a Data Structure : "); scanf("%d",&choice);
		
		printf("\n\n");
		switch(choice)
		{	
			//STACK
			case 1 : 
				while(1)
				{
					displayStackMenu(); //To Display The Stack Operations Menu
					printf("\t\tChoose an Operation : "); scanf("%d",&choice);
					
					printf("\n\n");
					switch(choice)
					{
						case 1 :
							printf("\t\tEnter Data To Push : "); scanf("%d",&data);
							push(data);
							break;
						case 2 :
							printf("\t\tKeep Entering Data To Push. Enter -9999 To Stop.\n\t\t"); scanf("%d",&data);
							while(data!=-9999)
							{
								push(data);
								scanf("%d",&data);
							}
							break;
						case 3 :
							data = pop();
							if(data!=ERRORCODE) printf("\t\tElement Popped : %d\n",data);
							break;
						case 4 :
							printf("\t\tNumber Of Elements To Pop : "); scanf("%d",&n);
							for(i=0;i<n;i++)
							{
								data = pop();
								if(data!=ERRORCODE) printf("\t\tElement Popped : %d\n",data);
							}
							break;
						case 5 :
							printf("\t\tHeight Of The Stack : %d\n",stackLength());
							break;
						case 6 :
							invertStack();
							break;
						case 7 :
							displayStack();
							break;
						default : printf("\t\tInvalid Choice!\n");
					}
					
					printf("\n\t\tDo Another Operation(1 for Yes) : "); scanf("%d",&choice);
					printf("\n");
					switch(choice)
					{
						case 1 : continue;
					}
					break;
				}
				break;
			
			//QUEUE
			case 2 :
				while(1)
				{
					displayQueueMenu(); //To Display The Queue Operations Menu
					printf("\t\tChoose an Operation : "); scanf("%d",&choice);
					
					printf("\n\n");
					switch(choice)
					{
						case 1 :
							printf("\t\tEnter Data To Load : "); scanf("%d",&data);
							load(data);
							break;
						case 2 :
							printf("\t\tKeep Entering Data To Load. Enter -9999 To Stop.\n\t\t"); scanf("%d",&data);
							while(data!=-9999)
							{
								load(data);
								scanf("%d",&data);
							}
							break;
						case 3 :
							data = retrieve();
							if(data!=ERRORCODE) printf("\t\tElement Retrieved : %d\n",data);
							break;
						case 4 :
							printf("\t\tNumber Of Elements To Retrieve : "); scanf("%d",&n);
							for(i=0;i<n;i++)
							{
								data = retrieve();
								if(data!=ERRORCODE) printf("\t\tElement Retrieved : %d\n",data);
							}
							break;
						case 5 :
							printf("\t\tLength Of The Queue : %d\n",queueLength());
							break;
						case 6 :
							reverseQueue();
							break;
						case 7 :
							displayQueue();
							break;
						default : printf("\t\tInvalid Choice!\n");
					}
					
					printf("\n\t\tDo Another Operation(1 for Yes) : "); scanf("%d",&choice);
					printf("\n");
					switch(choice)
					{
						case 1 : continue;
					}
					break;
				}
				break;
			
			//SIMPLE LINKED LIST
			case 3 :
				while(1)
				{
					displayListMenu(); //To Display The List Operations Menu
					printf("\t\tChoose an Operation : "); scanf("%d",&choice);
					
					printf("\n\n");
					switch(choice)
					{
						case 1 :
							printf("\t\tEnter Data To Append : "); scanf("%d",&data);
							append(data);
							break;
						case 2 :
							printf("How Many Elements Do You Want To Append : "); scanf("%d",&n);
							printf("\t\tKeep Entering Data To Append\n\t\t");
							for(i=0;i<n;i++)
							{
								
								scanf("%d",&data);
								append(data);
							}
							break;
						case 3 :
							printf("\t\tEnter Data To Add : "); scanf("%d",&data);
							printf("\t\tEnter Index Where Data Is To Be Added : "); scanf("%d",&index);
							addNodeAt(data,index);
							break;
						case 4 :
							printf("\t\tEnter Index From Where Data Is To Be Removed : "); scanf("%d",&index);
							removeNodeAt(index);
							break;
						case 5 :
							removeLastNode();
							break;
						case 6 :
							printf("\t\tEnter Data To Be Removed From The List : "); scanf("%d",&data);
							removeAllOccurences(data);
							break;
						case 7 :
							printf("\t\tLength Of The List : %d\n",listLength());
							break;
						case 8 :
							printf("\t\tEnter Data To Be Searched : "); scanf("%d",&data);
							printf("\t\tFound At Index : %d\n",indexOf(data));
							break;
						case 9 :
							printf("\t\tEnter Index : "); scanf("%d",&index);
							data = valueAt(index);
							if(data!=ERRORCODE) printf("\t\tValue At %dth Index : %d\n",index,data);
							break;
						case 10 :
							reverseList();
							break;
						case 11 :
							displayList();
							break;
						default : printf("\t\tInvalid Choice!\n");
						
					}
					
					printf("\n\t\tDo Another Operation(1 for Yes) : "); scanf("%d",&choice);
					printf("\n");
					switch(choice)
					{
						case 1 : continue;
					}
					break;
				}
				break;
			default :
				printf("\t\tInvalid Choice!\n");
		}
		
		printf("\n\t\tUse Another Data Structure(1 for Yes) : "); scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1 : continue;
		}
		break;
	}
	printf("\t\t\tGOODBYE!!!\n");
}
