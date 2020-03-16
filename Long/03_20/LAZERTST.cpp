/* 
    Contest: CodeChef March 2020 Long challange
    Problem link:https://www.codechef.com/MARCH20B/problems/LAZERTST
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/

#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++)
#define pb push_back
#define all(m) m.begin(),x.end()
using namespace std;


struct point {
    long long m, z;
    point() {}
    point(long long _m, long long _z) : m(_m), z(_z) {}
    point operator-(const point& p) const { return point(m - p.m, z - p.z); }
    long long xboxcheck(const point& p) const { return m * p.z - z * p.m; }
    long long xboxcheck(const point& a, const point& b) const { return (a - *this).xboxcheck(b - *this); }
};

int stupidfuntion(const long long& m) { return m >= 0 ? m ? 1 : 0 : -1; }

bool function2(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool stupidfunctionverify(const point& a, const point& b, const point& c, const point& d) {
    if (c.xboxcheck(a, d) == 0 && c.xboxcheck(b, d) == 0)
        return function2(a.m, b.m, c.m, d.m) && function2(a.z, b.z, c.z, d.z);
    return stupidfuntion(a.xboxcheck(b, c)) != stupidfuntion(a.xboxcheck(b, d)) &&
           stupidfuntion(c.xboxcheck(d, a)) != stupidfuntion(c.xboxcheck(d, b));
}


void solve()
{
    ll n, q;
		cin >> n >> q;
		vl a(n);
		point points[n];
		repll(i, 0, n) {
			cin >> a[i];
			points[i] = point(i+1, a[i]);
		}
		repll(i, 0, q) {
			ll m1, m2, z;
			cin >> m1 >> m2 >> z;
			ll answer = 0;
			point a(m1, z), b(m2, z);
			repll(j, 1, n) {
				if(stupidfunctionverify(a, b, points[j-1], points[j])) {
					answer++;
					if(b.m == points[j-1].m && b.z == points[j-1].z)
						answer--;
					if(a.m == points[j].m && a.z == points[j].z)
						answer--;
				}
			}
			cout << answer << "\n";
}
}

  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}