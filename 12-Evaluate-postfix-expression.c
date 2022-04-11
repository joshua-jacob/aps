#define SIZE 50
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct stack
{
	int s[SIZE];
	int top;
}st;
void Push(int elem)
{
	st.top++;
	st.s[st.top]=elem;
}
int Pop()
{
	return st.s[st.top--];
}
void display()
{
	printf("Printing Stack\n");
	for(int i=st.top;i>=0;i--)
	printf("|%d|\ttop=%d\n",st.s[i],st.top);
	printf("\n");
}
int main()
{
	st.top=-1;
	char temp[50],postfix[50],ch;
	int i=0,k=0,temp1,temp2,res;
	printf("Enter a postfix expression\n");
	scanf("%s",postfix);
	ch=postfix[0];
	while(ch!='\0')
	{
		display();
		ch=postfix[i];
		if(isalnum(ch))
			Push(atoi(&ch));
		else
		{
			if(st.top==0)
			break;
			temp1=Pop();
			temp2=Pop();
			printf("temp1 = %d\ntemp2 = %d\n",temp1,temp2);
			switch(ch)
			{
				case '+': Push(temp1+temp2);
					break;
				case '-': Push(temp2-temp1);
					break;
				case '*': Push(temp1*temp2);
					break;
				case '/': Push(temp2/temp1);
					break;
			}
		}
		i++;
	}
	printf("Postfix entered: %s\n",postfix);
	display();
	if(st.top==0)
	{
		printf("Only 1 remaining\n");
		res = Pop();
	}
	printf("Value = %d\n",res);
}
