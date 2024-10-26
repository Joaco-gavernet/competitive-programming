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

void bfs(int start, unordered_set<int> &nodes, vector<vii> &g, unordered_map<int,int> &teams, bool &check) {
  queue<int> q; q.push(start); 
  teams[start] = 1; 
  while (q.size()) {
    auto v = q.front(); q.pop(); 
    int next = (teams[v] == 1 ? 2 : 1); 
    for (auto [u, id] : g[v]) {
      if (esta(nodes,u) == false) continue; 
      if (teams[u] == 0) q.push(u), teams[u] = next; 
      else if (teams[u] == teams[v]) {
        check = false;
        return; 
      }
    }
  }
}

unordered_set<int> build_nodes(vi &v) {
  unordered_set<int> ans;  
  for (auto u: v) ans.insert(u); 
  return ans; 
}

void solve() {
  int n, m; cin >> n >> m;
  graph g(n);
  while (m--) {
    int a, b; cin >> a >> b;
    g.add_edge(--a, --b);
  }

  BCC bicomps(g); // O(n) 
  
  set<int> ans;
  forn(i,SZ(bicomps.comps)) {
    if (SZ(bicomps.comps[i]) <= 2) continue; 
    unordered_set<int> nodes = build_nodes(bicomps.comps[i]);

    unordered_map<int,int> teams;
    // if teams[v] == 0 -> nodo no visto
    // if teams{v] == 1 -> team 1
    // if teams[v] == 2 -> team 2

    bool check = true;
    bfs(*nodes.begin(), nodes, g.adj, teams, check);
    if (check == false) {
      for (auto x : nodes) {
        ans.insert(x);
      }
    }
  }
  cout << SZ(ans) << endl;
}

int main(){
  FIN;

  #ifndef LOCAL
  freopen("d.in", "r", stdin);
  #endif
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
