// https://www.codechef.com/problems/CLEANUP 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		vector<int> chf,as,inp;
		int m,n,tmp,count=0,flag=0;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>tmp;
			inp.push_back(tmp);
		}
		sort(inp.begin(),inp.end());
		for(int i=0;i<n;i++)
		{
//			cout<<"inp "<<inp[count]<<" i "<<i<<endl;
			if(count<m && inp[count]==i+1)
			{
				count++;
				continue;
			}
			else 
			{
				flag++;
				if(flag%2==1)
					chf.push_back(i+1);
				else
					as.push_back(i+1);
			}
		}
		for(auto i : chf)
		cout<<i<<' ';
		cout<<endl;
		for(auto i : as)
		cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}
