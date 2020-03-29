/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link: https://www.codechef.com/LTIME82B/problems/SWPDGT
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int a,b;
    cin>>a>>b;
    int sum = a+b;
    if(a<10 && b<10)
    {
        cout<<sum<<endl;
    }
    else if(a<10 || b<10)
    {
        int temp1 = max(a,b);
        int temp2 = min(a,b);
        a = temp1;
        b = temp2;
        int a2 = a%10;
        a = a/10;
        int a1 = a%10;
        a = b*10+a2;
        b = a1;
        cout<<max(sum,a+b)<<endl;
    }
    else
    {
        int a1,a2,b1,b2,sum1,sum2;
        a2 = a%10;
        a = a/10;
        a1 = a%10;
        b2  =b%10;
        b = b/10;
        b1 = b%10;
        b = b1*10 + a1;
        a = b2*10 + a2;
        sum1 = a+b;
        b = a2*10 + b2;
        a = a1*10 + b1;
        sum2 = a+b;
        cout<<max(sum, max(sum1,sum2))<<endl;
    }
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