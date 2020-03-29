/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link: https://www.codechef.com/LTIME82B/problems/PRFXGD
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
    string str;
    cin>>str;
    int k,x;
    cin>>k>>x;
    unordered_map<char, int> mp;
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        mp[str[i]]++;
        if(mp[str[i]]>x)
        {
            mp[str[i]]--;
            k--;
            if(k<0)
            break;
            else 
            continue;
        }
        ans++;
    }
    cout<<ans<<endl;
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