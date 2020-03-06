#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int cnt=0;
		string s1="101";
		for(int i=0;i<str.length();i++)
		{
			string s = str.substr(i,3);
			if(s==s1)
			{
				cnt+=1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}