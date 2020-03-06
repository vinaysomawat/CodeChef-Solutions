/* Problem link: https://www.codechef.com/AUG19B/problems/MSNSADM1 
    Author: Vinay Somawat
    Webpage: http://vinaysomawat.github.io/
    Contest: CodeChef Auguest Long challange
*/

#include<bits/stdc++.h>
#define mod 1000000007
typedef long double ld;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 26
#define MAX_CHAR 256
using namespace std;


int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n,total=0;
         cin>>n;
         int a[n],b[n],c[n];
         for(int i=0;i<n;i++)
         {
             cin>>a[i];
         }
         for(int i=0;i<n;i++)
         {
             cin>>b[i];
         }
         for(int i=0;i<n;i++)
         {
            total = (a[i]*20) - (b[i]*10);
            c[i]=total;
         }
         int max;
         max = *max_element(c,c+n);
         if(max<0)
         {
             max=0;
         }
         cout<<max<<endl;
     }
	return 0;
}