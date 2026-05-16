#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

const ll INF = 1LL<<60; 

struct Dinic {
  int nodes, src, dst; 
  vi dist, q, work;
  struct edge {int to, rev; ll f, cap; }; 
  vector<vector<edge>> g;
  Dinic(int x): nodes(x), dist(x), q(x), work(x), g(x) {}
  void add_edge(int s, int t, ll cap) {
    g[s].pb({t, SZ(g[t]), 0, cap}); 
    g[t].pb({s, SZ(g[s]) -1, 0, 0}); 
  }
  bool dinic_bfs() {
    fill(all(dist), -1); dist[src] = 0; 
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
    for (auto &i = work[u]; i < SZ(g[u]); i++) {
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

struct DSU {
  vi link, sz; 
  DSU(int tam) {
    link.resize(tam + 5), sz.resize(tam + 5);
    forn(i, tam + 5) link[i] = i, sz[i] = 1;
  }
  ll find(ll x) { return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }
  void join(ll a, ll b) {
    a = find(a), b = find(b); 
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b); 
    sz[a] += sz[b]; 
    link[b] = a; 
  }
};

struct edge{
  ll a, b, c;
  bool operator <(edge e)const{return c<e.c;}
};

int main() {
  FIN;
  int n, r, g;
  cin >> n >> r >> g;
  vector <edge> e(r);
  forn(i,r){
    cin >> e[i].a >> e[i].b >> e[i].c;
    e[i].a--; e[i].b--;
  }
  sort(all(e));
  vi t(g);
  vector <vi> v(g);
  forn(i,g) {
    cin >> t[i];
    forn(j,t[i]) {
      int x; cin >> x;
      x--;
      v[i].pb(x);
    }
  }
  Dinic di(g+n+2);
  forn(j,g){
    di.add_edge(0,1+j,1);
    forn(k,t[j]) di.add_edge(1+j,1+g+v[j][k],1);
  }
  forn(j,n) di.add_edge(1+g+j,1+g+n,1);
  if(di.max_flow(0,1+g+n)!=g) {cout << "-1\n"; return 0;}
  DSU d(n);
  ll c=0, ans=0, last=g;
  forn(i,r){
    if(c==n-g) break;
    if(d.same(e[i].a,e[i].b)) continue;
    d.join(e[i].a,e[i].b);
    Dinic din(g+n+2);
    forn(j,g){
      din.add_edge(0,1+j,1);
      forn(k,t[j]) din.add_edge(1+j,1+g+d.find(v[j][k]),1);
    }
    forn(j,n) din.add_edge(1+g+j,1+g+n,1);
    if(din.max_flow(0,1+g+n)!=last) {last--; continue;}
    c++;
    ans+=e[i].c;
  }
  if(c==n-g) cout << ans << "\n";
  else cout << "-1\n";
  return 0; 
}