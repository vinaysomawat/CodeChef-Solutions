/*
Author: Vinay Somawat
Email: vinaysomawat@hotmail.com
webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void leftRotatebyOne(ll arr[], int n) 
{ 
    ll temp = arr[0], i; 
    for (i = 0; i < n - 1; i++) 
        arr[i] = arr[i + 1]; 
  
    arr[i] = temp; 
} 

ll maxSubArraySum(ll a[], int size) 
{ 
   int max_so_far = 0, max_ending_here = 0; 
   for (int i = 0; i < size; i++) 
   { 
       max_ending_here = max_ending_here + a[i]; 
       if (max_ending_here < 0) 
           max_ending_here = 0; 
  
       /* Do not compare for all elements. Compare only    
          when  max_ending_here > 0 */
       else if (max_so_far < max_ending_here) 
           max_so_far = max_ending_here; 
   } 
   return max_so_far; 
} 

void solve()
{
      int n;
      cin>>n;
      ll v[n];
      for(int i=0;i<n;i++)
      {
          cin>>v[i];
      }  
      for(int i=0;i<n;i++)
      {
          cout<<maxSubArraySum(v,n)<<" ";
          leftRotatebyOne(v,n);
      }
        cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}