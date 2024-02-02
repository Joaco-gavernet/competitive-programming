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
const int MAXN = (int)(2e5+5);

typedef vector<int> vi;
typedef vector<bool> vb;

// 2sat (2-satisfiability) - O(n + m) (Kosaraju)
struct two_sat { // 2*x representa a x, y 2*x+1 a ~x
  int tot;
  vector<vector<int>> g, g_trans;
  vb used, assignment;
  vector<int> order, comp;

  two_sat(int _tot): tot(_tot){
    g.resize(tot); g_trans.resize(tot);
  } // tot = total de nodos (normales + negados), en general n = tot/2

  void dfs1(int v) {
    used[v] = true;
    for(auto u: g[v]) if(!used[u]) dfs1(u);
    order.pb(v);
  }

  void dfs2(int v, int cl) { // Kosaraju para encontrar las SCC
    comp[v] = cl;
    for(auto u: g_trans[v]) if(comp[u] == -1) dfs2(u, cl);
  }

  bool solve() {
    order.clear(); used.assign(tot, false);
    comp.assign(tot, -1);
    forn(i, tot) if(!used[i]) dfs1(i);

    int comp_act = 0;
    forn(i, tot){
      auto v = order[tot-i-1];
      if(comp[v] == -1) dfs2(v, comp_act++);
    }

    assignment.assign(tot/2, false);
    forn(i, tot/2){
      if(comp[2*i] == comp[2*i + 1]) return false;
      assignment[i] = comp[2*i] > comp[2*i+1]; 
    }
    return true;
  }

  void add_edge(int from, int to){ // implicancia comun from->to
    g[from].pb(to);
    g_trans[to].pb(from); // agregar en el TRANSPUESTO
  }

  void add_or(int v1, int v2) { // agrega (v1 or v2)
    add_edge(v1 ^ 1, v2); // ~v1 -> v2
    add_edge(v2 ^ 1, v1); // ~v2 -> v1
  }
  // setear variable x en true/false: add_or(x, x)/add_or(~x, ~x)
};


int main(){
  FIN;

  int n,m; cin >> n >> m;
  two_sat s(m*2); 

  int x, y;
  char xc, yc;
  string input;
  while (n--) {
    cin >> xc >> x >> yc >> y;
    x--; y--;
    x *= 2; y *= 2;
    if (xc == '-') x ^= 1;
    if (yc == '-') y ^= 1;
    s.add_or(x, y);
  }

  bool possible = s.solve();
  vb ans = s.assignment; 
  dbg(ans);

  if (possible == false) cout << "IMPOSSIBLE\n";
  else {
    for (bool i: ans) {
      if (i == false) cout << "- ";
      else cout << "+ "; 
    }
  }
  
  
  return 0;
}








