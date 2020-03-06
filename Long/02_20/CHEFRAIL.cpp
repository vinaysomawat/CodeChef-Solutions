/*

Author:Vinay Somawat
Email :vinaysomawat40@gmail.com
Webpage: http://vinaysomawat.github.io/

*/


#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll temp=100001;

vector<ll> vect(temp+1,0);

void firstfuntion(ll N) {

	vector<ll> arr(temp+1,0);
	ll i,t,j,k,n,r=1,s=1,c=0;
	for(i=0;i<temp+1;i++)
	arr[i]=i;

    //for loop creation
	for(j=2;j<=temp;j++)
	{   if(arr[j]==j)
	   {
		for(k=j*j;k<=temp;k+=j)
		 {  if(arr[k]==k)
			arr[k]=j;
		 }
	   }
	}

	for(i=1;i<=N;i++)
	{   r=1,s=1;
	    c=0;
		n=i;
        //if it doesn't want to go.
		while(n>0)
		{
			if(r==arr[n])
			{
				c++;
				if(n==1)
				break;

			}
			else
			{
				if(c%2==1)
				s=s*r;
				c=1;
				r=arr[n];
				if(n==1)
				break;
			}
			n=n/arr[n];

		}
		vect[i]=s;
	}

}

void solve()
{
double z;
	ll t,i,n,temp,j,c,d,h,v,tempa,tempb,finalanswer,k;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{   c=0;
	    d=0;
	    h=0;
	    v=0;
	    finalanswer=0;
	    tempa=0;
	    tempb=0;
	    vector <ll> a(4,0), b(4,0);
		scanf("%lld %lld",&n,&temp);
		vector <ll> P(n,0),Q(temp,0);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&P[j]);
			if(P[j]>0)
			{
				c++;
				if(P[j]>tempa)
				tempa=P[j];
			}
			else if(P[j]<0)
			{
				d++;
				if((P[j]*-1)>tempb)
				tempb=(P[j]*-1);
			}
			else
			{
				finalanswer=finalanswer+(n-1)*temp;
			}
		}
		a[0]=tempa;
		a[1]=tempb;
		b[0]=tempa;
		b[1]=tempb;
		vector <ll> xp(c,0),pqr1(tempa+1,0),xn(d,0),abc1(tempb+1,0);
		for(j=0;j<n;j++)
		{
			if(P[j]>0)
			{
				pqr1[P[j]]=1;
				xp[h]=P[j];
				h++;
			}
			if(P[j]<0)
			{
				abc1[(P[j]*-1)]=1;
				xn[v]=P[j]*-1;
				v++;
			}
		}
		c=0,d=0,h=0,v=0,tempa=0,tempb=0;
		for(j=0;j<temp;j++)
		{
			scanf("%lld",&Q[j]);
			if(Q[j]>0)
			{
				c++;
				if(Q[j]>tempa)
				tempa=Q[j];
			}
		    else if(Q[j]<0)
			{
				d++;
				if((Q[j]*-1)>tempb)
				tempb=(Q[j]*-1);
			}
			else
			finalanswer=finalanswer+(temp-1)*n;
		}
		a[2]=tempa;
		a[3]=tempb;
		b[2]=tempa;
		b[3]=tempb;
		sort(a.begin(),a.end());
		firstfuntion(a[3]);

        //FOLLOWING CODE IS TAKEN FROM GEEKSFORGEEKS 
        //LINK IS MENTIONED ABOVE SOLUTION
		vector<ll> asd(tempa+1,0),jkl(tempb+1),ypaf(c,0),zxc(d,0);
		for(j=0;j<temp;j++)
		{
			if(Q[j]>0)
			{
				asd[Q[j]]=1;
				ypaf[h]=Q[j];
				h++;
			}
			else if(Q[j]<0)
			{
				jkl[(Q[j]*-1)]=1;
				zxc[v]=Q[j]*-1;
				v++;
			}
		}
		for(j=0;j<xn.size();j++)
		{   
			for(k=vect[xn[j]];k<=b[0];k+=vect[xn[j]])
			{  
				if(pqr1[k]==1)
				{
					z=sqrt(k*xn[j]);
					if(z==floor(z))
					{   
					    if(z<=asd.size())
						{
						if(asd[z]==1 )
		 				finalanswer++;
		 			    }
		 			    if(z<=jkl.size())
						{
						if(jkl[z]==1 )
						finalanswer++;
					    }
					}
				}
			}

	}
    //AGAIN FOR LOOP
		for(j=0;j<zxc.size();j++)
		{     

					for(k=vect[zxc[j]];k<=b[2];k+=vect[zxc[j]])
			{
				if(asd[k]==1)
				{
					z=sqrt(k*zxc[j]);
					if(z==floor(z))
					{ 
						if(z<=pqr1.size())
						{
						if(pqr1[z]==1  )
						finalanswer++;
					    }
					    if(z<=abc1.size())
					    {
						if(abc1[z]==1 )
						finalanswer++;
					    }
					}
				}
			}

	}
		cout<<finalanswer<<endl;
	}
}

int main()
{   
    solve();
	return 0;
}