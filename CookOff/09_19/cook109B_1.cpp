#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        int a[n],b[q];
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<q;i++)
        {
            cin>>b[i];
        }
        int k=0,m=0,count=0;
        while(k<n && m<q)
        {
            if(b[m]>a[k])
            {
                //cout<<"chota hai"<<endl;
                b[m] = 2*(b[m]-a[k]);
                k++;
                count++;
            }
            else
            {
                cout<<"bada hai"<<endl;
                m++;
                k=0;
                cout<<"count: "<<count<<endl;
            }
        }
    };
    return 0;
}