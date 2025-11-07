#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


// DSU struct con path compression y union por size
// Complejidad: O(ack(n)) por operacion, donde ack(n) es la funcion inversa de Ackermann, casi O(1)
struct DSU {
  vi link, sz;

  DSU(int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i, tam+5) link[i] = i, sz[i] = 1;
  }

  ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }

  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
  }
};

struct edge { int u, v; ll w; }; 

void solve() {
  int n, m; cin >> n >> m; 
  vi deg(n); 
  vector<vector<ii>> g(n); 
  ll W = 0; 
  vector<edge> edg(m); 
  forn(i,m) {
    int u, v; ll w; 
    cin >> u >> v >> w; 
    u--, v--; 
    deg[u]++, deg[v]++; 
    W += w; 
    g[u].pb({v, w}); 
    g[v].pb({u, w}); 
    edg[i] = {u, v, w}; 
  }

  int odds = 0; 
  forn(i,n) if (deg[i]&1) odds++; 

  ll J = 0; // cost for the selected joins 
  if (odds) {
    // 1. build reconstruction tree 
    DSU ds(n); 
    vector<vi> tree(n+m), treer(n+m);  
    vi top(n); 
    iota(all(top), 0); // each node is it's own top at first 
    // from [0..n) represent a vertex
    // from [n..n+m) represent an edge 
    forn(e, m) {
      auto [u, v, w] = edg[e]; 
      if (ds.same(u, v) == false) {
        tree[top[ds.find(u)]].pb(n+e); 
        tree[top[ds.find(v)]].pb(n+e);
        treer[n+e].pb(top[ds.find(u)]); 
        treer[n+e].pb(top[ds.find(v)]); 
        ds.join(u, v); 
      } else {
        tree[top[ds.find(u)]].pb(n+e); 
        treer[n+e].pb(top[ds.find(u)]); 
      }
      top[ds.find(u)] = n+e; 
    }

    // 2. find best pairings of odd vertices, (bottom to top) 
    vi depth(n, -1); 
    function<void(int,int)> dfs = [&](int x, int act) {
      if (SZ(treer[x]) == 0) depth[x] = act++; 
      for (auto y: treer[x]) dfs(y, act +1); 
    }; 
    dfs(n+m-1, 0); 

    priority_queue<ii> pq; 
    forn(v, n) if (deg[v]&1) pq.push({depth[v], v}); 
    assert(SZ(pq) %2 == 0); 
    vi fathers; 
    while (SZ(pq)) {
      auto act = pq.top(); pq.pop(); 
      if (pq.top() == act) {
        fathers.pb(act.ss); 
        pq.pop(); 
      } else {
        auto [de, v] = act; 
        pq.push({de-1, tree[v].back()});
      }
    }

    // 3. find best cost for each LCA of the defined pairs 
    const ll INF = 1LL<<60; 
    vi best(n+m, INF); 
    function<void(int,ll)> cost = [&](int x, ll act) {
      if (SZ(treer[x]) == 0) return; 
      act = min(act, edg[x-n].w); 
      best[x] = act; 
      for (auto y: treer[x]) cost(y, act); 
    }; 
    cost(n+m-1, INF); 
    for (auto f: fathers) J += best[f];
  }
  cout << W + J << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
