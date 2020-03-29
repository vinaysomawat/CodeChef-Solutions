/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link:https://www.codechef.com/COOK116B/problems/MYSARA
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

void solve()
{
    ll n,temp;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    ll ans=1;
    for(int i=0;i<n-1;i++)
    {
        if((v[i]&v[i+1])==v[i])
        {
            ll k =v[i];
            int p=0;
            while(k>0)
            {
                if(k%2==1)
                {
                    p++;
                }
                k/=2;
            }
            ans*=pow(2,p);
            ans = ans%mod;
            p=0;
        }
        else 
        {
            ans=0;
            break;
        }
    }
    cout<<ans%mod<<endl;
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