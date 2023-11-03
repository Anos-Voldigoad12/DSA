#include <stdio.h>
#include <stdlib.h>

#define MAX(X,Y)(X>Y? X:Y)
#define ABS(X)(((X)<0)? -1*(X) : (X)) 

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
int isBalanced(treeNode* root)
{
	if(root==NULL)
		return 1;
	else
		return (ABS(height(root->left)-height(root->right))<=1) && isBalanced(root->left) && isBalanced(root->right);
}
int isBST(treeNode* root)
{
	if(root==NULL)
		return 1;
	else
	{
		int flag = 1;
		if(root->left!=NULL)
			flag = flag && root->left->data<root->data;
		if(root->right!=NULL)
			flag = flag && root->right->data>root->data;
		return flag;
	}
}
int diameter(treeNode* root)
{
	if(root==NULL)
		return 0;
	else
		return MAX(height(root->left)+height(root->right)+1, MAX(diameter(root->left),diameter(root->right)));
}
void main()
{
	//int arr[] = {1,2,4,-1,-1,5,6,-1,-1,-1,3,-1,7,-1,-1};
	//int arr[] = {40,20,10,-1,-1,30,-1,-1,60,50,-1,-1,70,-1,-1};
	//int arr[] = {1,2,4,8,-1,-1,-1,5,-1,-1,3,-1,-1};
	int arr[] = {1, -1, 2, -1, 3, -1, 4, -1};
	int n = sizeof(arr)/sizeof(arr[0]);
	Tree* tree = createBinTree();
	tree->root = createTreeFromPreArray(arr,n,tree->root);
	preorder(tree->root); printf("\n");
	inorder(tree->root); printf("\n");
	postorder(tree->root); printf("\n");
	if(tree->root!=NULL)
	{
		if(isBalanced(tree->root))
			printf("Tree is BALANCED.\n");
		else
			printf("Tree is NOT BALANCED.\n");
	}
	if(tree->root!=NULL)
	{
		if(isBST(tree->root))
			printf("Tree is a BST.\n");
		else
			printf("Tree is NOT A BST.\n");
	}
	printf("Diameter: %d\n",diameter(tree->root));
}
