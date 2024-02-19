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
const int MAXN = 200;
#else
#define dbg(...)
const int MAXN = 200005; 
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


const int LOG = 20;

struct LCA {
  int n, root;
  vector<vector<int>> g;
  int jmp[MAXN][LOG], depth[MAXN]; // jmp[i][j] tiene el 2^j-esimo ancestro de i

  void lca_dfs(int x) {
    for(int u : g[x]) {
      if(u == jmp[x][0]) continue;
      jmp[u][0] = x; depth[u] = depth[x]+1;
      lca_dfs(u);
    }
  }

  LCA(int tam, vector<vector<int>> &tree, int r): n(tam),root(r),g(tree) {
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

void dfs1(vector<vector<int>> &g, vector<int> &par, int v, int prev = -1) {
  par[v] = prev;
  for(int u: g[v]) if (u != prev) dfs1(g,par,u,v);
}

void dfs2(vector<vector<int>> &g, vector<int> &ans, int v, int prev = -1) {
  for(int u: g[v]) {
    if (u != prev) {
      dfs2(g,ans,u,v);
      ans[v] += ans[u];
    }
  }
}


int main(){
  FIN;

  // Use idea of preffix sum in tree. 
  // Find LCA between nodes. a[l]++ a[r]++ a[c]-- a[par[c]]--
  int n,q; cin >> n >> q;
  vector<vector<int>> g(n);
  vector<int> par(n); // parent for each node O(1)
  par[0] = -1;

  int a,b;
  forn(i,n-1) {
    cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
  }
  dfs1(g,par,0); // dfs to search for parents

  LCA s(n,g,0);
  vector<int> preffix(n,0);

  while (q--) {
    int l,r; cin >> l >> r;
    l--; r--;
    preffix[l]++; preffix[r]++;
    int c = s.lca(l,r);
    preffix[c]--;
    if (par[c] != -1) preffix[par[c]]--;
  }

  // compute answer for each node i based on preffix[i]
  dfs2(g,preffix,0);
  for (auto i: preffix) cout << i << ' ';
  cout << '\n';

  return 0;
}
