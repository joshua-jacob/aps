/*
Prim's algorithm for Minimal Spanning Tree
The Graph is represented as an Adjacency Matrix
*/

#include<stdio.h>
#include<stdlib.h>
#define infinity 9999
#define max 20
int G[max][max],spanning[max][max],n;
int prim()
{
	int cost[max][max];
	int i,j,no_of_edges,min_cost,u,v,min_dist,dist[max],from[max],visited[max];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=infinity;
			else
				cost[i][j]=G[i][j];
			spanning[i][j]=0;
		}
	}
	dist[0]=0;
	visited[0]=1;
	for(i=1;i<n;i++)
	{
		dist[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	min_cost=0;
	no_of_edges=n-1;
	while(no_of_edges>0)
	{
		min_dist=infinity;
		for(i=1;i<n;i++)
		{
			if(visited[i]==0 && dist[i]<min_dist)
			{
				v=i;
				min_dist=dist[i];
			}
		}
		u=from[v];
		spanning[u][v]=dist[v];
		spanning[v][u]=dist[v];
		visited[v]=1;
		for(i=1;i<n;i++)
		{
			if(visited[i]==0 && cost[i][v]<dist[i])
			{
				dist[i]=cost[i][v];
				from[i]=v;
			}
		}
		min_cost=min_cost+cost[u][v];
		no_of_edges--;
	}
	return min_cost;
}
int main()
{
	int i,j,total_cost=0;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	total_cost=prim();
	printf("Minimum spanning tree\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",spanning[i][j]);
		printf("\n");
	}
	printf("Total cost of minimal spanning tree= %d\n",total_cost);
	printf("Minimum number of messages to be sent = %d\n",(2*n)-2);
	int temp=infinity;
	for(i=0;i<n;i++)
		if(spanning[n-1][i]!=0 && spanning[n-1][i]<temp)
		temp=spanning[n-1][i];
	printf("Total cost to send out all messages = %d\n",(2*total_cost)-temp);
	return 0;
}
