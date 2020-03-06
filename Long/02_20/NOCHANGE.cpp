/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
ll finalsum;
ll k,ptr;
ll n,p=0,p1=1;
cin>>n>>finalsum;
ll a[n];
for(int j=0;j<n;j++)
{
cin>>a[j];
if(finalsum%a[j]!=0)
{ptr=j;
p=1;
}
}
ll vect[n+1] ={0};
if(p==1)
{
vect[ptr] = (finalsum/a[ptr])+1;	
p1=0;
}
else
{
for(int j=n-1;j>=0;j--)
{
if(finalsum%a[j]==0)
{
k = finalsum/a[j];
finalsum = finalsum -a[j]*(k-1);
vect[j] = k-1; 
}
else if(finalsum%a[j]!=0)
{
k=finalsum/a[j];
p1=0;
vect[j] = k+1;
break; }
}}

if(p1==0)
{cout<<"YES ";
for(int j=0;j<n;j++)
{cout<<vect[j]<<" ";}
cout<<endl;
}
else if(p1==1)
{
cout<<"NO"<<endl;
}

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