/*
HeapSort using MaxHeap heapification and maximum (root node) deletion
Complexity - O(nlogn)
*/


#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void heapify(int arr[], int n, int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
	largest=l;
	if(r<n && arr[r]>arr[largest])
	largest=r;
	if(largest!=i)
	{
		swap(&arr[largest],&arr[i]);
		heapify(arr,n,largest);
	}
}
void heapsort(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	heapify(arr,n,i);
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

void printArray(int arr[], int n)
{ 
    int i;
    for (i=0; i<n;i++)
        printf("%d",arr[i]);
    printf("\n");
}

int main()
{
    int arr[]={4,2,5,7,2,5,4,34,45,32,65,43,76,34,57};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
    int ch;
    printf("Number of heapifications: %d\n",count);
}
