// Vinay Somawat NIT Warangal
// webpage: https://vinaysomawat.github.io/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int s;
		cin>>s;
		int w1,w2,w3;
		cin>>w1>>w2>>w3;
		int count=3;
		int f=0;
		if(s>=w1+w2)
		{
			count--;
			f=1;
			if(s>=w1+w2+w3)
			{
				count--;
			}
		}
		if(s>=w2+w3 && f==0)
		{
			count--;
		}
		cout<<count<<endl;
	}
	return 0;
}