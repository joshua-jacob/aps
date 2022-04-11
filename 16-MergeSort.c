#include<stdio.h>
#include<stdlib.h>



void merge(int arr[],int l, int m, int r)
{
	int n1,n2,i,j,k;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	L[i]=arr[l+i];
	for(j=0;j<n2;j++)
	R[j]=arr[j+m+1];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

void printArray(int arr[], int n)
{ 
    int i;
    for (i=0; i<n;i++)
        printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int arr[]={4,2,5,7,2,5,4,34,45,32,65,43,76,34,57};
	printArray(arr,n);
	mergeSort(arr,0,14);
	printArray(arr,n);
}
