/* 
    Contest: CodeChef APRIL 2020 LONG Challange DIV 1
    Problem link:https://www.codechef.com/APRIL20A/problems/SQRDSUB
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

void solve()
{
    int n;
    cin >> n;

    vector<int> vect;
    long long answer = 0ll;
    int ptrfront = -1, ptrback = -1;

    for (int p = 0,temp; p < n; p++)
    {        
        cin >> temp;
        vect.push_back(temp);
    }

    for (int p = 0; p < n; p++)
    {
        if (vect[p] % 4 == 0){
            answer += p + 1;
            ptrback = ptrfront;
            ptrfront = p;
        }

        else if (vect[p] % 2 == 0){
            if (ptrfront != -1)
                answer += p - (p - ptrfront - 1);

            ptrback = ptrfront;
            ptrfront = p;
        }

        else
        {
            if (ptrfront != -1 && ptrback != -1)
            {
                if (vect[ptrfront] % 4 == 0)
                    answer += (p + 1);
                else
                    answer += (p + 1) - (ptrfront - ptrback);
            }
            else if (ptrfront != -1 && ptrback == -1)
            {
                if (vect[ptrfront] % 4 == 0)
                    answer += p + 1;
                else
                    answer += (p - ptrfront);
            }
            else
                answer += p + 1;
                
        }
        
    }
    cout << answer <<endl;
}

int main()
{
    IOS
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}