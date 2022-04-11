// https://www.codechef.com/problems/HORSES

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,tmp,dif=10000000000;
	    std::vector<int> v;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>tmp;
	        v.push_back(tmp);
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(v[i]>v[j])
	            {
	                if((v[i]-v[j])<dif)
	                    dif=v[i]-v[j];
	            }
	            else
	                if((v[j]-v[i])<dif)
	                    dif=v[j]-v[i];
	        }
	    }
	    std::cout << dif << std::endl;
	}
	return 0;
}
