/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll finalsum=0;

vector<vector<int>> solve(vector<vector<int>> v, vector<int> &o)
{
    int maxindex=INT_MIN, p,q;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(maxindex<v[i][j])
            {
                maxindex = v[i][j];
                p= i;
                q=j;
            }
        }
    }
    o.push_back(maxindex);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            v[p][j]=0;
            v[i][q]=0;
        }
    }
    return v;
}

void solve()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"-400"<<endl;
        finalsum-=400;
    }
    else
    {
    char movie;
    int showtime;
    unordered_map<char, int> mpa;
    unordered_map<char, int> mpb;
    unordered_map<char, int> mpc;
    unordered_map<char, int> mpd;
    int cnta=0,cntb=0,cntc=0,cntd=0;
    for(int i=0;i<n;i++)
    {
        cin>>movie>>showtime;
        if(showtime==12)
        {
            mpa[movie]++;
        }
        if(showtime==3)
        {
            mpb[movie]++;
        }
        if(showtime==6)
        {
            mpc[movie]++;
        }
        if(showtime==9)
        {
            mpd[movie]++;
        }
    }
    vector<vector<int> > mat(4 , vector<int> (4)); 
    mat[0][0] = mpa['A'];
    mat[1][0] = mpa['B'];
    mat[2][0] = mpa['C'];
    mat[3][0] = mpa['D'];
    mat[0][1] = mpb['A'];
    mat[1][1] = mpb['B'];
    mat[2][1] = mpb['C'];
    mat[3][1] = mpb['D'];
    mat[0][2] = mpc['A'];
    mat[1][2] = mpc['B'];
    mat[2][2] = mpc['C'];
    mat[3][2] = mpc['D'];
    mat[0][3] = mpd['A'];
    mat[1][3] = mpd['B'];
    mat[2][3] = mpd['C'];
    mat[3][3] = mpd['D'];
    
    vector<int> v1;
    mat = solve(mat,v1); 
    mat = solve(mat,v1);
    mat = solve(mat,v1); 
    mat = solve(mat,v1);

    sort(v1.begin(), v1.end());

    int price=100;
    ll sum=0;
    int negative=0;
    for(int i=v1.size()-1;i>=0;i--, price-=25)
    {
        sum+=v1[i]*price;
        if(v1[i]==0)
        {
            negative++;
        }
    }
    if(negative>0)
    {
        sum -=negative*100;
    }
    finalsum+=sum;
    cout<<sum<<endl;
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
    cout<<finalsum<<endl;
    return 0;
}