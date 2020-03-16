/* 
    Contest: CodeChef March 2020 Long challange
    Problem link: https://www.codechef.com/MARCH20B/problems/MDSWIN2
    Author: Vinay Somawat
    Author's Webpage: http://vinaysomawat.github.io/
*/

#include <bits/stdc++.h>
#define ll long
using namespace std;

ll mod = 998244353;
const ll elementmax = 100001;
ll array1[elementmax];
ll array2[elementmax];

const ll elementmid = 10001;
ll matched[elementmid][elementmid];

ll relatedarr[elementmax];
struct Cmd {
    ll l, r, id;
    friend bool operator < (const Cmd& a, const Cmd& b) {
        if(relatedarr[a.l]==relatedarr[b.l]) return a.r < b.r;
        return relatedarr[a.l] < relatedarr[b.l];
    }
} matchedarray[elementmax];

 ll function_gcd(ll a,ll b){
    if(b==0) return a;
    return function_gcd(b,a%b);
 }

void e_function_gcd(ll a,ll b,ll &x,ll &y) {
    if(!b) {
        x = 1, y=0;
        return;
    }
    e_function_gcd(b,a%b,x,y);
    ll l=x;
    x=y;
    y=l-a/b*y;
}

ll function1(ll mod, ll n,ll m) {
    if(n<elementmid) return matched[n][m];
    if(m==1 || m==n-1) return n;
    if(m>n) return 0;
    if(n==m) return 1;
    ll nn=array1[n], mm=(array1[m]*array1[n-m])%mod;
    ll d=function_gcd(nn,mm);
    nn/=d, mm/=d;
    ll x,y;
    e_function_gcd(mm,mod,x,y);
    x=(x+mod)%mod;
    return (x*nn)%mod;
}

ll array4[elementmax], array3[elementmax], array5[elementmax], all;
bool itvisited[elementmax];
void addition(ll x) {
    ++array3[++array5[x]];
    array4[++all]=array5[x];
    --array3[array5[x]-1];
}

void deletion(ll x) {
    ++array3[--array5[x]];
    array4[++all]=array5[x];
    --array3[array5[x]+1];
}

void e_function_gcd2(ll a,ll b,ll &x,ll &y) {
    if(!b) {
        x = 1, y=0;
        return;
    }
    e_function_gcd(b,a%b,x,y);
    ll l=x;
    x=y;
    y=l-a/b*y;
}

ll function2() {
    ll k = 0;
    vector<ll> vt;
    for(ll j=1;j <= all;j++) if(!itvisited[array4[j]]&&array3[array4[j]]>0) {
        vt.push_back(array4[j]);
        array4[++k]=array4[j];
        itvisited[array4[j]]=true;
    }
    all=k;
    for(int j=1;j<=k;j++) itvisited[array4[j]] = false;
    ll sum = 0;
    for(ll i: vt) if(array3[i]%2) sum ^= i;
    if(sum==0) return 0;
    ll res = 0, ans, temparr;
    for(ll i: vt) if(array3[i]>0) {
        ans = sum^i;
        if(ans > i) continue;
        temparr = function1(mod, i, i-ans);
        temparr = (temparr*array3[i])%mod;
        res = (res+temparr)%mod;
    }
    return res;
}
void e_function_gcd3(ll a,ll b,ll &x,ll &y) {
    if(!b) {
        x = 1, y=0;
        return;
    }
    e_function_gcd(b,a%b,x,y);
    ll l=x;
    x=y;
    y=l-a/b*y;
}
void solve(ll m) {
    ll L = 1, R = 0;
    vector<ll> res(m+1);
    for(int i=1;i<=m;i++) {
        for(;R<matchedarray[i].r;R++) addition(array2[R+1]);
        for(;L>matchedarray[i].l;L--) addition(array2[L-1]);
        for(;R>matchedarray[i].r;R--) deletion(array2[R]);
        for(;L<matchedarray[i].l;L++) deletion(array2[L]);
        res[matchedarray[i].id] = function2();
    }
    for(int i=1;i<=m;i++) printf("%ld\n", res[i]);
}

void startedhere() {
    array1[0] = 1;
    for(int i=1;i<elementmax;i++) array1[i] = (array1[i-1]*i)%mod;
    
    for(int i=0;i<elementmid;i++) {
        matched[0][i] = 0; matched[i][0] = 1;
    }
    for(int i=1;i<elementmid;i++) for(int j=1;j<=i;j++) {
        matched[i][j] = (matched[i-1][j]+matched[i-1][j-1])%mod;
    }
}

int main(){
    startedhere();
    ll t, n, q, l, r; cin>>t;
    while(t--) {
        scanf("%ld", &n); ll sq = sqrt(n);
        for(int i=1;i<=n;i++) {
            scanf("%ld", &array2[i]); relatedarr[i] = (i-1)/sq+1;
        }
        unordered_map<ll, ll> unordermp;
        for(int i=1;i<=n;i++) {
            if(unordermp.find(array2[i])==unordermp.end()) unordermp[array2[i]] = unordermp.size();
            array2[i] = unordermp[array2[i]];
        }
        scanf("%ld", &q);
        for(int i=1;i<=q;i++) {
            scanf("%ld%ld", &matchedarray[i].l, &matchedarray[i].r);
            matchedarray[i].id = i;
        }
        memset(array4, 0, sizeof(array4));
        memset(array3, 0, sizeof(array3));
        memset(array5, 0, sizeof(array5));
        memset(itvisited, 0, sizeof(itvisited));
        all = 0;
        sort(matchedarray+1, matchedarray+q+1);
        solve(q);
    }
    return 0;
}