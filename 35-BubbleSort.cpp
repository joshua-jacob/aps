#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void display(int *a, int n)
{
	printf("Displaying..\n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
}

void bubbleSort(int *a, int n)
{
	int i,j,temp;
	printf("Performing bubble sort..\n");
	for(i=0;i<n-2;i++)
		for(j=0;j<n-i-1;j++)
		{	
			count++;
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
}

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<"Before sort\n";
  display(a,n);
  bubbleSort(a,n);
  cout<<"After sort\n";
  display(a,n);
  return 0;
}
