/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link:https://www.codechef.com/COOK116B/problems/CHCBOX
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
    vector<int> v;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    int p = *max_element(v.begin(), v.end());
    // cout<<"max element:"<<p<<endl;
    vector<int> points;
    // cout<<"max index: ";
    for(int i=0;i<v.size();i++)
    {
        if(p==v[i])
        {
            points.push_back(i);
            // cout<<i<<" ";
        }
    }
    // cout<<endl;
    int low = points[0];
    int high = points[points.size()-1];
    int final = low+(n-high)-1;
    // cout<<"low: "<<low<<endl;
    // cout<<"high: "<<high<<endl;
    // cout<<"final: "<<final<<endl;
    vector<int> diff;
    diff.push_back(final);
    //cout<<"difference: ";
    for(int i=0;i<points.size()-1;i++)
    {
        diff.push_back(points[i+1]-points[i]-1);
        //cout<<points[i+1]-points[i]-1<<" ";
    }
    //cout<<endl;
    int maxdiff = *max_element(diff.begin(),diff.end());
    //cout<<"maxdiff: "<<maxdiff<<endl;
    cout<<max((maxdiff-n/2+1),0)<<endl;
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