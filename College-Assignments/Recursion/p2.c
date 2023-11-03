#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
typedef struct
{
	struct Node* head;
	int length;
}List;

List* createList();
void addNode(int data, List *l);
void deleteNode(int data, List *l);

List* createList()
{
	List* newList = (List *) malloc(sizeof(List));
	newList->head = NULL;
	newList->length = 0;
	return newList;
}
void addNode(int data, List *l)
{	
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(l->head==NULL)
		l->head = newNode;
	else
	{
		struct Node* cur = l->head;
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = newNode;
	}
	l->length++;
}
void deleteNode(int data, List *l)
{
	if(l->head==NULL)
	{
		printf("\nEmpty List Exception!\n");
		return;
	}
	if(l->head->data==data)
	{
		struct Node* temp = l->head;
		l->head = l->head->next;
		free(temp);
		l->length--;
	}
	else if(l->head->next==NULL)
	{
		printf("\nValue Not Found Exception!\n");
		return;
	}
	else
	{
		struct Node* cur = l->head;
		while(cur->next!=NULL)
		{
			if(cur->next->data!=data)
				cur = cur->next;
			else
			{
				struct Node* temp = cur->next; 
				cur->next = cur->next->next;
				free(temp);
				l->length--;
				return;		
			}			
		}
		printf("\nValue Not Found Exception!\n");
	}
}
void displayList(List *l)
{
	if(l->head!=NULL)
	{
		struct Node* cur = l->head;
		while(cur->next!=NULL)
		{
			printf("%2d => ",cur->data);
			cur = cur->next;
		}
		printf("%2d\n",cur->data);
	}
	else
	{
		printf("\nEmpty List Exception!\n");
		return;
	}
}
int getListLength_Recursive(struct Node* curNode)
{
	if(curNode==NULL)
		return 0;
	else
		return 1 + getListLength_Recursive(curNode->next);
}
int searchList_Recursive(int data, struct Node* curNode)
{
	static int i = 0;
	if(curNode==NULL)
		return -1;
	else
	{
		if(curNode->data==data)
			return i;
		else
		{
			i++;
			searchList_Recursive(data, curNode->next);
		}
	}
}
void mergeLists_Recursive(struct Node* curNode1, struct Node* curNode2, List *newL)
{
	if(curNode1==NULL && curNode2!=NULL)
	{
		addNode(curNode2->data,newL);
		mergeLists_Recursive(curNode1,curNode2->next, newL);
	}
	else if(curNode1!=NULL && curNode2==NULL)
	{
		addNode(curNode1->data,newL);
		mergeLists_Recursive(curNode1->next,curNode2, newL);
	}
	else if(curNode1!=NULL && curNode2!=NULL)
	{
		if(curNode1->data < curNode2->data)
		{
			addNode(curNode1->data,newL);
			mergeLists_Recursive(curNode1->next,curNode2, newL);
		}
		else
		{
			addNode(curNode2->data,newL);
			mergeLists_Recursive(curNode1,curNode2->next, newL);
		}
	}
	else
		return;	
}
void reverseList_Recursive(List *l, struct Node* prevNode)
{
	if(l->head->next==NULL)
	{
		l->head->next = prevNode;
		return;
	}
	else
	{
		struct Node* curNode = l->head;
		l->head = l->head->next;
		reverseList_Recursive(l,curNode);
		curNode->next = prevNode;
	}
}
struct Node* reverseList_Recursive_Node(struct Node* curNode, struct Node* prevNode)
{
	if(curNode->next==NULL)
	{
		curNode->next = prevNode;
		return curNode;
	}
	else
	{
		struct Node* retNode = reverseList_Recursive_Node(curNode->next,curNode);
		curNode->next = prevNode;
		return retNode;
	}
}	
struct Node* reverseList_Recursive_NodeS(struct Node* curNode) //Sir's Solution
{
	if( !curNode|| !(curNode->next) )
	{
		return curNode;
	}
	else
	{
		struct Node* retNode = reverseList_Recursive_NodeS(curNode->next);
		curNode->next->next = curNode;
		curNode->next = NULL;
		return retNode;
	}
}
struct Node* findMiddle(struct Node* slow, struct Node* fast) {
    if (fast == NULL || fast->next == NULL)
        return slow;
    return findMiddle(slow->next, fast->next->next);
}
int isOpenParenthesis(char *str, int start, int end)
{
	if(start==end)
		return 0;
	else if(str[end]==')')
		return 0;
	else
		return isBalanced(str,start,end-1);
}
int isBalanced(char *str, int start, int end)
{
	if(start==end)
		return 1;
	else if(str[start]=='(')
		return 1 && !isOpenParenthesis(str,start+1,end);
}
//void listOperations(List *l)
//{
//	int n;
//	do
//	{
//		printf("\nLIST OPERATIONS\n");
//		printf("1. Add Node\n");
//		printf("2. Delete Node\n");
//		printf("3. Display List\n");
//		printf("4. Exit");
//		printf("\nChoice: "); scanf("%d",&n);
//		switch(n)
//		{
//			case 1:
//				printf("Data: "); scanf("%d",&n);
//				addNode(n,l);
//				break;
//			case 2:
//				deleteNode()
//		}
//	}while(n!=6);
//}
void main()
{
	int n=60;
	List *l1 = createList();
	addNode(10,l1);
	addNode(20,l1);
	addNode(30,l1);
	addNode(40,l1);
	addNode(50,l1);
//	struct Node* mid = findMiddle(l1->head,l1->head);
//	List *l2 = createList();
//	addNode(9,l2);
//	addNode(20,l2);
//	addNode(33,l2);
//	addNode(44,l2);
//	addNode(55,l2);
//	List *l3 = createList();
//	mergeLists_Recursive(l1->head,l2->head,l3);
	
	//printf("%d Found At: %d\n",n,searchList_Recursive(n,l->head));
	printf("List1: "); displayList(l1);
	printf("List Length: %d\n",getListLength_Recursive(l1->head));
//	printf("Mid: %d\n",mid->data);
//	printf("List2: "); displayList(l2);
//	printf("\nMerged List: "); displayList(l3);
//	reverseList_Recursive(l1,NULL);
	//l1->head= reverseList_Recursive_NodeS(l1->head);
	//printf("List1: "); displayList(l1);
	//char str[] = "(a+(b*c)/2)+2d";
	//if(isBalanced(str,0))
//		printf("Balanced");
//	else
//		printf("UnBalanced");
}
