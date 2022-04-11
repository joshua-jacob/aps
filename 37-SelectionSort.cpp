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

void selectionSort(int *a, int n)
{
	int i,j,min,count=0;
	printf("Performing selection sort..\n");
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			count++;	
			if(a[j]<a[min])
				min=j;
		}
		swap(&a[min],&a[i]);
	}
	printf("Selection sort complete.\nNo of comparisons=%d\n",count);
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
  selectionSort(a,n);
  cout<<"After sort\n";
  display(a,n);
  return 0;
}
