/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<ll> v1;
    vector<ll> v2;
    ll temp;
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        v1.push_back(temp);
    }
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        v2.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll sum=0;
    for(int i=0;i<n;++i)
    {
        sum+= min(v1[i], v2[i]);
    }
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