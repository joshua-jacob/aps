/*Write a function called create_node which creates a node dynamically and returns a pointer to the calling function.
This function also accepts the data of a student like name,usn,marks.
Write a main program wherein you ask user whether the student is a regular student or a lateral entry or change of branch.
In case of regular student, ask user total class strength and allocate the memory once for all.
In other cases, then allocate only one memory every time he requests.
Write a function to display the student details.*/

#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[10];
    int usn;
    float cgpa;
};
struct NODE
{
    struct student data;
    struct NODE *next;
}*tail,*head;
struct NODE* getnode();
void getdetails(struct NODE*);
void insert_head();
void insert_tail();
void insert_between();
void delete_begin();
void delete_end();
void delete_at();
void reverse();
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
    return p;
}
void getdetails(struct NODE *head)
{
	if(head==NULL)
	printf("No student found\nPlease try again\n");
	else
	{
    	struct NODE *p;
    	p=head;
    	printf("----------------------------------------------\n");
    	printf("Student details:\n");
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
		tail=p;
	}
	return;
}
void insert_between()
{
	int key;
	struct NODE *p,*temp;
	p=getnode();
	printf("Enter key USN\n");
	scanf("%d",&key);
	temp=head;
	while(temp!=NULL)
	{
		if(temp->next->data.usn==key)
		{
			p->next=temp->next;
			temp->next=p;
			printf("Data inserted\n");
			return;
		}
		else
		temp=temp->next;
	}
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
		free(temp);
		printf("1 Node deleted at the beginning\n");
	}
}
void delete_end()
{
	struct NODE *temp;
	if(head==NULL||tail==NULL)
		printf("No nodes to delete\n");
	else if(tail==head)
	{
		delete_begin();
		return;
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		temp=temp->next;
		tail=temp;
		temp=temp->next;
		tail->next=NULL;
		free(temp);
		printf("1 Node deleted at the end\n");
	}
}
void delete_at()
{
	struct NODE *temp,*p;
	temp=head;
	int key;
	printf("Enter Key USN to delete: ");
	scanf("%d",&key);
	if(head->data.usn==key)
	{	
		delete_begin();
		return;
	}
	else if(tail->data.usn==key)
	{
		delete_end();
		return;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			if(temp->next->data.usn==key)
			{
				p=temp->next;
				temp->next=temp->next->next;
				p->next=NULL;
				free(p);
				printf("1 Node deleted\n");
				return;
			}
			else
			temp=temp->next;
		}
		printf("Key element not found in list\n");
	}
}
void reverse()
{
	if(head==NULL||tail==NULL)
		printf("No nodes available\n");
	else
	{
		struct NODE *temp,*ttail;
		ttail=tail;
		while(ttail!=head)
		{
			temp=head;
			while(temp->next!=ttail)
			{
				temp=temp->next;
			}
			ttail->next=temp;
			ttail=temp;
			ttail->next=NULL;
		}
		printf("List reversed\n");
		head=tail;
		tail=ttail;
		temp=NULL;
		ttail=NULL;
		return;
	}
}
int main()
{
    struct NODE *p;
    int ch=0;
    head=NULL;
    while(ch!=9)
    {
    printf("Enter choice:\n1. Insert data in beginning\n2. Insert data in the end\n3. Insert data in between\n4. Display\n5. Delete from beginning\n6. Delete from the end\n7. Delete in between\n8. Reverse the list\n9. Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    	insert_head();
        break;
    case 2:
    	insert_tail();
		break;
    case 3:
        insert_between();
		break;
	case 4:
		getdetails(head);
		break;
	case 5:
		delete_begin();
		break;
	case 6:
		delete_end();
		break;
	case 7:
		delete_at();
		break;
	case 8:
		reverse();
		break;
	case 9:
		printf("Thank you\n");
		exit(0);
    default:   
        printf("Invalid input\nPlease try again\n");
    }}
    return 0;
}
