// https://www.codechef.com/FEB20B/problems/NOCHANGE

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        vector<ll> d(n);
        for(ll i=0;i<n;i++)
            cin>>d[i];
        bool isFactor=true;
        ll index=-1;
        if(n==1)
        {
            if(p%d[0]==0)
                cout<<"NO\n";
            else
                cout<<"YES "<<p/d[0]+1<<'\n';
        }
        else
        {
        for(ll i=n-1;i>0;i--)
        {
            if(p%d[i]==0)
                continue;
            else
            {
                index=i;
                isFactor=false;
                break;
            }
        }
        if(isFactor)
        {
            bool found=false;
            ll i1=-1,i2=-1;
            for(ll i=0;i<n;i++)
            {
                for(ll j=i+1;j<n;j++)
                {
                    ll gcd=__gcd(d[i],d[j]);
                    if(gcd==d[i]||gcd==d[j])
                        continue;
                    else
                    {
                        i1=i;
                        i2=j;
                        found=true;
                        break;
                    }
                }
            }
            if(found)
            {
                vector<ll> ans(n,0);
                ans[i2]=p/d[i2]-1;
                ans[i1]=d[i2]/d[i1]+1;
                cout<<"YES ";
                for(auto c:ans)
                    cout<<c<<" ";
                cout<<'\n';
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else
        {
            vector<ll> ans(n,0);
            ans[index]=(p/d[index]) + 1;
            cout<<"YES ";
                for(auto c:ans)
                    cout<<c<<" ";
                cout<<'\n';
        }
        }
    }
    return 0;
}
