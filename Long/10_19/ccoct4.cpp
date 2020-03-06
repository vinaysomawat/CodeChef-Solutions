#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &a[i]);
		}
		int max=0;
		for(int i=n;i>0;i--)
		{
			int count=0;
			for(int j=i-1;j>0;j--)
			{
				if(a[j]%a[i]==0)
				{
					count++;
				}
			}
			if(max<count)
			{
				max=count;
			}
		}
		cout<<max<<endl;
	}
}