#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(c) int((c).size())
#define pb push_back
#define DBG(v) cerr << #v << " = " << v << endl;
#define RAYA cerr << "==========================" << endl;


typedef ll tipo;
const int MAXN = 2e5;

struct arista {
  ll x; tipo w;
};

struct nodo {
  tipo d, v, a;
  bool operator < (const nodo &x) const { return d > x.d; }
};

vector<nodo> Dijkstra (int start, int n, vector<vector<arista>> &g) {
  vector<nodo> ans(n);
  vb visto(n, false); 
  priority_queue<nodo> p; p.push({0, start, -1});
  while (!p.empty()) {
    nodo it = p.top(); p.pop();
    if (visto[it.v]) continue;
    else {
      ans[it.v] = it; visto[it.v] = true;
      for (arista u : g[it.v]) {
	if (!visto[u.x]) p.push({it.d +u.w, u.x, it.v});
      }
    }
  }
  
  return ans;
}


int main() {
  FIN; 
  
  int n, s, lower, upper; 
  cin >> n >> s >> lower >> upper;
  
  vector<vector<arista>> ga(n);
  forn(k,s) {
    int i, j, w; cin >> i >> j >> w;
    ga[i].pb({j,w});
    ga[j].pb({i,w});
  }
  
  vector<nodo> ans = Dijkstra(0,n,ga);
  set<ii> st;
  upper = (upper+1)/2;
  
  forn(v,n) {
    if (ans[v].d < upper) {
      for (auto [u, w] : ga[v]) {
	if (v > u) st.insert({u,v});
	else st.insert({v,u});
      }
    }
  }
  
  cout << st.size() << endl;
  
  
  return 0;
}









