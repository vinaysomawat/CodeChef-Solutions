/* 
    Contest: CodeChef March 2020 Cook-Off challange
    Problem link:https://www.codechef.com/CHPTRS01/problems/GAMENUM
    GitHub Solution Repository: https://github.com/vinaysomawat/CodeChef-Solutions
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
    Author's mail: vinaysomawat@hotmail.com
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
#else
#define trace(...) 42
#endif

ll n;

void fill(ll a, string &aa){
    int i = n - 1;

    while(a){
        if (a&1){
            aa[i] = '1';
        }
        a = a >> 1;
        i--;
    }
}

void solve()
{
    ll a, b;
        cin >> a >> b;

        n = floor(log2(max(a, b))) + 1;
        string aa(n, '0'), bb(n, '0');

        fill(a, aa);
        fill(b, bb);

        trace(aa, bb);

        ll mx = a ^ b;
        trace(mx);

        int rotations = 0;
        int ansrt = 0;

        for (int i = 1; i <= 65; i++){
            rotate(bb.rbegin(), bb.rbegin()+1, bb.rend());
            ll x = bitset<64>(bb).to_ullong();
            if (x == b) break;
            rotations++;
            if ((x ^ a) > mx){
                ansrt = rotations;
                mx = x ^ a;
            }
        }

        cout << ansrt << ' ' << mx << endl;
}

int main(){
    IOS;
    #ifdef LOCAL
    #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}