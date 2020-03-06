//vinaysomawat40@gmail.com
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,m,k,l,r;
    cin>>n>>m>>k>>l>>r;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
   /* for(int i=0;i<n;i++)
    {
        cout<<"a[i]: "<<a[i]<<"b[i]: "<<b[i]<<endl;
    }*/ 
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        int p = a[i];
       /*  cout<<"p before: "<<p<<endl;
        cout<<"l: "<<l<<"r: "<<r<<endl; */
        if(p<k-1)
        {   
           // cout<<"inrement\n";
            p = p + m;
        }
        else if(p>k+1)
        {
            //cout<<"decrement\n";
            p = p - m;
        }
        else 
        {
            continue;
        }
       // cout<<"p after: "<<p<<endl;
        if(p>=l && p<=r)
        {
            cout<<a[i]<<endl;
            flag=true;
            break;
        }
    }
    if(flag==false)
    {
        cout<<"-1"<<endl;
    }
    }
}