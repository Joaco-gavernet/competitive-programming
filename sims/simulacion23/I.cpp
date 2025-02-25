#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = -1;
const int INF = -1;
const int MOD = -1;


typedef ll tipo;
struct arista {
  int x; tipo w;
};

struct nodo {
  tipo d, v, a; 
  bool operator < (const nodo &x) const { return d > x.d; }
}; 

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
  vector<nodo> ans(n); 
  vector<bool> visto(n, false); 
  priority_queue<nodo> p; p.push({0, start, -1}); 
  while (p.size()) {
    nodo it = p.top(); p.pop(); 
    if (visto[it.v]) continue;
    else {
      ans[it.v] = it; visto[it.v] = true; 
      for (arista u : g[it.v]) {
        if (!visto[u.x]) p.push({it.d + u.w, u.x, it.v}); 
      }
    }
  }

  return ans; 
}

ll cont = 0; 
void dfs(int v, int cost, vector<vector<arista>> &g, vb &visto, vector<nodo> &ans) {
  visto[v] = true; 
  forn(i,SZ(g[v])) {
    auto [u, w] = g[v][i]; 
    if (cost < ans[u].d +w) continue; 
    if (cost -w >= 0) cont += w; 
    if (visto[u] == false) dfs(u,cost-w,g,visto,ans); 
  }
}

int main() {
  FIN; 
  
  int n, m, a, b;
  cin >> n >> m >> a >> b; 

  ll tot = 0; 
  vector<vector<arista>> g(n); 
  forn(_,m) {
    int u, v, w;
    cin >> u >> v >> w; 
    tot += w; 
    g[--u].pb({--v, w}); 
    g[v].pb({u, w}); 
  }

  --a, --b; 
  vector<nodo> ans = Dijkstra(a,n,g); 
  vb visto(n, false); 
  ll bestcost = ans[b].d; 
  dfs(b,bestcost,g,visto,ans); 

  cout << tot -cont << endl; 
  
  return 0;
}
