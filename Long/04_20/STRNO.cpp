/* 
    Contest: CodeChef APRIL 2020 LONG Challange DIV 1
    Problem link:https://www.codechef.com/APRIL20A/problems/STRNO
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


int Factors(int n)
{
    int temp=0;
    while (n % 2 == 0)
    {
        temp++;
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            temp++;
            n = n / i;
        }
    }

    if (n > 2)
        temp++;

    return temp;
}



void solve()
{
    int x,k;
    cin >> x>>k;

    int answer = Factors(x);

    if (k <= answer)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
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