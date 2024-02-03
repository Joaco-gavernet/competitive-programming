#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define SZ(x) int((x).size())
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef vector<int> vi;
typedef vector<bool> vb;

vi w; // w[i] = "coins in room i"

/*
   Algoritmo para hallar las componentes fuertmente conexas.
   Una componente es fuertemente conexa cuando para todo nodo
   perteneciente a la componente, se puede llegar a cualquier 
   otro nodo tambien perteneciente a la componente.
*/
struct SCC {
  int n, scc;
  vector<vi> g, gr, ans;
  vb visto;
  vi order, comp_act, component;
  vi nw; // new weights for scc

  SCC(vector<vi> &_g): n(SZ(_g)) {
    g = _g;
    gr.resize(n), visto.resize(n), component.resize(n);
    forn(v, n) for(auto u: g[v]) gr[u].pb(v); // me lo creo aca el grafo traspuesto

    find_scc(); 
  }

  void DFS1 (int v) {
    visto[v] = true;
    for (int u : g[v]) if(!visto[u]) DFS1(u);
    order.pb(v);
  }

  void DFS2 (int v) {
    visto[v] = true;
    comp_act.pb(v);
    for (int u : gr[v]) if(!visto[u]) DFS2(u);
  }

  void find_scc() {
    fill(all(visto),false);
    forn(i,n) if(!visto[i]) DFS1(i);
    fill(all(visto),false);
    forn(i,n) {
      int v=order[n-i-1];
      if(!visto[v]) { 
        DFS2(v);
        ans.pb(comp_act);
        comp_act.clear();
      }
    }
    scc = SZ(ans); // cantidad de scc's
    forn(i, scc) for(auto v: ans[i]) component[v] = i;
  }
};

#define f first
#define s second

bitset<MAXN> visto;

// Topological sort
// Complexity: O(n+m)
vi tsort(vector<vi> &g, int n){  // lexicographically smallest topological sort
    vi r; priority_queue<ll> q;
    vi d(2*n);
    forn(i, n) for(ll j: g[i]) d[j]++;
    forn(i, n) if(!d[i]) q.push(-i);
    while(!q.empty()){
        ll x=-q.top(); q.pop(); 
        if (visto[x] == 1) r.pb(x);
        for(ll j: g[x]){
            d[j]--;
            if(!d[j]) q.push(-j);
        }
    }
    return r;  // if not DAG it will have less than n elements
}

void dfs(int v, vector<vi> &g) {
  visto[v] = true;
  for(int c: g[v]) {
      if (visto[c] == 0) dfs(c,g);
  }
}


int main(){
  FIN;

  // Steps for solution: 
  // 1. SCCs share a common profit and could be seen as a unique node.
  // 2. After simplifying nodes in SCCs, build alternative graph. 
  // 3. Find answer with Dynamic-Programming.

  int n,m; cin >> n >> m;
  w.resize(n);
  forn(i,n) cin >> w[i]; 

  vector<vi> g(n);
  forn(i,m) {
    int a,b; cin >> a >> b;
    g[--a].pb(--b);
  }

  SCC s(g);
  vector<vi> ans = s.ans;
  int nn = ans.size(); 
  vi component = s.component;

  vector<vi> ng(nn); // ng = "new SCC graph"
  vector<ll> nw(nn); // nw = "new weights/profit for SCC graph"

  forn(i,nn) for(int p: ans[i]) nw[i] += w[p];
  forn(v,g.size()) {
    for(int u: g[v]) {
      if (component[v] != component[u]) {
        ng[component[v]].pb(component[u]);
      }
    }
  }

  vector<ll> dp(nn);
  dfs(0,ng);
  vi tp = tsort(ng,nn);
  dbg("fin.");
  dbg(nw);
  forn(i,nn) dbg(ng[i]);
  forn(i,nn) dp[i] = nw[i];
  dbg(dp);

  ll tot = 0;
  for(int i: tp) { // push dp
    for(int x: ng[i]) {
      dbg(dp[i] + nw[x]); // check ????????????
      dp[x] = max(dp[x], dp[i] + nw[x]);
    }
    tot = max(tot,dp[i]);
    dbg(dp);
  }

  cout << tot << '\n';

  
  return 0;
}






