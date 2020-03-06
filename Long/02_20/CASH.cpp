/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll temp,sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        sum +=temp%k;
    }
    sum = sum%k;
    cout<<sum<<endl;
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