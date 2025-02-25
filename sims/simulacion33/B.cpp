#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "======================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

const int MAXN = 3e5+5; 

int start = -1, root = -1; 
vector<vi> g; 
vb visto; 

void dfs(int v, vi &ans, bool &check, int dist = 1) {
  visto[v] = true; 
  ans.pb(v); 
  if (dist >= 2 and check) {
    ans.pb(start); 
    ans.pb(root); 
    check = false; 
  }
  for (auto u: g[v]) {
    if (visto[u]) continue; 
    dfs(u, ans, check, dist+1); 
  }
}

int main() {
  FIN; 

  int n; cin >> n;
  g.resize(n); 
  visto.resize(n); 
  vi deg(n); 
  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
    deg[a]++; 
    deg[b]++; 
  }
  // DBGV(deg,n); cerr << endl; 

  forn(i,n) if (deg[i] == 1) {
    start = i; // soy hoja
    break; 
  }
  root = start; 
  start = g[start][0]; 
  visto[start] = visto[root] = true; 

  vi ans; 
  bool check = true; 
  for (auto u: g[start]) {
    if (visto[u] == false) dfs(u,ans,check); 
  }

  if (check == false) {
    cout << "YES\n"; 
    for (auto x : ans) cout << x +1 << ' ';
    cout << endl; 
  } else cout << "NO\n"; 


  return 0;
}
