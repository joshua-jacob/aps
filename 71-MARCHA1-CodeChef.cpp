#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,sum,flag=0;
		cin>>n>>m;
		vector<ll> a(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		ll max=1<<n,bits,i,j;
		for(i=0;i<max;++i)
		{
			sum=0;
		    for (bits = i, j = 0; bits; bits >>= 1, ++j) 
		    {
    		    if (bits & 1)
    		        sum+=a[j];
    		}
			if(sum==m)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
