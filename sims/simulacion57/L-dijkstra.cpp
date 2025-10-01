#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define ff first
#define ss second 


const ll INF = 1LL<<60;
typedef long double tipo; 

struct city {
  int x, y; 
};

struct bridge {
  int a, b; 
  ll w; 
};

struct arista {
  int x; tipo w;
};

struct nodo {
  tipo d, v, a;
  bool operator < (const nodo &x) const { return d > x.d; }
};

vector<nodo> Dijkstra(ll start, int n, vector<vector<pair<int, tipo>>> &g) {
  vector<nodo> ans(n);
  vb visto(n, false);
  priority_queue<nodo> p; p.push({0, start, -1}); 
  while (SZ(p)) {
    nodo it = p.top(); p.pop();
    if (visto[it.v]) continue;
    else {
      ans[it.v] = it; visto[it.v] = true; 
      for (auto u: g[it.v]) {
        if (!visto[u.ff]) p.push({it.d +u.ss, u.ff, it.v}); 
      }
    }
  }
  return ans; 
}

bool check(int s, vector<vector<pair<int, tipo>>> &g, int m) {
  const int n = SZ(g); 
  vector<tipo> dist(n, -1); 
  vector<nodo> ans = Dijkstra(s, n, g);
  forn(i,n) if (i != s and ans[i].d > m) return false; 
  return true; 
}

int main() {
  FIN;

  int n, k, m; cin >> n >> k >> m; 
  vector<city> pos(n); forn(i,n) cin >> pos[i].x >> pos[i].y; 
  vector<vector<pair<int, tipo>>> g(n); 
  forn(i,n) {
    int u = (i+1) %n; 
    tipo weight = (pos[u].x -pos[i].x) * (pos[u].x -pos[i].x) + (pos[u].y -pos[i].y) * (pos[u].y -pos[i].y); 
    g[i].pb({u, sqrtl(weight)});
    
    u = (i +n -1) %n; 
    weight = (pos[u].x -pos[i].x) * (pos[u].x -pos[i].x) + (pos[u].y -pos[i].y) * (pos[u].y -pos[i].y); 
    g[i].pb({u, sqrtl(weight)});
  }

  vector<bridge> v(k); forn(i,k) cin >> v[i].a >> v[i].b >> v[i].w, v[i].a--, v[i].b--; 

  ll ans = INF;
  forn(mask,(1<<k)) {
    ll cost = 0; 
    forn(i,10) if (mask&(1<<i)) {
      cost += v[i].w; 
      tipo weight = (pos[v[i].a].x -pos[v[i].b].x) * (pos[v[i].a].x -pos[v[i].b].x) + (pos[v[i].a].y -pos[v[i].b].y) * (pos[v[i].a].y -pos[v[i].b].y); 
      g[v[i].a].pb({v[i].b, sqrtl(weight)});
      g[v[i].b].pb({v[i].a, sqrtl(weight)});
    }

    bool anda = true; 
    forn(i,n) {
      if (check(i, g, m) == false) anda = false; 
    }

    forn(i,10) if (mask&(1<<i)) {
      g[v[i].a].pop_back();
      g[v[i].b].pop_back();
    }
    if (anda) ans = min(ans, cost); 
  }

  cout << ans << '\n'; 

  return 0;
}
