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

void BFS(int start, vector<vi> &g, vi &dists) {
  const int n = SZ(g);
  queue<int> q; q.push(start);
  vb visto(n, false); 
  visto[start] = true; 
  dists[start] = 0; 

  while (q.size()) {
    int v = q.front(); q.pop(); 
    for (auto u : g[v]) {
      if (visto[u] == true) continue; 
      visto[u] = true; 
      dists[u] = dists[v] +1; 
      q.push(u); 
    }
  }
}

bool check(vi dists, vi cities) {
  int i = 1; 
  const int m = SZ(cities); 
  while (i < m) {
    if (dists[cities[i]] != dists[cities[i-1]]) return false;  
    i++; 
  }
  return true; 
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
  
  if (m == 1) {
    cout << "YES\n"; 
    cout << *cities.begin() +1 << '\n'; 
    return 0; 
  }

  vb visto(n,false); 
  vi depth(n,-1); 
  BFS(0,g,depth); 

  // caso trivial (respuesta la raiz) 
  int i = 1; 
  while (i < m) {
    if (depth[cities[i]] != depth[cities[0]]) break; 
    if (i == m-1) {
      cout << "YES\n"; 
      cout << "1\n"; 
      return 0; 
    }
    i++; 
  }

  // busco nodo intermedio
  int mi = 0, mx = 0; 
  forr(i,1,m) {
    if (depth[cities[i]] < depth[cities[mi]]) mi = i; 
    if (depth[cities[i]] > depth[cities[mx]]) mx = i; 
  }
  int cmi = cities[mi];
  int cmx = cities[mx];

  vi mi_dists(n, -1), mx_dists(n, -1); 
  BFS(cmi, g, mi_dists); 
  BFS(cmx, g, mx_dists); 

  // chequear si existe una ciudad a la misma distancia de ambas
  int best = -1; 
  forn(i,n) {
    if (i == cmi or i == cmx) continue; 
    if (mi_dists[i] == mx_dists[i]) {
      if (best == -1 or mi_dists[i] < mi_dists[best]) best = i; 
    }
  }
  
  if (best == -1) {
    cout << "NO\n"; 
    return 0; 
  }

  vi dists(n, -1); 
  BFS(best, g, dists); 

  if (check(dists, cities)) cout << "YES\n" << best +1 << '\n'; 
  else cout << "NO\n"; 

  return 0; 
}

