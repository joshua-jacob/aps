#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll lookUp[100][100];

void build(ll n, ll arr[])
{
    for(ll j=0;j<n;j++)
        lookUp[j][0]=j;
    for(ll j=1;(1<<j)<n;j++)
    {
        for(ll i=0;(i+(1<<j)-1)<n;i++)
        {
            if(arr[lookUp[i][j-1]]<arr[lookUp[i+(1<<(j-1))][j-1]])
                lookUp[i][j]=lookUp[i][j-1];
            else
                lookUp[i][j]=lookUp[i+(1<<(j-1))][j-1];
        }
    }
}

ll query(ll n, ll arr[], ll L, ll R)
{
    ll j = (ll)log2(R-L+1);
    if(arr[lookUp[L][j]]<=arr[lookUp[R-(1<<j)+1][j]])
        return lookUp[R-(1<<j)+1][j];
    else
        return lookUp[L][j];
}

int main(int argc, char const *argv[])
{
    ll n=9;
    ll arr[] = {7,2,3,0,5,10,3,12,18};
    build(n,arr);
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;(1<<j)<n;j++)
            cout<<lookUp[i][j]<<' ';
        cout<<endl;
    }
    cout<<"1 5 "<<query(n,arr,1,5)<<endl;
    cout<<"3 3 "<<query(n,arr,3,3)<<endl;
    cout<<"4 9 "<<query(n,arr,4,9)<<endl;
    cout<<"1 9 "<<query(n,arr,1,9)<<endl;
    return 0;
}
