//Vinay Somawat
//vinaysomawat40@gmail.com

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int check(ll a, ll b)
{
    int cnt=0;
    if(b<a)
    {
        swap(a,b);
    }
    for(ll i=1; i<b;i++)
    {
        if(b%i==a%i)
        {
            cnt++;
            cout<<i<<endl;
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<check(a-1,b-1)<<endl;
    }
    return 0;
}