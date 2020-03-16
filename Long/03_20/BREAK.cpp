/* 
    Contest: CodeChef March 2020 Long challange
    Problem link: https://www.codechef.com/MARCH20B/problems/BREAK
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/


#include <bits/stdc++.h>
#define ll long
using namespace std;

bool function1(vector<ll>& p, vector<ll>& q, ll n) {
    //sorting both vectors
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    if(p[0]>=q[0]) return false;
    unordered_set<ll> uset;
    uset.insert(p[0]);
    uset.insert(q[0]);
    for(ll i=1;i<n;i++) {
        if(uset.count(p[i])==0) return false;
        if(p[i]>=q[i]) return false;
        uset.insert(p[i]);
        uset.insert(q[i]);
    }
    return true;
}


//check 1
bool check(ll a, ll b)
{
    return 1;
}

//check 2
bool check1(ll k, ll j)
{
    return 0;
}

bool function2(vector<ll>& p, vector<ll>& q, ll n, ll s) {
    //calling function1 here

    if(s==1) return function1(p, q, n);
    if(n==1) return p[0]<q[0];
    vector<ll> v(p.begin(), p.end());
    v.insert(v.end(), q.begin(), q.end());
    sort(v.begin(), v.end());
    for(ll i=0;i<n;i++) if(v[i]>=v[i+n]) return false;
    return true;
}

int main(){
    ll t, s, n; cin>>t>>s;
    while(t--) {
        cin>>n;
        vector<ll> p(n), q(n);
        for(ll& k: p) cin>>k;
        for(ll& k: q) cin>>k;
        if(function2(p, q, n, s))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}