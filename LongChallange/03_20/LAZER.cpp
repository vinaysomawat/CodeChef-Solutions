/* 
    Contest: CodeChef March 2020 Long challange
    Problem link:https://www.codechef.com/MARCH20B/problems/LAZER
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long int
#define pdd pair<double, double> 
using namespace std;

  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int x1,x2;
        ll y;
        for(int i=0;i<q;i++)
        {
            cin>>x1>>x2>>y;
            x1--;
            x2--;
            int counter=0;
            for(int j=x1;j<x2;j++)
            {
                if(y>a[j] && (a[j+1]>y||a[j+1]==y))
                {
                    counter++;
                }
                else if(y<a[j]&& (a[j+1]<y||a[j+1]==y))
                {
                    counter++;
                }
                else if(y==a[j])
                {
                    if(a[j+1]>y|| a[j+1]<y)
                    {
                        counter++;
                    }
                    else if(a[j+1]==y)
                    {
                        counter+=2;
                    }
                }
            }
            cout<<counter<<endl;
        }
    }
    return 0;
}

