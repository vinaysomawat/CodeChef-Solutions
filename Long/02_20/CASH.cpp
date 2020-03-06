/* Problem link: https://www.codechef.com/FEB20B/problems/CASH
    Author: Vinay Somawat
    Webpage: http://vinaysomawat.github.io/
    Contest: CodeChef February 2020 Long challange
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