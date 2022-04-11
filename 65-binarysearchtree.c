#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;
int level=0;
void inOrder(NODE*);
int height(NODE*);
NODE *search(NODE*,int);
NODE *delete1(NODE*,int);
NODE *findMin(NODE*);
NODE *findMax(NODE*);
NODE *CreateBST(NODE*,int);
NODE *CreateBST(NODE *root, int n)
{
	if(root==NULL)
	{
		root=(NODE*)malloc(sizeof(NODE));
		root->left=NULL;
		root->right=NULL;
		root->data=n;
		//return root;
	}
	else
	{
		if(n<root->data)
			root->left=CreateBST(root->left,n);
		else
			root->right=CreateBST(root->right,n);
	}
	return root;
}
void inOrder(NODE *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d\n",root->data);
		inOrder(root->right);
	}
}
NODE *search(NODE *root, int key)
{
	if(root==NULL)
	{
		printf("No nodes in tree\n");
	}
	if(root->data==key)
	{
		printf("Data found\n");
		return root;
	}
	else
	{
		if(key<root->data)
			root->left=search(root->left,key);
		else
			root->right=search(root->right,key);
		level++;
	}
}
NODE *findMin(NODE *root)
{
	NODE *temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}
NODE *findMax(NODE *root)
{
	NODE *temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
	return temp;
}
NODE *delete1(NODE *root,int val)
{
	if(root==NULL)
		return root;
	else if(val<root->data)
		root->left=delete1(root->left,val);
	else if(val>root->data)
		root->right=delete1(root->right,val);
	else
	{
		if(root->left==NULL && root->right==NULL)//leafnode
		{
			free(root);
			root=NULL;
			return root;
		}
		else if(root->left==NULL & root->right!=NULL)//single right child
		{
			//NODE *temp;
			//temp=root;
			//temp=root->right;
	//		root->data=temp->data;
			//free(temp);
			root=root->right;
			return root;
		}
		else if(root->right==NULL & root->left!=NULL)//single left child
		{
			NODE *temp;
			temp=root;
			temp=root->left;
		//	root->data=temp->data;
			free(temp);
			return root;
		}
		else
		{
			NODE *temp=findMin(root->right);
			root->data=temp->data;
			root->right=delete1(root->right,temp->data);
			return root;
		}
	}
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int height(NODE *root)
{
	if(root==NULL)
		return 0;
	if(root->right==NULL && root->left==NULL)
		return 1;
	else
		return (1+max(height(root->left),height(root->right)));
}
int main()
{
	int ch,n,key;
	NODE *root,*temp;
	root=NULL;
	do
	{
		printf("Menu\n");
		printf("1. Insert nodes\n2. Search\n3. InOrder Display\n4. Delete a node\n5. Calculate height of tree\n6. Find minimun value\n7. Find maximum value\n8. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter data to insert\n");
				scanf("%d",&n);
				root=CreateBST(root,n);
				break;
			case 2:
				level=0;
				printf("Enter key to search\n");
				scanf("%d",&key);
				temp=search(root,key);
				printf("Data = %d\n",root->data);
				printf("Data is at level %d\n",level);
				break;
			case 3:	printf("Displaying...\n\n");
				inOrder(root);
				break;
			case 4: printf("Enter element to delete\n");
				scanf("%d",&n);
				root=delete1(root,n);
				printf("Data %d deleted\n",root->data);
				break;
			case 5:	printf("Height of tree = %d\n",height(root));
				break;
			case 6: temp=findMin(root);
				printf("Minimum value in tree: %d\n",temp->data);
				break;
			case 7: temp=findMax(root);
				printf("Maximum value in tree: %d\n",temp->data);
				break;
			case 8: printf("Thank you\n");
				exit(0);
			default: ("Invalid Input\nPlease try again\n");
		}
	}while(ch!=8);
	return 0;
}
