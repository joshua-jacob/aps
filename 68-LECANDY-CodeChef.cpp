// https://www.codechef.com/problems/LECANDY

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        ll sum=0,var;
        for(int i=0;i<n;i++)
        {
            cin>>var;
            sum+=var;
        }    
        if(sum<=c)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
