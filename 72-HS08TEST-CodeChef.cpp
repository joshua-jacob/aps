// https://www.codechef.com/problems/HS08TEST

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	float y;
	cin>>x>>y;
	if(x%5==0 && x+0.5<=y)
		printf("%.2f\n",y-x-0.5);
	else
		printf("%.2f\n",y);
	return 0;
}
