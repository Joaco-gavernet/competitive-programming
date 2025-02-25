#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> pi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define SZ(x) int((x).size())
#define fs first
#define ss second

const int INF = -1;
const int MAXN = 2e5+5;
const int MOD = -1;


void dfs(int v, vector<vi> &g, vb &visto) {
  visto[v] = true;
  for (int u : g[v]) 
    if (visto[u] == false) 
      dfs(u, g, visto);
}

void init(int t, vector<vi> &g, vb &ans) {
  for (int u : g[t]) {
    ans[u] = true;
  }
}

int main() {
  FIN;
  
  int n, m, t; cin >> n >> m >> t;
  
  vector<vi> g(n);
  vector<pi> aristas(m);
  vb visto(n), ans(n);

  forn(i,m) {
    int a, b; cin >> a >> b;
    g[b].pb(a);
    aristas[i] = {b,a};
  }

  dfs(t, g, visto); // marco vistos
  init(t, g, ans); // marco adyacentes directos a t

  // chequeo todas las aristas
  for (auto [x,y] : aristas) {
    if (visto[x] and ans[y] and x != t) 
      ans[y] = false;
  }

  vi toprint;
  forn(i,n) if (ans[i]) toprint.pb(i);
  
  cout << SZ(toprint) << "\n";
  sort(all(toprint));
  for (int u : toprint) cout << u << "\n";
  
  return 0;
}




