#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5
struct stack
{
	int top;
	int data[STACKSIZE];
}s;
typedef struct stack STACK;
void Push(int x);
int Pop();
void Push(int x)
{
	s.top++;
	s.data[s.top]=x;
	printf("Push operation completed successfully\n");
}
int Pop()
{
	int x;
	x=s.data[s.top];
	s.top--;
	return x;
}
int main()
{
	s.top=-1;
	int i,x;
	for(;;)
    {
        printf("1 for Push\n2 for Pop\n3 for display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to Push into stack\n");
            	scanf("%d",&x);
            	Push(x);
                break;
            case 2:x=Pop();
            printf("Popped element is %d",x);
                    break;
            case 3:display();
            		break;
            default: return 0;
        }
    }
	printf("The topmost element is %d\n",Peek());
	return 0;
}
