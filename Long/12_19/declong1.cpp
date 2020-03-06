#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		unordered_map<int, int> umap;
		for(int i=0;i<n;i++)
		{
			int p,q;
			cin>>p>>q;
			if(umap.find(p)==umap.end())
			{
				umap.insert(make_pair(p,q));
			}
			else
			{
				if(umap[p]<q)
				{
					umap[p] = q;
				}
			}
		}
		int sum=0;
		for(auto it=umap.begin(); it!=umap.end(); it++)
		{
			if(it->first >= 1 && it->first <=8 )
			{
				sum +=it->second;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}