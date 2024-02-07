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
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const ll LOG = 20; // check ???????????????????????????
const int MAXN = 2e5+5;

#define SZ(x) int((x).size())
typedef vector<int> vi;
typedef vector<bool> vb;

struct SCC {
  int n, scc;
  vector<vi> g, gr, ans;  
  vb visto;
  vi order, comp_act, component, cdx, toCycle; 
  // cdx = "index of node inside cycle"
  // toCycle = "distance from any node to nearest cycle"

  SCC(vector<vi> &_g): n(SZ(_g)) {
    g = _g;
    gr.resize(n), visto.resize(n), component.resize(n), cdx.resize(n,-1), toCycle.resize(n,-1);
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
    cdx[v] = comp_act.size();
    comp_act.pb(v);
    for (int u : gr[v]) if(!visto[u]) DFS2(u);
  }

  int DFS3 (int v) {
    if (ans[component[v]].size() > 1 or g[v][0] == v) {
      toCycle[v] = 0; 
      return 0;
    }
    if (toCycle[v] != -1) return toCycle[v];

    toCycle[v] = (DFS3(g[v][0]) +1);
    return toCycle[v];
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

  void distanceToCycle() {
    forn(i,n) if (toCycle[i] == -1) DFS3(i);
  }
};

int log2(int x) {
  return sizeof(int)*8 -1 -__builtin_clz(x);
}

int main(){
  FIN;

  // Observations: 
  // 1. We are given a functional graph. 
  // 2. There are 3 possible cases:
  //   - case 1: both in cycle
  //   - case 2: both in tree
  //   - case 3: one in each

  int n,q; cin >> n >> q;
  vector<vi> g(n); 
  forn(i,n) { 
    int a; cin >> a; 
    g[i].pb(--a);
  }

  SCC s(g);

  vi comp = s.component;
  vi cdx = s.cdx; 
  vector<vi> ans = s.ans;
  dbg(comp);
  forn(i,ans.size()) dbg(i,ans[i]);

  // preprocessing distance from every node to the cycle
  s.distanceToCycle();
  vi toCycle = s.toCycle;
  dbg(toCycle);

  RAYA;

  // preprocessing sparse table (cases 2 and 3)
  vector<int> t(MAXN*LOG, INF); // sparse table in 1D to avoid double indirection
  forn(i,n) t[i*LOG] = g[i][0];
  for(int j = 1; j < LOG; j++) {
    forn(i,MAXN) {
      if (t[i*LOG + j-1] == INF) t[i*LOG + j] = INF;
      else t[i*LOG + j] = t[t[i*LOG + j-1]*LOG + j-1];
    }
  }

  while (q--) {
    int a,b; cin >> a >> b;
    a--; b--;
    dbg(a,b);

    int dist = -1;
    if (a == b) dist = 0;
    else if (comp[a] == comp[b]) { // both in cycle
      dbg("case 1");
      // compare a's and b's index in cycle
      if (cdx[a] > cdx[b]) dist = cdx[a]-cdx[b];
      else dist = ans[comp[a]].size() + cdx[a]-cdx[b];
    } 

    else if (ans[comp[a]].size() == 1 and ans[comp[b]].size() == 1) { // both in tree
      dbg("case 2");
      // start from a and b using sparse table to search for cycle 
      if (toCycle[a] < toCycle[b]) dist = -1;
      else {
        // binary lifting to check if starting from a we can reach b
        int x = a, k = toCycle[a] - toCycle[b];
        if (k != 0) {
          dist = 0;
          int j = log2(k);
          k -= (1<<j);
          while (k > 0) {
            x = t[x*LOG +j];
            j = log2(k);
            k -= (1<<j);
          }
          dbg(dist);
          if (t[x*LOG +j] == b) dist = toCycle[a] - toCycle[b];
          else dist = -1;
        }
      }
    } 

    else if (ans[comp[a]].size() == 1 and ans[comp[b]].size() > 1) { // one in each
      dbg("case 3");
      // search for starting of cycle and check if same cycle as b
      int x = a, k = toCycle[a];
      int j = log2(k);
      k -= (1<<j);
      while (k > 0) {
        x = t[x*LOG +j];
        j = log2(k);
        k -= (1<<j);
      }
      if (comp[t[x*LOG +j]] == comp[b]) {
        // if true, then consider distance to cycle and distance inside cycle
        dist = 0;
        if (g[a][0] != a) {
          dist += toCycle[a];
          if (cdx[t[x*LOG +j]] > cdx[b]) dist += cdx[t[x*LOG +j]]-cdx[b];
          else dist += ans[comp[b]].size() + cdx[t[x*LOG +j]]-cdx[b];
        }
      } else dist = -1;
    } 
    cout << dist << '\n';
  }

  return 0;
}










