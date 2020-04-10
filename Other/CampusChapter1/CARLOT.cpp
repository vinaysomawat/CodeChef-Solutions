/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link:https://www.codechef.com/CHPTRS01/problems/CARLOT
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
    
}

int main()
{
	int t;
    int m,n;
	int array1[301],array2[301];
	bool checkarray[301];
	char elementvalue;
    
	cin >>t;
	while(t--)
	{
		cin>>m>>n;
		fill(checkarray, checkarray+m+1, false);

		int initial=m+1,stop=-1;
		for(int i=0; i<m; i++)
		{	array1[i]=n+1;
			array2[i]= -1;
			for(int j =0; j<n; j++)
			{
				cin>>elementvalue;
				if(elementvalue == 'P') {
					array1[i] = min(array1[i],j);
					array2[i] = max(array2[i],j);
				
					initial = min(initial,i);
					stop = max(stop, i);
					checkarray[i] =  true;
				}
			}
		}
		
		if(initial > stop) {
			cout<<"0"<<endl;
            continue;
		}


		array2[stop+1] = array2[stop];
		array1[stop+1] = array1[stop];
		checkarray[stop+1]  = true;

		int tillstep;

		if(initial%2 == 0) tillstep = array1[initial];
		else tillstep = array2[initial];
		int countbars=0;


		for(int i= initial; i <= stop; i++ )
		{	if(!checkarray[i]) continue;
			
			if(i%2 == 0)
			{
				countbars+= (array1[i] - tillstep);
				countbars+= (array2[i]-array1[i]);
				tillstep = array2[i];

				int idx=i+1;
				while(!checkarray[idx]) idx++;

				if(idx%2 == 0 && array1[idx] < tillstep)
				{	
					countbars+= tillstep- array1[idx];
					tillstep = array1[idx];	
				}
				else if(idx%2 == 1 && array2[idx] > tillstep)
				{
					countbars += (array2[idx] - tillstep );
					tillstep = array2[idx];
				}
					 
			}
			else
			{
				countbars+= (tillstep - array2[i]);
				countbars+= (array2[i]-array1[i]);
				tillstep = array1[i];

				int idx=i+1;
				while(!checkarray[idx]) idx++;


				if(idx%2 == 0 && array1[idx] < tillstep)
				{	
					countbars+= tillstep- array1[idx];
					tillstep = array1[idx];	
				}
				else if(idx%2 == 1 && array2[idx] > tillstep)
				{
					countbars += (array2[idx] - tillstep );
					tillstep = array2[idx];
				}

				
			}

		}
		countbars+= (stop-initial);
		cout<<countbars<<endl;
	}
	return 0;
}