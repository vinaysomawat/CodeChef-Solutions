//vinaysomawat40@gmail.com


#include<bits/stdc++.h>
#define MOD 1000000007
#define INFI 1e15
#define INFIM 1e18
#define ll unsigned long long
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define pb push_back
#define f(t) for(int i=0;i<t;i++)
#define fi first
#define se second
#define all(t) t.begin(),t.end()
#define ci(t) cin>>t
#define co(t) cout<<t
#define mii map<int,int>
#define pii pair<int,int>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll p=n;
		bool flag=false;
		int count=0;
		while(n%10==0)
		{
			n = n/10;
			count++;
		}
		//cout<<count<<endl;
		ll a[100001];
		for(int i=0;i<count;i++)
		{
			a[i] = pow(2,i);
		}
		if(p>10 && p!=40 && p!=80 && p!=800)
		{
			for(int i=0;i<101;i++)
			{
				//cout<<"a[i]: "<<a[i]<<endl;
				if(n==a[i])
				{
					flag = true;
					break;
				}
			}
		}
		if(flag==true)
		{
			cout<<"Yes"<<endl;
		}
		else 
			cout<<"No"<<endl;
	}
	return 0;
}