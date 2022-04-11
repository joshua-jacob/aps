// https://www.codechef.com/problems/FCTRL
// Find number of leading zeros in a factorial of a number

#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int ans,t,n;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		while(n>0)
		{
			ans+=n/5;
			n=n/5;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
