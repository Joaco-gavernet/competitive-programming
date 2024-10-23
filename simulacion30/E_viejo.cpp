#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "=================================\n"

void dfs(int v, vector<vi> &g, vb &visto, vi &depth, int act) {
  visto[v] = true; 
  depth[v] = act; 
  for (auto u : g[v]) {
    if (visto[u] == false) dfs(u, g, visto, depth, act +1); 
  }
}

int BFS(int mi, int mx, vector<vi> &g) {
  // RAYA; 
  // DBG(mi); 
  // DBG(mx); 
  const int n = SZ(g);
  queue<int> q; 
  q.push(mi); q.push(mx); 
  vi visto(n, -1); 
  visto[mi] = mi; 
  visto[mx] = mx; 
  vi steps(n, 0); 
  // RAYA; 
  while (q.size()) {
    int v = q.front(); q.pop(); 
    // DBG(v); 
    for (auto u : g[v]) {
      if (visto[u] != -1) {
        if (visto[u] == visto[v]) continue; 
        else {
          if (steps[u] == steps[v] +1) return u; 
          else return -1; 
        }
      }
      visto[u] = visto[v]; 
      steps[u] = steps[v] +1; 
      q.push(u); 
    }
  }
  return -1; 
}

bool BFS2(int start, unordered_set<int> &cities, vector<vi> &g) {
  queue<int> q; q.push(start); 
  const int n = SZ(g); 
  vb visto(n, false); 
  visto[start] = true; 
  while (q.size()) {
    auto v = q.front(); q.pop(); 
    if (esta(cities,v) == true) {
      for (auto x : cities) {
        if (visto[x] == false) return false; 
      }
      return true; 
    }
    for (auto u : g[v]) {
      if (visto[u] == false) {
        visto[u] = true; 
        q.push(u); 
      }
    }
  }
  return false; 
}

int main() {
  FIN; 

  int n, m; cin >> n >> m; 
  vector<vi> g(n); 
  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
  }
  vi cities(m); forn(i,m) cin >> cities[i], cities[i]--; 

  vb visto(n,false); 
  vi depth(n,-1); 
  dfs(0,g,visto,depth,0); 

  /*
  DBGV(depth,n);
  cerr << endl; 
  RAYA; 
  DBGV(cities,m);
  cerr << endl; 
  RAYA; 
  */

  // chequeo caso trivial (raiz como respuesta) 
  int i = 1; 
  while (i < m) {
    if (depth[cities[i]] != depth[cities[i-1]]) break; 
    if (i == m-1) {
      cout << "YES\n";
      cout << "1\n"; 
      return 0; 
    }
  }

  // busco nodo intermedio
  int mi = 0, mx = 0; 
  forr(i,1,m) {
    if (depth[cities[i]] < depth[cities[mi]]) mi = i; 
    if (depth[cities[i]] > depth[cities[mx]]) mx = i; 
  }
  // DBG(mi); 
  // DBG(mx); 

  int best = BFS(cities[mi], cities[mx], g); 
  // DBG(best); 
  if (best == -1) {
    cout << "NO\n"; 
    return 0; 
  }

  // chequear si best es una respuesta posible para cada otra ciudad
  unordered_set<int> set_cities(all(cities)); 
  bool ok = BFS2(best, set_cities, g); 
  if (ok) cout << "YES\n" << best +1 << '\n'; 
  else cout << "NO\n"; 

  return 0; 
}
