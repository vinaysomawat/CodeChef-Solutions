/*
Author: Vinay Somawat
Email: vinaysomawat@hotmail.com
webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt1=0,cnt2=0;
    int goal = n/2 +1;
    int f=1;
    for(int i=0;i<s.length();i++)
    {
        if(i%2==0)
        {
            if(s[i]=='1')
            {
                cnt1++;
            }
        }
        else 
        {
            if(s[i]=='1')
            {
                cnt2++;
            }
        }
        if(abs(cnt1-cnt2)>goal && i>n/2)
        {
            cout<<i<<endl;
            f=0;
            break;
        }
        //cout<<cnt1<<" "<<cnt2<<endl;
    }
    if(f==1)
    {
        cout<<2*n<<endl;
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