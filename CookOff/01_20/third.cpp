//Vinay Somawat
//vinaysomawat40@gmail.com

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll ans(ll a, ll b){ 
while(a < b){ 
    b -= (b & -b)%1000000007; 
} 
return b; 
} 

ll ansall(ll a, ll b)
{
    ll arr[b];
    arr[a] = a;
    ll final= a;
    for(ll i=a+1;i<=b;i++)
    {
        //cout<<"before: "<<i<<" "<<arr[i-1]<<endl;
        arr[i] = ans(arr[i-1],i);
        //cout<<"after: "<<i<<" "<<arr[i]<<endl;
        final +=arr[i];
        //cout<<arr[i]<<" "<<i<<" "<<ans(a,i)<<endl;
    }
    return final;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout << ansall(l, r)<<endl; 
    }
    return 0;
}