#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n) 
#define pb push_back
#define esta(x,v) ((v).find(x) != (v).end()) 
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"


void solve() {
  int n, m; cin >> n >> m;
  
  vector<vi> g(n), gr(n);
  vi out(n), in(n); 
  forn(i,m) {
    int u, v; cin >> u >> v; 
    g[--u].pb(--v); 
    gr[v].pb(u); 
    out[u]++; in[v]++; 
  }
  vb visto(n, false); 
  set<ii> st; 
  forn(v,n) st.insert({out[v]-in[v], v}); 
  
  while (st.size()) { 
    auto [x, v] = *st.rbegin(); 
    visto[v] = true; 
    st.erase(*st.rbegin()); 
    cout << v +1 << ' '; 
    for (auto u : g[v]) {
      st.erase({out[u]-in[u], u}); 
      in[u]--; 
      if (visto[u] == false) st.insert({out[u]-in[u], u});  
    }
    for (auto u : gr[v]) {
      st.erase({out[u]-in[u], u}); 
      out[u]--; 
      if (visto[u] == false) st.insert({out[u]-in[u], u}); 
    }
  }
  cout << '\n'; 
}

int main() {
  FIN; 
  
  int t; cin >> t; 
  forn(_,t) solve(); 

  return 0; 
}


