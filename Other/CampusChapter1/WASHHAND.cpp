/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link:https://www.codechef.com/CHPTRS01/problems/WASHHAND
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n,k;
    cin>>n;
	int cnt=0;

		int infarr[n+1];
		bool Arr[n+1];
		fill(Arr, Arr+n+1, false);

		stack<int> stk;

		string str;
		cin>>str;
		for(int i=1; i<=n; i++)
		{
			infarr[i] = str[i-1]-'0';
			if(infarr[i]==1) {
				stk.push(i);
				cnt++;
			}
		}


		cin>>k;

		int isolatedarr[k+1];
		for(int i =1; i<=k; i++)
			cin>>isolatedarr[i];

	           
		for(int day=1; day<= k; day++)
		{
			Arr[ isolatedarr[day]] = true;

			stack<int> stknew;

			int index;
			while(!stk.empty())
			{	
				index = stk.top();
				stk.pop();

				if(index-1>0 && !Arr[index] && infarr[index-1]==0){
					cnt++;
					infarr[index-1] = 1;
					stknew.push(index-1);
				}

				if(index+1 <= n && !Arr[index+1] && infarr[index+1]== 0){
					cnt++;
					infarr[index+1] = 1;
					stknew.push(index+1);
				}
			}

			stk = stknew;
		}

		cout<<cnt<<"\n";
}

int main()
{	
    IOS
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}

	return 0;
}