#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i< (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define fs first
#define ss second
#define DBG(c) cerr << #c << " = " << c << endl
#define DBGV(v,n) forn(_,n) cerr << v[_] << " "; cerr << endl
#define RAYA cerr << "===================\n"

const int MAXN = -1;
const int INF = -1;
const int MOD = -1;

vector<vi> g;
vi lleft, lright;

void dfs(int v, int prev = -1) {
  //~ DBG(v);
  //~ DBG(prev);
  lleft[v] = lright[v] = 0;
  int u = -1, w = -1;
  
  for (int k : g[v]) {
    if (k == prev) continue;
    if (u == -1) u = k;
    else w = k;
  }
  
  if (u != -1) {
    dfs(u, v);
    lleft[v] = max(lleft[u], lright[u]) +1;
  }
  
  if (w != -1) {
    dfs(w, v);
    lright[v] = max(lleft[w], lright[w]) +1;
  }
  
  if (lleft[v] != lright[v]) {
    int mi = min(lleft[v], lright[v]);
    lleft[v] = lright[v] = mi +1;
  }
}

ll tot = 0;
void dfs2(int v, ll lifes, int prev = -1) {
  //~ if (v == 2) DBG(lifes);
  if (lifes < 0) {
    tot++;
    //~ DBG(v);
  }
  for (int u : g[v]) {
    if (u == prev) continue;
    dfs2(u, min(lifes -1, lleft[v] -1), v);
  }
}

int main() {
  FIN;
  
  int n; cin >> n;
  g.resize(n, vi()); 
  lleft.resize(n); 
  lright.resize(n);
  
  forn(_,n-1) {
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  
  //~ forn(i,n) {
    //~ DBG(i);
    //~ DBGV(g[i], SZ(g[i]));
  //~ }
  
  dfs(0);
  //~ RAYA;
  dfs2(0, lleft[0]);
  
  cout << tot << endl;
  
  return 0;
}
