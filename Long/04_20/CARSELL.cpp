/* 
    Contest: CodeChef APRIL 2020 LONG Challange DIV 1
    Problem link:https://www.codechef.com/APRIL20A/problems/CARSELL
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	ll n;
	cin>>n;
	multiset<int> ms;
	for(ll i=0,temp;i<n;i++)
	{
		cin>>temp;
		ms.insert(temp);
	}
	ll i=0,sum=0;
	for(auto it=ms.rbegin();it!=ms.rend();it++,i++)
	{
		sum += (*it - ((*it - i > 0) ? i : (*it))) % 1000000007;
	}
	cout<<sum%1000000007<<endl;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}