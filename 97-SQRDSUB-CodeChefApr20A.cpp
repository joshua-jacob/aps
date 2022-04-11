// https://www.codechef.com/APRIL20A/problems/SQRDSUB/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isInvalid(ll n)
{
    if(!(n%2==0 && n%4!=0))
        return false;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, prev1 = 0, prev2 = 0;
        bool flag = false;
        cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
            cin>>a[i];
        ll max = n*(n+1)/2, invalidCount = 0, prevCount = 0;
        for(ll i=0;i<n;i++)
        {
            invalidCount=0;
            if(isInvalid(a[i]))
            {
                invalidCount=1;
            }
            if(a[i]==1)
            {
                prev1++;
                invalidCount += prevCount;
            }
            else
            {
                if(a[i]%2==0)
                {
                    if(a[i]%4==0)
                        flag = false;
                    else
                    {
                        flag = true;
                        invalidCount += prev1;
                    }
                    prev2 = prev1;
                    prev1 = 0;
                }
                else
                {
                    if(flag)
                    {
                        invalidCount += prev2;
                        invalidCount++;
                    }
                    prev1++;
                }
            }
            max -= invalidCount;
            prevCount = invalidCount;
        }
        cout<<max<<'\n';
    }
    return 0;
}
