/*
Implementation of Doubly Linked List in C using Dynamic memory allocation.
*/

#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[20];
	int DOB;
	float cgpa;
};
struct NODE
{
	struct NODE *prev;
	struct student data;
	struct NODE *next;
}*head,*tail;
struct NODE* getnode();
void getdetails(struct NODE *head);
void insert_head();
void insert_tail();
void delete_begin();
struct NODE* getnode()
{
	struct NODE *p;
	p=malloc(sizeof(struct NODE));
	printf("Enter name\n");
    scanf("%s",p->data.name);
    printf("Enter USN\n");
    scanf("%d",&p->data.usn);
    printf("Enter CGPA\n");
    scanf("%f",&p->data.cgpa);
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void getdetails(struct NODE *head)
{
	if(head==NULL)
	printf("No data found\nPlease try again\n");
	else
	{
    	struct NODE *p;
    	p=head;
    	printf("----------------------------------------------\n");
    	printf("Details:\n");
    	while(p!=NULL)
    	{
        	printf("Name: %s\n",p->data.name);
        	printf("USN: %d\n",p->data.usn);
        	printf("CGPA: %f\n",p->data.cgpa);
        	p=p->next;
    	}
    }
}
void insert_head()
{
	struct NODE *p;
	p=getnode();
	if(head==NULL)
	{
		head=p;
		tail=p;
    }
    else
    {
        p->next=head;
        head->prev=p;
        head=p;
    }
	return;
}
void insert_tail()
{
	struct NODE *p;
	p=getnode();
	if(head==NULL)
	{
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
		p->next=NULL;
		p->prev=tail;
		tail=p;
	}
	return;
}
void delete_begin()
{
	struct NODE *temp;
	if(head==NULL)
		printf("No nodes to delete\n");
	else
	{
		temp=head;
		head=temp->next;
		temp->next=NULL;
		head->prev=NULL;
		free(temp);
		printf("1 Node deleted at the beginning\n");
	}
}
int main()
{
	int ch;
	do
	{
		printf("Enter choice\n1. Insert element at head\n2. Insert element at tail\n3. Delete element from head\n4. Display\n5. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_head();
				break;
			case 2: insert_tail();
				break;
			case 3: delete_begin();
				break;
			case 4: getdetails(head);
				break;
			case 5: printf("Thank you\n");
				exit(0);
			default: printf("Invalid input\nPlease try again\n");
		}
	}while(ch!=5);
	return 0;
}
