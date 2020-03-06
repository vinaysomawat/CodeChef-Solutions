//Vinay Somawat
//vinaysomawat40@gmail.com

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t ;
	cin>>t;
	while(t--)
	{
	    int n,m,q;
	    cin>>n>>m>>q;
	    int i , j ;
	    int row[n]={0} , column[m] ={0};
	    int x , y ;
	    
	    
	    for(i=0;i<q;i++)
	    {
	        cin>>x>>y;
	        row[x-1]++;
	        column[y-1]++;
	    }

	    long long int OCells=0;
	    long long ERows=0;
	    long long EColumns=0;
	    long long ORows=0;
	    long long OColumns=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(row[i]&1)
	        {
	            ORows++;
	        }
	        else
	        {
	            ERows++;
	        }
	    }
	    
	    for(int i=0;i<m;i++)
	    {
	        if(column[i]&1)
	        {
	            OColumns++;
	        }
	        else
	        {
	            EColumns++;
	        }
	    }
	    
	    OCells = ORows*EColumns + ERows*OColumns;
	    cout<<OCells<<endl;
	}
	return 0;
}