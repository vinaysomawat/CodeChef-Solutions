/* 
    Contest: CodeChef March 2020 Long challange
    Problem link: https://www.codechef.com/MARCH20B/problems/ENGXOR
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll a;
        ll o=0,e=0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            //method to count setbits
            ll t = __builtin_popcount(a);
            if(t%2==0)
                e++;
            else
                o++;
        }
        int p,x;
        for(int i=0;i<q;i++)
        {
            cin>>p;
            x=__builtin_popcount(p);
            if(x%2==0)
            {
                cout<<e<<" "<<o<<"\n";
            }
            else
            {
                cout<<o<<" "<<e<<"\n";
            }
        }
    }
    return 0;
}
