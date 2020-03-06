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
		ll k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		if(k<n*6)
		{
			for(int i=0;i<k;i++)
			{
		    	int x = arr[i%n];
		    	int y = arr[(n-1-(i%n))];
				arr[i%n] = x^y;
			}
		}
		else
		{
			if(k>n*6)
			{
				for(int i=0; i < ((k%(n*3))+n*3);i++)
				{
					int x = arr[i%n];
		    	int y = arr[(n-1-(i%n))];
				arr[i%n] = x^y;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}