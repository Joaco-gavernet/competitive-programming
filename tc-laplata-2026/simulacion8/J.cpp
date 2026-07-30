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


const int INF = 1LL<<30; 

struct Dinic {
    int nodes, src, dst; 
    vector<int> dist, q, work;
    struct edge { int to, rev; ll f, cap; };
    vector<vector<edge>> g;
    Dinic(int x): nodes(x), dist(x), q(x), work(x), g(x) {}
    void add_edge(int s, int t, ll cap) {
        g[s].pb({t, SZ(g[t]), 0, cap}); 
        g[t].pb({s, SZ(g[s]) - 1, 0, 0}); 
    }
    bool dinic_bfs() {
        fill(all(dist), - 1); dist[src] = 0;
        int qt = 0; q[qt++] = src;
        forn(qh, qt) {
            int u = q[qh];
            forn(i, SZ(g[u])) {
                edge &e = g[u][i]; int v = g[u][i].to;
                if (dist[v] < 0 and e.f < e.cap) dist[v] = dist[u] + 1, q[qt++] = v;
            }
        }
        return dist[dst] >= 0;
    }
    ll dinic_dfs(int u, ll f) {
        if (u == dst) return f;
        for (int &i = work[u]; i < SZ(g[u]); i++) {
            edge &e = g[u][i]; 
            if (e.cap <= e.f) continue; 
            int v = e.to;
            if (dist[v] == dist[u] + 1) {
                ll df = dinic_dfs(v, min(f, e.cap - e.f)); 
                if (df > 0) { e.f += df; g[v][e.rev].f -= df; return df; }
            }
        }
        return 0;
    }
    ll max_flow(int _src, int _dst) {
        src = _src, dst = _dst; 
        ll result = 0;
        while (dinic_bfs()) {
            fill(all(work), 0);
            while (ll delta = dinic_dfs(src, INF)) result += delta; 
        }
        return result; 
    }
};

int main() {
    FIN;
    ll n,m; cin>>n>>m;
    vector<pair<ii,ll>> aristas(m);
    forn(i,m){
        cin>>aristas[i].ff.ff;
        cin>>aristas[i].ff.ss;
        cin>>aristas[i].ss;
    }
    ll l=-1,r=1e9+1;
    ll med=(l+r)/2;
    while(l+1<r){
        Dinic check(2*n+2);
        // DBG(med);
        forn(i,n) check.add_edge(0,i+1,1);
        forn(i,n) check.add_edge(n+1+i,2*n+1,1);
        forn(i,m) if(aristas[i].ss <= med){
            ii u=aristas[i].ff;
            check.add_edge(u.ff,u.ss+n,INF);
        }
        ll ans=check.max_flow(0,2*n+1);
        if(ans == n) r=med;
        else l=med;
        med=(l+r)/2;
    }
    if(r==1e9+1) cout<<"-1\n";
    else cout<<r<<"\n";
    return 0;
}