//vinaysomawat40@gmail.com


#include<bits/stdc++.h>
#define MOD 1000000007
#define INFI 1e15
#define INFIM 1e18
#define ll long long int
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool flag=true;
		int max = *max_element(a,a+n);
		int min = *min_element(a,a+n);

		for(int i=0;i<n;i++)
		{
			if(a[i]==max)
			{
				flag=true;
				break;
			}
			else if(a[i]==min)
			{
				flag = false;
				break;
			}
		}
		sort(a,a+n);
		if(flag==false)
		{
			cout<<a[0]<<" "<<a[n-1]<<endl;
		}
		else 
		{
			cout<<a[n-1]<<" "<<a[0]<<endl;
		}
		
	}
	return 0;
}