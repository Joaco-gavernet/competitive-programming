#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> ii;
#define NaN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"


void dfs(ll x, vector<vi>& g, vb& visto, vi& path, vector<ii>& taken) {
    visto[x] = true;
    path.pb(x); 
    for (auto y : g[x]) if (visto[y] == false) {
        taken.pb({min(x,y), max(x,y)}); 
        dfs(y, g, visto, path, taken);
    }
}

int reti() {
    cout << "impossible\n";
    return 0;
}

int main() {
    NaN; 
    ll n,m; cin>>n>>m;
    vector<vi> g(n);
    map<ii,ll> aristas;
    vi ans(m,1);
    forn(i,m){
        ll x,y; cin>>x>>y; x--; y--;
        if(x>y) swap(x,y);
        aristas[{x,y}]=i+1;
        g[x].pb(y);
        g[y].pb(x);
    }
    vi w(n); 
    vi s(n); forn(i,n) cin >> s[i], w[s[i] - 1] = i;
    auto cmp = [&](int a, int b) {
        return w[a] < w[b]; 
    }; 
    forn(i,n) sort(all(g[i]), cmp); 

    vb visto(n); 
    vi path;
    vector<ii> taken; 
    dfs(0, g, visto, path, taken); 

    forn(i,n) if (path[i] + 1 != s[i]) return reti(); 

    ll act = 1e9-1; 
    for (auto [x, y]: taken) {
        ans[aristas[{x, y}] - 1] = act;
        act--;
    }

    forn(i,m) cout<<ans[i]<<" ";
    cout<<"\n";

    return 0; 
}