// Vinay Somawat NIT Warangal
// webpage: https://vinaysomawat.github.io/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int n,m;
vector<vector<int>>a;

int count(int i, int j)
{
	int l=0;
	while(1)
	{
		if(j-(l+1)<0 || j+(l+1)>=m || i-(l+1)<0 || i+(l+1)>=n)
		{
			break;
		}
		if(a[i][j-(l+1)]!=a[i][j+(l+1)] || a[i-(l+1)][j]!=a[i+(l+1)][j])
		{
			break;
		}
		++l;
	}
	return l+1;
}

void solve()
{
	cin>>n>>m;
	a = vector<vector<int>>(n, vector<int>(m));
	int ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans+=count(i,j);
		}
	}
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}