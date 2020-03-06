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

ll maxOR(ll L, ll R) 
{ 
    if (L == R) 
        return L; 
  
    else if ((R - L) == 1) 
        return (R | L); 
    else { 
        if (((R - 1) | R) > ((R - 2) | (R - 1))) 
            return ((R - 1) | R); 
        else
            return ((R - 2) | (R - 1)); 
    }
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		//cout<<maxOR(l,r)<<endl;
		cout<<((r-1)|r)<<endl;
	}
	return 0;
}