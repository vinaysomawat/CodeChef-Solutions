#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int b[n*k+1];
        for(int i=0;i<n*k;i++)
        {
            b[i] = a[i%n];
        }
        long long count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n*k;j++)
            {
                if(b[i]>b[j])
                {
                    //cout<<i<<" "<<j<<" "<<b[i]<<" "<<b[j]<<endl;
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}