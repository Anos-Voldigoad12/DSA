#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define MAX(X,Y)(X>Y? X:Y)

typedef struct treeNode
{
	int data;
	int freq;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;
typedef struct
{
	treeNode *root;
}BST; 

treeNode* createTreeNode(int data)
{
	treeNode* node = (treeNode*) malloc(sizeof(treeNode));
	node->data = data;
	node->freq = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}
BST* createBST()
{
	BST* tree = (BST *) malloc(sizeof(BST));
	tree->root = NULL;
	return tree;
}
void preorder(treeNode* root)
{
	if(root==NULL)
		return;
	else
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
treeNode* insert(int data, treeNode* root)
{
	if(root == NULL)
	{
		return createTreeNode(data);
	}
	else
	{
		if(data == root->data)
			root->freq++;
		else if(data < root->data)
			root->left = insert(data,root->left);
		else
			root->right = insert(data,root->right);
		return root;
	}
}
treeNode* search(int data,treeNode* root)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(data == root->data)
			return  root;
		else if(data < root->data)
			return search(data,root->left);
		else
			return search(data,root->right);
	}
}
treeNode* delete(int data,treeNode* root)
{
	if(root==NULL)
		return NULL;
	
	if(data < root->data)
	{
		root->left = delete(data, root->left);
		return root;
	}
	else if(data > root->data)
	{
		root->right = delete(data, root->right);
		return root;
	}
	
	treeNode* temp;
	if(root->left == NULL)
	{
		temp = root->right;
		free(root);
		return temp;
	}
	else if(root->right == NULL)
	{
		temp = root->left;
		free(root);
		return temp;
	}
	else
	{
		treeNode* succParent = root;
		treeNode* succ = root->right;
		while(succ->left!=NULL)
		{
			succParent = succ;
			succ = succ->left;
		}
		
		if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
		
		root->data = succ->data;
		root->freq = succ->data;
		free(succ);
		return root;
	}
}
treeNode* lca(int n1, int n2, treeNode* root)
{
	if(root==NULL)
		return NULL;
	
	if(root->data==n1 || root->data==n2)
		return root;
		
	treeNode* left_lca = lca(n1,n2, root->left);
	treeNode* right_lca = lca(n1,n2, root->right);
	
	if(left_lca && right_lca)
		return root;
	
	return (left_lca!=NULL)? left_lca:right_lca;
}
void levelorder(treeNode* root)
{
	Queue* q = newQueue();
	enqueue(root,q);
	while(!isEmpty(q))
	{
		treeNode* cur = (treeNode*) dequeue(q);
		if(cur!=NULL)
		{
			printf("%d ",cur->data);
			if(cur->left!=NULL)
				enqueue(cur->left,q);
			if(cur->right!=NULL)
				enqueue(cur->right,q);
		}
	}
}
void menu()
{
	printf("\nBINARY SEARCH TREE OPERATIONS\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Lowest Common Ancestor\n");
	printf("5. Level Order Traversal\n");
	printf("\nChoice: ");
}
void main()
{
	BST* tree = createBST();
	int i,n,tmp,tmp2,choice;
	do
	{
		printf("\n"); menu(); scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("n: "); scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&tmp);
					tree->root = insert(tmp,tree->root);
				}
				printf("Data Inserted Successfully!\n");
				break;
			case 2:
				printf("Enter item to delete: "); scanf("%d",&tmp);
				tree->root = delete(tmp,tree->root);
				break;
			case 3:
				printf("Enter item to Search: "); scanf("%d",&tmp);
				treeNode *found_node = search(tmp,tree->root);
				//printf("\n%p\n",found_node);
				if(found_node)
					printf("%d found in the tree with freq: %d\n",tmp,found_node->freq);
				else
					printf("%d not found!\n",tmp);
				break;
			case 4:
				printf("Enter 2 items to find lca of: ");
				scanf("%d",&tmp); scanf("%d",&tmp2);
				if(search(tmp,tree->root)==NULL||search(tmp2,tree->root)==NULL)
				{
					printf("No Lowest Common Ancestor Found!\n");
					break;
				}
				treeNode* found_lca = lca(tmp,tmp2,tree->root);
				if(found_lca)
					printf("Lowest Common Ancestor of %d and %d is: %d\n",tmp,tmp2,found_lca->data);
				else
					printf("No Lowest Common Ancestor Found for %d and %d\n",tmp,tmp2);
				break;
			case 5:
				printf("Level Order: ");
				levelorder(tree->root);
				printf("\n");
				break;
			default:
				printf("\n\nInvalid Choice!\n\n");
		}
		printf("Continue[Yes=1, No=0]? "); scanf("%d",&choice);
	}while(choice);
	printf("\nGood Bye!\n\n");
}
