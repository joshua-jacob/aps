/*
Binary Indexed Tree/Fenwick Tree
Range Sum Query and Update
Better than Segment Tree in almost every case
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll BIT[1000];

void update(ll n, ll index, ll val)
{
    // cout<<"starting index "<<index<<endl;
    for(; index <= n; index += (index&-index))
    {
        // cout<<"updating "<<index<<endl;
        BIT[index] += val;
    }
}

ll query(ll index)
{
    ll sum = 0;
    for(; index > 0; index -= (index&-index))
    {
        // cout<<"query "<<index<<endl;
        sum += BIT[index];
    }
    return sum;
}

ll queryBIT(ll left, ll right)
{
    return query(right)-query(left-1);
}

int main(int argc, char const *argv[])
{
    ll n,q;
    cin >> n >> q;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        update(n, i+1, a[i]);
    }
    // for(ll i=0;i<20;i++)
    //     cout<<BIT[i]<<' ';
    // cout<<endl;
    for(ll i=0; i<q; i++)
    {
        ll l, r;
        cin >> l >> r;
        cout << queryBIT(l, r)<< '\n';
    }
    return 0;
}
