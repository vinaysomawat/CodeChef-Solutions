/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link:https://www.codechef.com/CHPTRS01/problems/FUNRUN
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
    int n,temp;
    cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        b.push_back(temp);
    }
    if(*max_element(a.begin(), a.end())!=*max_element(b.begin(),b.end()))
    {
        cout<<"YES"<<endl;
    }
    else 
    cout<<"NO"<<endl;
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