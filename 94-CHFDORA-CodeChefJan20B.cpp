// https://www.codechef.com/JAN20B/problems/CHFDORA

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    ll a[n][m];
	    for(ll i=0;i<n;i++)
	    {
	        for(ll j=0;j<m;j++)
	        cin>>a[i][j];
	    }
	    ll ans=m*n;
	    for(ll i=1;i<n-1;i++)
	    {
	        for(ll j=1;j<m-1;j++)
	        {
	            ll k=1;
	            //cout<<i<<' '<<j<<' '<<endl;
	            while(a[i][j+k]==a[i][j-k] && a[i-k][j]==a[i+k][j])
	            {
	                ans++;
	                //cout<<k<<' '<<ans<<endl;
	                k++;
	                if((i-k)<0 || (i+k)>=n || (j-k)<0 || (j+k)>=m)
	                    break;
	            }
	        }
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}
