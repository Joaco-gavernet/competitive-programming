#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


const int MAXN = 2e5+5, LOG = 20;
struct LCA {
  int n, root; 
  vector<vi> g;
  int jmp[MAXN][LOG], depth[MAXN];
  void lca_dfs(int x) {
    for (int u : g[x]) {
      if (u == jmp[x][0]) continue; 
      jmp[u][0] = x; depth[u] = depth[x] + 1;
      lca_dfs(u); 
    }
  }
  LCA(int tam, vector<vi> &tree, int r) : n(tam), root(r), g(tree) {
    depth[root] = 0;
    memset(jmp, -1, sizeof(jmp)); jmp[root][0] = root;
    lca_dfs(root); 
    forr(k, 1, LOG) {
      forn(i,n) {
        if (jmp[i][k-1] < 0) jmp[i][k] = -1; 
        else jmp[i][k] = jmp[jmp[i][k-1]][k-1];
      }
    }
  }
  int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    for (int i = LOG - 1; i >= 0; i--) {
      if (depth[x] - (1<<i) >= depth[y]) x = jmp[x][i];
    }
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
      if (jmp[x][i] != jmp[y][i]) x = jmp[x][i], y = jmp[y][i];
    }
    return jmp[x][0]; 
  }
  int dist(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)]; 
  }
};

int main() {
  FIN;
  ll n,q; cin>>n>>q;
  vector<vi> g(n,vi());
  // RAYA;
  forn(i,n-1){
    ll x,y; cin>>x>>y;
    x--; y--;
    g[x].pb(y);
    g[y].pb(x);
    // DBG(i);
  }
  // RAYA;
  LCA tree(n,g,0);
  forn(i,q){
    ll x,y; cin>>x>>y;
    x--; y--;
    ll ans=n;
    ll len=tree.dist(x,y);
    len++;
    ans=ans+(len*(len-1)/2);
    cout<<ans<<"\n";
  }

  return 0;
}