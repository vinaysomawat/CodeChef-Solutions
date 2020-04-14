#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


ll N, Q;
map<ll, ll> mp_cst, mp_visited, mp_hap;

class graph{
    private:
        map<ll, list<ll> > adj_list;
    public:
        void AddEdge(ll u, ll v){
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        void Traversal(ll src, ll dst);
} G, t_G;

void graph::Traversal(ll src, ll dst){
    queue<ll> Q;
    Q.push(src);
    mp_visited[src] = true;
    mp_hap[src] = (1*mp_cst[src])%MOD;

    while(!Q.empty()){
        ll top = Q.front();
        Q.pop();
        for(auto it:adj_list[top]){
            if(!mp_visited.count(it)){
                mp_visited[it] = true;
                mp_hap[it] = (mp_hap[top]*mp_cst[it])%MOD;
                Q.push(it);
            }
        }
    }
}

ll CntDiv(ll X){
    ll cnt = 0;
    for(ll i = 1; i <= sqrt(X); i++){
        if(X%i == 0){
            cnt++;
            if(X/i != i)
                cnt++;
            cnt %= MOD;
        }
    }
    return cnt;
}

void Input(){
    cin >> N, G = t_G, mp_cst.clear();
    for(ll i = 1; i < N; i++){
        ll u , v;
        cin >> u >> v;
        G.AddEdge(u, v);
    }

    for(ll i = 1; i <= N; i++){
        ll d;
        cin >> d;
        mp_cst[i] = d;
    }
}

void Solve(){
    cin >> Q;

    while(Q--){
        mp_hap.clear(), mp_visited.clear();
        ll u, v;
        cin >> u >> v;
        G.Traversal(u, v);
        cout << CntDiv(mp_hap[v]) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    while(T--){
        Input();
        Solve();
    }
    return 0;
} 