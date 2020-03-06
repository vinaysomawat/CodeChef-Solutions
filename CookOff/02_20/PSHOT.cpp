/*
Author: Vinay Somawat
Email: vinaysomawat@hotmail.com
webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void solve()
{
ll n;
      cin>>n;
      char a[2*n];
      for(ll i=0;i<2*n;i++)
      {
          cin>>a[i];
      }
      
      ll temp1=0;
      ll temp2=0;
      for(ll i=0;i<2*n;i++)
      {
         
          if(i%2==0)
          {
              if(a[i]=='1')
              temp1++;
          }
          
          else
          {
              
              if(a[i]=='1')
              temp2++;
          }
          
          if((temp1-temp2)>(((2*n)-i-1)/2)&&(i%2==1))
          {
              cout<<i+1<<endl;
              break;
          }
          else if((temp2-temp1)>(((2*n)-i-1)/2)&&(i%2==0))
          {
              
              cout<<i+1<<endl;
              break;
              
              
          }
          else if((temp1-temp2)>((((2*n)-i-1)/2)+1)&&(i%2==0))
          {
               cout<<i+1<<endl;
              break;
              
          }
          else if((temp2-temp1)>((((2*n)-i-1)/2))&&(i%2==1))
          {
               cout<<i+1<<endl;
              break;
              
          }
          else if(temp1-temp2==0&&i==(2*n)-1)
          {
              cout<<i+1<<endl;
              break;
          } 
      }
}

int main() {
  int t;
  cin>>t;
  while((t--)>0)
  {
      solve();
  }
  return 0;
}