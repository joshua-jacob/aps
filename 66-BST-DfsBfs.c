#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	int visited;
}NODE;
int level=0,count=0;
int qf=0,qr=-1,qc=0;
void inOrder(NODE*);
int height(NODE*);
NODE *search(NODE*,int);
NODE *delete1(NODE*,int);
NODE *findMin(NODE*);
NODE *findMax(NODE*);
NODE *CreateBST(NODE*,int);
void DFS(NODE*);
NODE *CreateBST(NODE *root, int n)
{
	if(root==NULL)
	{
		root=(NODE*)malloc(sizeof(NODE));
		root->left=NULL;
		root->right=NULL;
		root->data=n;
		root->visited=FALSE;
		count++;
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
NODE *ancestor(NODE *root, int key)
{
	if(root==NULL)
	{
		printf("No nodes in tree\n");
		return NULL;
	}
	if(root->data!=key)
	{
		if(key<root->data)
			root->left=ancestor(root->left,key);
		else
			root->right=ancestor(root->right,key);
		printf("%d\n",root->data);
	}
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
		else if(root->left==NULL && root->right!=NULL)//single right child
		{
			//NODE *temp;
			//temp=root;
			//temp=root->right;
	//		root->data=temp->data;
			//free(temp);
			root=root->right;
			return root;
		}
		else if(root->right==NULL && root->left!=NULL)//single left child
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
void DFS(NODE *root)
{
	if(root==NULL)
		return;
	else
	{
		root->visited=TRUE;
		printf("%d\n",root->data);
		DFS(root->left);
		DFS(root->right);
	}
}
void makevisitedzero(NODE *root)
{
	if(root!=NULL)
	{
		makevisitedzero(root->left);
		root->visited=FALSE;
		makevisitedzero(root->right);
	}
}
void enq(NODE *q[],NODE *r)
{
	qr++;qc++;
	r->visited=TRUE;
	q[qr]=r;
	printf("Queue\n");
	int i;
	for(i=0;i<qc;i++)
	{
		printf("%d\n",q[i]->data);
	}
}
void BFS(NODE *root)
{
	NODE* q[count];
	printf("Count = %d\n",count);
	int i=0;
	NODE *CWN;
	CWN=root;
	enq(q,CWN);
	while(i<count && CWN!=NULL)
	{
		/*if(CWN->left->visited==TRUE && CWN->right->visited==TRUE)
		{
			printf("%d\n",CWN->data);
			qf++;
			qc--;
		}*/
		/*else
		{
			if(CWN->left==NULL || CWN->right==NULL)
			{
				printf("%d\n",CWN->data);
				qf++;
				qc--;
			}
			else
			{*/
		if(CWN->left!=NULL)
			enq(q,CWN->left);
		if(CWN->right!=NULL)
			enq(q,CWN->right);
		CWN=q[qf++];
		i++;
	}
}
int main()
{
	int ch,n,key;
	NODE *root,*temp;
	root=NULL;
	for(;;)
	{
		printf("Menu\n");
		printf("0. Exit\n1. Insert nodes\n2. Search\n3. InOrder Display\n4. Delete a node\n5. Calculate height of tree\n6. Find minimun value\n7. Find maximum value\n8. Find the ancestors\n9. DFS Traversal\n10. BFS Traversal\n");
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
			case 8: printf("Enter key to search\n");
				scanf("%d",&key);
				temp=ancestor(root,key);
				break;
			case 0: printf("Thank you\n");
				exit(0);
			case 9: printf("DFS traversal\n");
				makevisitedzero(root);
				DFS(root);
				break;
			case 10: printf("BFS traversal\n");
				makevisitedzero(root);
				BFS(root);
				break;
			default: printf("Invalid Input\nPlease try again\n");
		}
	}
	return 0;
}
