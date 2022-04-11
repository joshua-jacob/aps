// https://www.codechef.com/problems/CNOTE

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y,k,n;
        cin>>x>>y>>k>>n;
        bool flag=false;
        for(ll i=0;i<n;i++)
        {
            ll p,c;
            cin>>p>>c;
            if(c<=k && (p+y)>=x)
                flag=true;
        }
        if(flag)
            cout<<"LuckyChef\n";
        else
            cout<<"UnluckyChef\n";
    }
    return 0;
}
