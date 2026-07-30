#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"


struct DSU {
    vi link, sz;
    DSU(int tam) {
        link.resize(tam + 5), sz.resize(tam + 5);
        forn(i, tam + 5) link[i] = i, sz[i] = 1;
    }
    ll find(ll x) { return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { 
        return find(a) == find(b); 
    }
    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b]; 
        link[b] = a; 
    }
};

using vii = vector<ii>;
struct edge {
    ll u, v, id, w;
    bool operator < (struct edge& y) const {
        return w < y.w; 
    }
};
struct graph {
    int n; 
    vector<vii> adj; 
    vector<edge> edges; 
    graph(int _n) : n(_n), adj(_n) {}
    void add_edge(ll u, ll v) {
        ll id = SZ(edges); 
        adj[u].pb({v, id});
        adj[v].pb({u, id});
        edges.pb({u, v, id, 0}); 
    }
    int add_node() { adj.pb({}); return n++; }
    vii& operator[](ll u) { return adj[u]; }
};

struct BCC {
    int n; graph adj;
    vector<vi> comps; 
    vi num, low, art, stk, bridge; 
    BCC(graph& _adj): n(_adj.n), adj(_adj) {
        num.resize(n), low.resize(n), art.resize(n), bridge.resize(SZ(adj.edges));
        for (ll u = 0, t; u < n; ++u) if (!num[u]) dfs(u, -1, t = 0);
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
                    while (comps.back().back() != u) comps.back().pb(stk.back()), stk.pop_back(); 
                }
            } else low[v] = min(low[v], num[u]); 
        }
    }
};


int main() {
    FIN;
    int n, m; cin >> n >> m;
    vector <edge> v(m);
    vector <string> s={"none\n", "at least one\n", "any\n"};
    vi ans(m);
    forn(i,m){
        cin >> v[i].u >> v[i].v >> v[i].w;
        v[i].v--; v[i].u--; v[i].id=i;
    }
    sort(all(v));
    DSU d(n);
    vi last(n,-1), hash(n,-1);
    forn(i,m){
        int j=i+1;
        while(j<m and v[j].w==v[i].w) j++;
        vi ids;
        graph g(0);
        map <ii,int> mapa;
        forr(k,i,j) if(!d.same(v[k].u,v[k].v)){
            ans[v[k].id]++;
            ids.pb(v[k].id);
            v[k].u=d.find(v[k].u); v[k].v=d.find(v[k].v);
            if(v[k].u>v[k].v) swap(v[k].u,v[k].v);
            if(last[v[k].u]<i) {last[v[k].u]=i; hash[v[k].u]=g.add_node();}
            if(last[v[k].v]<i) {last[v[k].v]=i; hash[v[k].v]=g.add_node();}
            g.add_edge(hash[v[k].u],hash[v[k].v]);
            mapa[{hash[v[k].u],hash[v[k].v]}]++;
        }
        BCC b(g);
        forn(k,SZ(ids)) if(b.bridge[k] and mapa[{g.edges[k].u,g.edges[k].v}]==1) ans[ids[k]]++;
        forr(k,i,j) d.join(v[k].u,v[k].v);
        i=j-1;
    }
    forn(i,m) cout << s[ans[i]];
    return 0;
}