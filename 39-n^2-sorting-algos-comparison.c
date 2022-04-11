#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int *a, int n)
{
	int i,j,temp,count=0;
	printf("Performing bubble sort..\n");
	for(i=0;i<n-2;i++)
		for(j=0;j<n-i-1;j++)
		{	
			count++;
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	printf("Bubble sort complete.\nNo of comparisons=%d\n",count);
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
	printf("Insertion sort complete.\nNo of shifts/comparisons=%d\n",count);
}
void display(int *a, int n)
{
	printf("Displaying..\n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
}
void heapify(int *a,int n)
{
	int l,r;
	for(int i=0;i<n;i++)
	{
		l=(2*i)+1;
		r=(2*i)+2;
		if(l<n && r<n)
		{
			if(a[l]>a[i] || a[r]>a[i])
			{
				if(a[l]>a[r])
				swap(&a[i],&a[l]);
				else
				swap(&a[i],&a[r]);
			}
		}
	}
}
void heapsort(int *a,int n)
{
	printf("Performing Heap Sort..\n");
	int i;
	for(i=0;i<n;i++)
	{
		heapify(a,n-i);
		swap(&a[0],&a[n-i-1]);
	}
	printf("Heap sort complete.\n");
}
int main()
{
	int n,i,ch;
	time_t t;
	srand((unsigned)time(&t));
	printf("Enter number of elements\n");
	scanf("%d",&n);
	int a[n],b[n];
	//printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{	
		a[i]=rand()%500;
		//scanf("%d",&a[i]);
		b[i]=a[i];
	}
	display(a,n);
	do
	{
		printf("1. Bubble sort\n2. selection sort\n3. insertion sort\n4. exit\n5. Display\n6. Restore array\n7. HeapSort\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
	 	switch(ch)
	 	{
	 		case 1: bubbleSort(a,n);
			break;
			case 2:	selectionSort(a,n);
			break;
			case 3:	insertionSort(a,n);
			break;
			case 4:
			printf("Terminating..\n");
			break;
			case 5:
			display(a,n);			
			break;
			case 6:
			for(i=0;i<n;i++)
			a[i]=b[i];
			printf("Array restored\n");
			break;
			case 7:
			heapsort(a,n);
			break;
			default: printf("Invalid input\nPlease try again\n");
		}
	}while(ch!=4);
}
