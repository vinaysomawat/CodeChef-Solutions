/* 
    Contest: CodeChef March 2020 Long challange
    Problem link: https://www.codechef.com/MARCH20B/problems/CHPINTU
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> f;
        vector<int> p;
        int temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            f.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            p.push_back(temp);
        }
        map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[f[i]]+=p[i];
        }
        int mincnt=INT_MAX;
        for(auto x:mp)
        {
            mincnt = min(mincnt, x.second);
        }
        cout<<mincnt<<endl;
    }
    return 0;
}
