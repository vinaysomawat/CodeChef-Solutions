/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int function1(int a, int b, ll c) 
{ 
	static int t[] = { 0, 3, 2, 5, 0, 3, 
					5, 1, 4, 6, 2, 4 }; 
	c -= b < 3; 
	return ( c + c / 4 - c / 100 + 
			c / 400 + t[b - 1] + a) % 7; 
} 

void solve()
{
    ll x,y,q,r;
    cin>>x>>q>>y>>r;
    if(x>2)
    {
        q = q+1;
    }
    if(y<2)
    {
        r = r-1;
    }
    ll ans=0;
    ans = ((r - q)/400)*101;
    q  = q+(((r-q)/400)*400);
    for(ll j=q;j<=r;j++)
    {
	    int c=0;
        int temp = function1(1, 2, j);
        if(((j% 4 == 0) && (j% 100 != 0)) || (j% 400 == 0))
        {
            c=1;
        }
	    if(temp == 6)
	    {
            ans++;
        }
	    else if(temp==0 && c!=1) 
	    {
            ans++;
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