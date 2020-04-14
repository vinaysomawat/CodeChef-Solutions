/* 
    Contest: CodeChef APRIL 2020 LONG Challange DIV 1
    Problem link:https://www.codechef.com/APRIL20A/problems/COVIDLQ
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int backpos = -6, currpos;
    bool check = true;
    for(int  i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp) {
            currpos = i;
            if(currpos - backpos < 6) {
                check = false;
            }
            backpos = currpos;
        }
    }
    cout << (check ? "YES" : "NO" ) << endl;
}

int main () {
    IOS
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}