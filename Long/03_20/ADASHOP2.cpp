/* 
    Contest: CodeChef March 2020 Long challange
    Problem link: https://www.codechef.com/MARCH20B/problems/ADASHOP2
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isSafe(int r, int c)
{
    if(r>0 && r<=8 && c>0 && c<=8)
    {
        return true;
    }
    return false;
}

pair<int,int> swapele(int r, int c)
{
    pair<int,int> temp;
    swap(r,c);
    temp = make_pair(r,c);
    return temp;
}

pair<int,int> addition(int r, int c, int val)
{
    pair<int,int> temp;
    r +=val;
    c +=val;
    temp = make_pair(r,c);
    return temp;
}

pair<int,int> addsub(int r, int c, int val)
{
    pair<int,int> temp;
    r+=val;
    c-=val;
    temp = make_pair(r,c);
    return temp;
}

pair<int,int> subadd(int r, int c, int val)
{
    pair<int,int> temp;
    r-=val;
    c+=val;
    temp = make_pair(r,c);
    return temp;
}
pair<int,int> sub(int r, int c, int val)
{
    pair<int,int> temp;
    r-=val;
    c-=val;
    temp = make_pair(r,c);
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        
        int m,n;
        cin>>m>>n;
        vector<pair<int,int> >vtr;
        vtr.push_back({m,n});
        int r,c;
        int p=(m-n)/2;
         r=m-p;
         c=n+p;
        int first=r,second=c,i=r-1;
        while(first>1 && second>1)
        {
            vtr.push_back({first,second});
            if(first<=4 && second<=4)
            {vtr.push_back({2*first-1,1});
            vtr.push_back({1,2*second-1});
            }
            else
            {
              vtr.push_back({8,2*first-8});
              vtr.push_back({2*first-8,8});

            }
            vtr.push_back({first,second});
            first--;
            second--;
        }
        vtr.push_back({first,second});
        while(first<=r && second<=c)
        {
            vtr.push_back({first,second});
            first++;
            second++;
        }
        while(first<8 && second<8)
        {
            vtr.push_back({first,second});
             if(first<=4 && second<=4)
            {vtr.push_back({2*first-1,1});
            vtr.push_back({1,2*second-1});
            }
            else
            {
              vtr.push_back({8,2*first-8});
              vtr.push_back({2*first-8,8});

            }
            vtr.push_back({first,second});
            first++;
            second++;
            vtr.push_back({first,second});
        }
        vector<pair<int,int> >e;
        if(first==8 && second==8 && r!=8 && c!=8)
        vtr.push_back({8,8});
        e.push_back(vtr[0]);
        for(int i=1;i<vtr.size();i++)
        if(vtr[i]!=e[e.size()-1])
        e.push_back(vtr[i]);
        cout<<e.size()<<"\n";
        for(int i=0;i<e.size();i++)
        cout<<e[i].first<<" "<<e[i].second<<"\n";
    }
    return 0;
}