#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl
#define esta(v,x) (v).find(x) != (v).end()

const ll MOD = (ll)(1e9+7); // 998244353
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

struct edge{ ll u, v, id; };

struct graph{
  int n;
  vector<vii> adj; // (to, id)
  vector<edge> edges;
  graph(int _n) : n(_n), adj(_n) {}

  void add_edge(ll u, ll v){
    ll id = SZ(edges);
    adj[u].pb({v, id}); adj[v].pb({u, id});
    edges.pb({u, v, id});
  }

  int add_node(){ adj.pb({}); return n++; }
  vii& operator[](ll u) { return adj[u]; }
};

struct BCC{
  int n; graph adj;
  vector<vi> comps;
  vi num, low, art, stk, bridge;
  BCC(graph &_adj): n(_adj.n), adj(_adj){
    num.resize(n), low.resize(n), art.resize(n), bridge.resize(SZ(adj.edges));
    for (ll u = 0, t; u < n; ++u) if (!num[u]) dfs(u, -1, t = 0);
  }

  void dfs(ll v, ll p, ll &t){
    num[v] = low[v] = ++t;
    stk.pb(v);
    for(auto [u, id]: adj[v]) if (u != p){
      if (!num[u]){
        dfs(u, v, t);
        low[v] = min(low[v], low[u]);
        if(low[u] > num[v]) bridge[id] = true;
        if(low[u] >= num[v]){
          art[v] = (num[v] > 1 || num[u] > 2);
          comps.pb({v});
          while (comps.back().back() != u)
            comps.back().pb(stk.back()), stk.pop_back();
        }
      }
      else low[v] = min(low[v], num[u]);
    }
  }

  // build the block cut tree
  pair<vi, graph> build_tree(){
    graph tree(0); vi id(n);
    forn(v, n) if (art[v]) id[v] = tree.add_node();
    for (auto &comp : comps){
      ll node = tree.add_node();
      for(ll v: comp){
        if (!art[v]) id[v] = node;
        else tree.add_edge(node, id[v]);
      }
    }
    return {id, tree};
  }
};

void dfs(int v, unordered_set<int> &nodes, vector<vii> &g, unordered_map<int,bool> &visto, unordered_map<int,int> &teams, bool my, bool &check) {
  // dbg(v, g[v]);
  visto[v] = true;
  if (my) teams[v] = 1;
  else teams[v] = 2; 
  for (auto [u, id] : g[v]) {
    if (esta(nodes,u) == false) continue;
    if (visto[u] == false) {
      dfs(u, nodes, g, visto, teams, !my, check);
      if (check == false) return;
    } else if (teams[u] == (my ? 1 : 2)) check = false;
  }
}

void solve() {
  int n, m; cin >> n >> m;
  graph g(n);
  while (m--) {
    int a, b; cin >> a >> b;
    g.add_edge(--a, --b);
  }

  // forn(i,n) dbg(i, g.adj[i]);
  // RAYA;

  BCC bicomps(g);
  const int tam = SZ(bicomps.comps);
  vector<unordered_set<int>> comps(tam);
  forn(i,tam) {
    auto list = bicomps.comps[i];
    for (auto v : list) comps[i].insert(v);
  }

  set<int> ans;
  dbg(tam);
  forn(i,tam) {
    dbg(i);
    auto nodes = comps[i];
    unordered_map<int,bool> visto; 
    unordered_map<int,int> teams;
    bool check = true;
    dfs(*nodes.begin(), nodes, g.adj, visto, teams, false, check);
    if (check == false) {
      for (auto x : nodes) {
        ans.insert(x);
      }
      // dbg(SZ(ans));
    }
    // RAYA;
  }
  // dbg("aca"); 
  // TODO: check why not reaching this point
  cout << SZ(ans) << endl;
}

int main(){
  #ifndef LOCAL
  freopen("d.in", "r", stdin);
  #endif
  FIN;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
