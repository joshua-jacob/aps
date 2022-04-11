// https://www.codechef.com/problems/LEPERMUT

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,c1=0,c2=0;
		cin>>n;
		vector<ll> a(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		for(ll i=0;i<n;i++)
			for(ll j=i+1;j<n;j++)
				if(a[i]>a[j])
					c1++;
		for(ll i=0;i<(n-1);i++)
			if(a[i]>a[i+1])
				c2++;
		if(c1==c2)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
