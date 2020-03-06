/* Problem link: https://www.codechef.com/JAN20B/problems/DYNAMO
    Author: Vinay Somawat
    Webpage: http://vinaysomawat.github.io/
    Contest: CodeChef January 2020 Long challange
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,a,s,b,c,d,e;
		cin>>n;
		cin>>a;
		ll res=1;
		for(ll i=1;i<=n;i++)
		{
			res*=10;
		}
		//cout<<"res: "<<res<<endl;
		s=a+2*res;
		cout<<s<<endl;
		//fflush(stdout);
		cin>>b;
		c =res-1-b;
		cout<<c<<endl;
		//fflush(stdout);
		cin>>d;
		e =res-d;
		cout<<e<<endl;
		//fflush(stdout);
		int p;
		cin>>p;
		if(p==-1)
		{
			break;
		}
	}
	return 0;
}