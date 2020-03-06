//Vinay Somawat
//vinaysomawat40@gmail.com

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

//counting divisor refernce geekforgeeks for optimization
//https://www.geeksforgeeks.org/count-divisors-n-on13/
ll countDivisors(ll n) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<countDivisors(abs(a-b))<<endl;
    }
    return 0;
}