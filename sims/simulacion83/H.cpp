#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

struct edge { ll u, v, id; };

struct graph {
    int n; 
    vector<vii> adj;
    vector<edge> edges; 
    graph(int n): n(n), adj(n) {}
    void add_edge(ll u, ll v) {
        ll id = SZ(edges); 
        adj[u].pb({v, id}); adj[v].pb({u, id}); 
        edges.pb({u, v, id});
    }
    int add_node() { adj.pb({}); return n++; }
    vii& operator[](ll u) { return adj[u]; }
};

struct BCC {
    int n; graph adj;
    vector<vi> comps; 
    vi num, low, art, stk, bridge; 
    BCC(graph& adj): n(adj.n), adj(adj), num(n), low(n), art(n), bridge(SZ(adj.edges)) {
        for (ll u = 0, t; u < n; u++) if (!num[u]) dfs(u, -1, t = 0);
    }
    void dfs(ll v, ll p, ll& t) {
        num[v] = low[v] = ++t; 
        stk.pb(v);
        for (auto [u, id]: adj[v]) if (u != p) {
            if (!num[u]) {
                dfs(u, v, t); 
                low[v] = min(low[v], low[u]); 
                if (low[u] > num[v]) bridge[id] = true; 
                if (low[u] >= num[v]) {
                    art[v] = (num[v] > 1 or num[u] > 2); 
                    comps.pb({v}); 
                    while (comps.back().back() != u) 
                        comps.back().pb(stk.back()), stk.pop_back(); 
                }
            } else low[v] = min(low[v], num[u]); 
        }
    }
    pair<vi, graph> build_tree() {
        graph tree(0); vi id(n); 
        forn(v, n) if (art[v]) id[v] = tree.add_node(); 
        for (auto& comp: comps) {
            ll node = tree.add_node();
            for (ll v: comp) {
                if (!art[v]) id[v] = node; 
                else tree.add_edge(node, id[v]); 
            }
        }
        return {id, tree}; 
    }
};

bool solve(int ids) {
    int m; cin >> m;
    if(m==0) return false;
    cout << "Case " << ids << ": "; 
    vi u(m), v(m);
    ll n=0;
    forn(i,m){
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
        n=max(n,u[i]+1); n=max(n,v[i]+1);
    }
    graph g(n);
    forn(i,m) g.add_edge(u[i],v[i]);
    BCC b(g);
    auto [id,t]=b.build_tree();
    if(t.n==1) {cout << 2 << " " << n*(n-1)/2 << "\n"; return true;}
    ll ans=0, tot=1;
    vi tam(t.n);
    forn(i,n) tam[id[i]]++;
    forn(i,t.n) if(SZ(t.adj[i])==1){ans++; tot*=tam[i];}
    cout << ans << " " << tot << "\n";
    return true; 
}

int main() {
    FIN;
    bool ans = true; 
    int i = 1; 
    while (ans) ans = solve(i++);
    return 0;
}