#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second


vb visto; 
vector<vi> g;
vector<ii> ans; 
void add_edge(int a, int b) {
  g[a].pb(b); 
  g[b].pb(a); 
}

void dfs(int v, int prev = -1) {
  visto[v] = true; 
  for (auto u: g[v]) if (visto[u] == false) dfs(u, v);
  if (prev != -1) ans.pb({v, prev});
}

int main() {
  FIN;

  int n; cin >> n; 
  char c; cin >> c; 
  vector<string> tab(n); forn(i,n) cin >> tab[i]; 
  vector<ii> v; 
  forn(y,n) {
    forn(x,n) {
      if (tab[y][x] != '.') {
        v.pb({y, x});
      }
    }
  }
  g.resize(SZ(v));
  visto.resize(SZ(v));

  // build graph for each case of piece
  if (c == 'R') {
    forn(i,SZ(v)) {
      forr(j,i+1,SZ(v)) {
        if (v[i].ff == v[j].ff or v[i].ss == v[j].ss) 
          add_edge(i, j);
      }
    }
  } else if (c == 'Q') {
    forn(i,SZ(v)) {
      auto [x, y] = v[i]; 
      forr(j,i+1,SZ(v)) {
        auto [xj, yj] = v[j];
        int dx = abs(x-xj);
        int dy = abs(y-yj);
        if (v[i].ff == v[j].ff or v[i].ss == v[j].ss or dx == dy) 
          add_edge(i, j);
      }
    }
  } else if (c == 'B') {
    forn(i,SZ(v)) {
      auto [x, y] = v[i]; 
      forr(j,i+1,SZ(v)) {
        auto [xj, yj] = v[j];
        int dx = abs(x-xj);
        int dy = abs(y-yj);
        if (dx == dy) 
          add_edge(i, j);
      }
    }
  } else if (c == 'N') {
    forn(i,SZ(v)) {
      auto [x, y] = v[i]; 
      forr(j,i+1,SZ(v)) {
        auto [xj, yj] = v[j];
        int dx = abs(x-xj);
        int dy = abs(y-yj);
        if (dx + dy == 3 and (dx == 1 or dy == 1)) 
          add_edge(i, j);
      }
    }
  } else if (c == 'K') {
    forn(i,SZ(v)) {
      auto [x, y] = v[i]; 
      forr(j,i+1,SZ(v)) {
        auto [xj, yj] = v[j];
        int dx = abs(x-xj);
        int dy = abs(y-yj);
        if (dx <= 1 and dy <= 1) {
          add_edge(i, j);
        }
      }
    }
  }

  dfs(0);
  forn(i,SZ(v)) if (visto[i] == false) {
    cout << "NO" << endl; 
    return 0;
  }

  cout << "YES" << endl; 
  for (auto [x, y]: ans) {
    cout << v[x].ff +1 << " " << v[x].ss +1 << " " << v[y].ff +1 << " " << v[y].ss +1 << endl; 
  }
  
  return 0;
}