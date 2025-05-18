#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


ll events = 0; 
unordered_map<int,int> in, out, k;
map<int, vi> apps; 

void dfs(int v, vector<vi> &g) {
  in[v] = events++; 
  apps[k[v]].pb(in[v]); 

  for (auto &u: g[v]) dfs(u, g);

  out[v] = events++; 
}

int main() {
  FIN; 
  
  int n, q; cin >> n >> q;
  forn(i,n) cin >> k[i]; 
  
  vector<vi> g(n); 
  forn(_,n-1) {
    int a, b; cin >> a >> b;
    g[--a].pb(--b);
  }

  dfs(0, g); 

  // DBG(events); 
  // for (auto &[k, v]: apps) {
  //   DBG(k);
  //   for (auto &z: v) cerr << z << ' ';
  //   cerr << '\n'; 
  // }

  // RAYA; 
  forn(_,q) {
    int x, K; cin >> x >> K; x--;
    // cerr << x << ' ' << K << '\n'; 
    // binsearch fst and lst
    // DBG(in[x]);
    // DBG(out[x]); 
    auto fst = lower_bound(all(apps[K]), in[x]); 
    auto lst = upper_bound(all(apps[K]), out[x]); 
    // DBG(fst -apps[K].begin());
    // DBG(lst -apps[K].begin());
    cout << lst - fst << '\n'; 
    // RAYA; 
  }

  return 0; 
}