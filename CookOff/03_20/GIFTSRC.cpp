/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link:https://www.codechef.com/COOK116B/problems/GIFTSRC
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int x=0,y=0;
    if(str[0]=='L')
    {
        x--;
    }
    if(str[0]=='R')
    {
        x++;
    }
    if(str[0]=='D')
    {
        y--;
    }
    if(str[0]=='U')
    {
        y++;
    }
    for(int i=1;i<n;i++)
    {
        if(str[i-1]=='L' || str[i-1]=='R')
        {
            if(str[i]=='U')
            {
                y++;
            }
            if(str[i]=='D')
            {
                y--;
            }
        }
        if(str[i-1]=='U' || str[i-1]=='D')
        {
            if(str[i]=='R')
            {
                x++;
            }
            if(str[i]=='L')
            {
                x--;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
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