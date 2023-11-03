#include <stdio.h>
#include <stdlib.h>

#define MAX(X,Y)(X>Y? X:Y)

typedef struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;
typedef struct
{
	treeNode *root;
}Tree; 

treeNode* createTreeNode(int data)
{
	treeNode* node = (treeNode*) malloc(sizeof(treeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
Tree* createBinTree()
{
	Tree* tree = (Tree *) malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}
treeNode* createTreeFromPreArray(int arr[], int n , treeNode* root)
{
	static int i = -1;
	i++;
	if(i>=n||arr[i]<0)
		return root;
	else
	{
		if(root==NULL)
			root = createTreeNode(arr[i]);
		root->left = createTreeFromPreArray(arr,n,root->left);
		root->right = createTreeFromPreArray(arr,n,root->right);
		return root;			
	}
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
void inorder(treeNode* root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(treeNode* root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int height(treeNode* root)
{
	if(root==NULL)
		return 0;
	else
	{
		return 1 + MAX(height(root->left),height(root->right));
	}
}
int numLeafNodes(treeNode* root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
	{
		return numLeafNodes(root->left) + numLeafNodes(root->right);
	}
}
void main()
{
	//int arr[] = {1,2,4,-1,-1,5,6,-1,-1,-1,3,-1,7,-1,-1};
	int arr[] = {1,5,4,-1,-1,7,-1,-1,8,2,-1,-1,3,-1,-1};
	int n = sizeof(arr)/sizeof(arr[0]);
	Tree* tree = createBinTree();
	tree->root = createTreeFromPreArray(arr,n,tree->root);
	printf("Pre-Order: "); preorder(tree->root);
	printf("\n");
	printf("In-Order: "); inorder(tree->root);
	printf("\n");
	printf("Post-Order: "); postorder(tree->root);
	printf("\n");
	printf("Height: %d\n",height(tree->root));
	printf("Number of Leaf Nodes: %d\n",numLeafNodes(tree->root));
}
