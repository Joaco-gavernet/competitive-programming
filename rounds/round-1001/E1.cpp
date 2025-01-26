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

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)

/*
Tiempo de build: O(nlogn)
Memoria: O(nlogn)
Tiempo por query: O(logn)
*/
const int MAXN = 200005, LOG = 20;  

struct LCA {
  int n, root = 0;  
  vector<vi> g;
  int jmp[MAXN][LOG], depth[MAXN]; // jmp[i][j] tiene el 2^j-esimo ancestro de i
  void lca_dfs(int x) {
    for(int u : g[x]) {
      if(u == jmp[x][0]) continue;
      jmp[u][0] = x; depth[u] = depth[x]+1;
      lca_dfs(u);
    }
  }

  LCA(int tam, vector<vi> &tree): n(tam), g(tree) {
    depth[root] = 0;
    memset(jmp,-1,sizeof(jmp)); jmp[root][0] = root;
    lca_dfs(root);
    forr(k, 1, LOG){ forn(i, n){
      if(jmp[i][k-1]<0) jmp[i][k] = -1;
      else jmp[i][k] = jmp[jmp[i][k-1]][k-1];
    }
    }
  }

  int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
    for(int i = LOG-1; i >= 0; i--) {
      if(depth[x]-(1<<i) >= depth[y]) x = jmp[x][i];
    }
    if(x == y) return x;
    for(int i = LOG-1; i >= 0; i--) {
      if(jmp[x][i] != jmp[y][i]) x = jmp[x][i], y = jmp[y][i];
    }
    return jmp[x][0];
  }

  int dist(int x, int y) { 
    return depth[x] + depth[y] - 2 * depth[lca(x,y)];
  }
};

void solve() {
  int n; cin >> n; 
  vector<ii> w(n); forn(i,n) cin >> w[i].fst, w[i].snd = i; 
  vector<vi> g(n); 
  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    a--; b--; 
    g[a].pb(b); 
    g[b].pb(a); 
  }

  dbg(w); 
  // LCA data(n, g); 

  int ans = -1; 
  int l = n-2, r = n-1; 
  int rep = -1; // TODO: check if needed 
  /*
  while (ans == -1 and l >= 0) {
    auto [ha, a] = w[l]; 
    auto [hb, b] = w[r]; 
    int c = dt.lca(a, b); 

    if (c != a and c != b) ans = a; 
    else {
    } 
  }

  cout << ans +1 << '\n'; 
  */


}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
