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

void insertionSort(int *a, int n)
{
	printf("Performing insertion sort..\n");
	int i,j,key,count=0;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>-1 && a[j]>key)
		{
			count++;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
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
  insertionSort(a,n);
  cout<<"After sort\n";
  display(a,n);
  return 0;
}
