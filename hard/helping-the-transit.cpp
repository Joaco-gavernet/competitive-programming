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
typedef pair<ll,ll> ii;
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
#define esta(x,v) (v).find(x) != (v).end() 

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


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

void dfs(int v, vector<vi> &g, vb &visto, vi &component, vector<set<int>> &dag) {
  visto[v] = true; 
  for (int u: g[v]) {
    if (component[v] != component[u]) 
      dag[component[v]].insert(component[u]); 
    if (visto[u] == false)
      dfs(u,g,visto,component,dag); 
  }
}

int main(){
  FIN;

  int n, m; cin >> n >> m; 
  vector<vi> g(n); 
  forn(i,m) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
  }

  SCC data(g); 
  int scc = data.scc; 
  vi component = data.component; 

  vb visto(n, false); 
  vector<set<int>> dag(scc, set<int>()); 
  forn(i,n) {
    if (visto[i] == false) 
      dfs(i,g,visto,component,dag); 
  }
  vi out_deg(scc), in_deg(scc); 
  forn(i,scc) {
    out_deg[i] = SZ(dag[i]); 
    for (int u: dag[i]) in_deg[u]++; 
  }
  int outs = 0, ins = 0; 
  for (auto u: out_deg) if (u == 0) outs++; 
  for (auto u: in_deg) if (u == 0) ins++; 
  if (scc <= 1) outs = ins = 0; 
  cout << max(outs, ins) << endl; 

  return 0;
}
