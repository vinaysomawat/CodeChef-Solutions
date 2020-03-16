//vinaysomawat40@gmail.com NIT WARANGAL

#include<bits/stdc++.h>
using namespace std;


void removeodd(int a[],int& number)
{
	int k=0;
	for(int i=1;i<number;i=i+2)
	{
		a[k] = a[i];
		k++;
	}
    number = number - k;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[100001];
		a[0]=0;
		a[1]=1;
		for(int i=2;i<n;i++)
		{
			a[i] = a[i-1] + a[i-2];
			a[i] = a[i]%10;
		}

		int x=n,p=0;
		while(x!=1)
		{
			x = x/2;
			p++;
		}
		while(p--)
		{
			removeodd(a,n);
		}
		cout<<a[0]<<endl;
	}
	return 0;
}