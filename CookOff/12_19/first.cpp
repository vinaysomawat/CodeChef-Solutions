#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,t;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			v.push_back(t);
		}
		sort(v.begin(),v.end());
		int k=v[0];
		// cout<<"k: "<<k<<endl;
		int cnt=0;
		for(int i=0;i<n-1;i++)
		{
			if(v[i]!=v[i+1])
			{
				// cout<<v[i]<<" "<<v[i+1]<<endl;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}