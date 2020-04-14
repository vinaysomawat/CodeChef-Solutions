/* 
    Contest: CodeChef APRIL 2020 LONG Challange DIV 1
    Problem link:https://www.codechef.com/APRIL20A/problems/ANSLEAK
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve()
{
    int N,M,K;
		cin>>N>>M>>K;
		int twoarr[N][K],point[N];
		for(int i=0; i<N; i++)
		{
			int arr[M] = {0};
			int arr2[M] = {0};
			for(int j=0; j<K; j++){
				cin>>twoarr[i][j];
				arr[twoarr[i][j]]++;
				arr2[twoarr[i][j]]++;
			}
			int lmax=0,lmaxvalue = 0;
			for(int k=0; k<M; k++)
			{
				if(lmaxvalue <= arr[k])
				{
					lmaxvalue = arr[k];
					lmax = k;
				}
			}
			point[i] = twoarr[i][lmax];
		}
		for(int i=0; i<N; i++){
			cout<<point[i]<<" ";
        }
		cout<<"\n";
}

int main()
{
    IOS
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
    return 0;
}