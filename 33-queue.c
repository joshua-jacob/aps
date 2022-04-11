/*Queue is a data structure which has two ends called 'front' and 'rear. The element in the queue can enter through the rear end will be deleted from the front end. The process of inserting a value is called 'enqueue' and the process of deleting a value is called 'dequeue'.*/
#include <stdio.h>
#include <stdlib.h>
int f=0;
int r=-1;
int count=0;
int q[5];
int size=4;
void enqueue()
{
    if(count==(size+1))
    {
        printf("Queue full\n");
    }
    else{
        if(r==size && count<=size)
        {
            r=r%size;
            count++;
            printf("Enter data\n");
            scanf("%d",&q[r]);
        }
        else
        {
            r++;
            count++;
            printf("Enter data\n");
            scanf("%d",&q[r]);
        }
    }
}
void dequeue()
{
    if(count==0)
    {
        printf("Queue empty\n");
    }
    else{
        if(f==size && count<=size)
        {
            printf("data dequeued is %d\n",q[f]);
            f=f%size;
            count--;
        }
        else
        {
            printf("data dequeued is %d\n",q[f]);
            f++;
            count--;
        }
    }

}
void display()
{
	if(count==0)
	{
		printf("Queue is empty\n");
		return;
	}
	int i;
	for(i=f;i<=r;i++)
	{
		printf("%d\n",q[i]);
	}
}
int main()
{
    int ch;
    int i;
    for(;;)
    {
        printf("1 for enqueue\n2 for dequeue\n3 for display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
            		break;
            default: return 0;
        }
    }
}
