// https://www.codechef.com/problems/LAPIN

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int len,flag=0;
		vector<int> count1(26,0),count2(26,0);
		string s,s1,s2;
		cin>>s;
		len=s.length();
		s1=s.substr(0,len/2);
		if(len%2==0)
			s2=s.substr(len/2);
		else
			s2=s.substr(len/2+1);
		for(int i=0;i<len/2;i++)
		{
			count1[s1[i]-'a']++;
			count2[s2[i]-'a']++;
		}
		for(int i=0;i<26;i++)
		{
			if(count1[i]==count2[i])
				continue;
			flag=1;
			break;
		}
		if(flag)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
