#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<4 && n%4!=0)
        {
            cout<<"-1"<<endl;
            break;
        }
        else
        {
            int A[n];
            for(int i=1;i<=n;i++)
            {
                cin>>A[i];
            }
            sort(A, A+n+1);
            //cout<<A[n]<<endl;
            int gap = n/4;
            int x=A[(2*gap)];
            int y=A[(3*gap)];
            int z=A[(4*gap)];
            if(x==y || y==z || z==x || x==A[1])
            {
                cout<<"-1"<<endl;
            }
            else
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
        
        
    }
    return 0;
}