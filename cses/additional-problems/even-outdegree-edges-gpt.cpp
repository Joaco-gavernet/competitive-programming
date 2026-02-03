#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back

int dfs(int v, vector<vi> &g, vb &visto, vb &done, vii &ans, vi &odeg, set<pair<int,int>> &used, int prev = -1) {
  visto[v] = true; 
  int aux = 0; 

  for (auto u: g[v]) {
    int a = min(u, v), b = max(u, v);
    if (used.count({a, b})) continue;
    used.insert({a, b});

    if (!visto[u]) {
      aux += dfs(u, g, visto, done, ans, odeg, used, v); 
      aux++; 
      if (odeg[u] % 2) ans.pb({u, v}), odeg[u]++; 
      else ans.pb({v, u}), odeg[v]++; 
    } else if (u != prev) {
      ans.pb({v, u}); 
      odeg[v]++; 
    }
  } 

  done[v] = true; 
  return aux; 
} 

int main(){
  FIN;

  int n, m; cin >> n >> m; 
  vector<vi> g(n); 
  forn(i,m) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
  } 

  vii ans; 
  vi odeg(n, 0); 
  vb visto(n), done(n); 
  set<pair<int,int>> used;

  forn(v,n) if (!visto[v]) {
    int tot = dfs(v, g, visto, done, ans, odeg, used, -1); 
    if (tot %2) {
      cout << "IMPOSSIBLE\n"; 
      return 0; 
    } 
  } 

  for (auto [a, b]: ans) cout << a +1 << ' ' << b +1 << '\n'; 
  return 0;
}
