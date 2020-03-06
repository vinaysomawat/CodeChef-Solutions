#include<bits/stdc++.h>
using namespace std;

long long int countpair(int n)
{
	long long int sum=0;
	while(n>0)
	{
		sum += n-1;
		n--;
	}
	return sum;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,t;
		cin>>n;
		unordered_map<int, int>umap;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			umap[t]++;
		}
		int count_two=0, count_zero=0;
		count_two = umap[2];
		count_zero = umap[0];
		
		if(count_two==1)
		{
			count_two = 0;
		}
		if(count_zero==1)
		{
			count_zero = 0;
		}
		long long totalpair = 0;
		totalpair= countpair(count_two) + countpair(count_zero);
		cout<<totalpair<<endl;
	}
	return 0;
}