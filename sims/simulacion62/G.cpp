#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

struct edge { ll u, v, id; }; 

struct graph {
  int n;
  vector<vector<ii>> adj; 
  vector<edge> edges; 
  graph(int _n): n(_n), adj(_n) {}
  void add_edge(ll u, ll v) {
    ll id = SZ(edges); 
    adj[u].pb({v, id}); adj[v].pb({u, id}); 
    edges.pb({u, v, id}); 
  }
  int add_node() { adj.pb({}); return n++; }
  vector<ii> &operator[] (ll u) { return adj[u]; }
};

struct BCC {
  int n; graph adj; 
  vector<vi> comps; 
  vi num, low, art, stk, bridge; 
  BCC(graph &_adj): n(_adj.n), adj(_adj) {
    num.resize(n), low.resize(n), art.resize(n), bridge.resize(SZ(adj.edges)); 
    for (ll u = 0, t; u < n; ++u) if (!num[u]) dfs(u, -1, t = 0); 
  } 

  void dfs(ll v, ll p, ll &t) {
    num[v] = low[v] = ++t; 
    stk.pb(v); 

    for (auto [u, id]: adj[v]) if (u != p) {
      if (!num[u]) {
        dfs(u,v,t); 
        low[v] = min(low[v], low[u]); 

        if (low[u] > num[v]) bridge[id] = true; 
        if (low[u] >= num[v]) {
          art[v] = (num[v] > 1 or num[u] > 2); 
          comps.pb({v}); 
          while (comps.back().back() != u) 
            comps.back().pb(stk.back()), stk.pop_back(); 
        }
      } 
      else low[v] = min(low[v], num[u]); 
    } 
  } 

  pair<vi, graph> build_tree() {
    graph tree(0); vi id(n); 
    forn(v,n) if (art[v]) id[v] = tree.add_node(); 
    for (auto &comp: comps) {
      ll node = tree.add_node(); 
      for (ll v: comp) {
        if (!art[v]) id[v] = node; 
        else tree.add_edge(node, id[v]); 
      }
    } 
    return {id, tree}; 
  } 
}; 

bool df(int v, int e, graph &g, vb &visto){
  visto[v]=true;
  if(v==e) return true;
  for(auto u:g.adj[v]) if(!visto[u.ff]){
    if(df(u.ff,e,g,visto)) return true;
  }
  visto[v]=false;
  return false;
}

void solve(){
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  s--; e--;
  graph g(n);
  forn(i,m){
    int a, b; cin >> a >> b;
    a--; b--;
    g.add_edge(a,b);
  }
  BCC b(g);
  pair <vi, graph> t=b.build_tree();
  vb visto(t.ss.n,false);
  df(t.ff[s],t.ff[e],t.ss,visto);
  vi ans;
  ans.pb(s); ans.pb(e);
  forn(i,n) if(i!=s and i!=e and visto[t.ff[i]] and b.art[i]) ans.pb(i);
  sort(all(ans));
  cout << SZ(ans) << "\n";
  forn(i,SZ(ans)) cout << ans[i]+1 << "\n";
}

int main() {
  FIN; 
  int t; cin >> t;
  while(t--) solve();
  return 0; 
} 
