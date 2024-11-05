#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

const int MAXN = 1e4+5; 

ii ans = {0,0}; 
int n = -1; 
vb visto(MAXN); 
vector<vi> g(MAXN); 
vi subtree(MAXN, 0); 

void dfs(int v) {
  visto[v] = true; 
  vi childs; 
  for (auto u : g[v]) {
    if (visto[u] == true) continue; 
    dfs(u); 
    childs.pb(subtree[u]); 
    subtree[v] += subtree[u]; 
  }
  ll act = 0; 
  childs.pb(n-subtree[v]-1); 
  for (auto k : childs) act += k*(n-k-1); 
  act /= 2; 
  if (act > ans.first) {
    sort(all(childs)); reverse(all(childs)); 
    ans = {act, act}; 
    if (SZ(childs) > 0) {
      ans.second -= childs[0]*childs[1];
    }
  }
  subtree[v]++; 
}

int main() {
  FIN; 

  int m; cin >> m; 
  n = m +1; 
  forn(_,m) {
    int a, b; cin >> a >> b; 
    g[a].pb(b); 
    g[b].pb(a); 
  }

  dfs(0); 
  cout << ans.first << ' ' << ans.second << '\n'; 


  return 0;
}
