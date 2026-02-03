#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)


int nan() {
  cout << "impossible\n";
  return 0;
}


int main() {
  FIN;

  int n; cin >> n;
  vi a(n), b(n); 
  forn(i,n) cin >> a[i]; 
  vector<ii> pq; 
  forn(i,n) {
    cin >> b[i]; 
    if (a[i] + b[i]) pq.pb({a[i] + b[i], i});
    else return nan();
  }
  
  // checks
  if (n == 1) {
    if (a[0] or b[0]) cout << "impossible\n";
    else cout << "1 0\n"; 
    return 0; 
  }

  int A = 0, B = 0;
  forn(i,n) A += a[i];
  forn(i,n) B += b[i];
  if (A != B) return nan();

  // greedy for first version of the graph
  vector<vi> g(n);
  while (SZ(pq)) {
    auto [wz, iz] = pq.top(), pq.pop();
    for (auto &[w, i]: pq) {
      w--, wz--;
      g[iz].pb(i);
      g[i].pb(iz);
      if (wz == 0) break;
    }
  }

  // cerr << "graph debug: " << '\n';
  // forn(v,n) {
  //   cerr << v << ": ";
  //   for(auto u: g[v]) cerr << u << ' ';
  //   cerr << '\n';
  // }
  // RAYA; 

  // fix random direction for each edge
  vb visto(n);
  vector<vi> dir(n);
  auto dfs = [&](int v, vb &visto, vector<vi> &g) {
    visto[v] = true; 
    for (auto u: g[v]) if (visto[u] == false) {
      if (a[v] == 0 and a[u] == 0) return nan();

      if (a[v] == 0 and a[u] > 0) valid.pb({u, v}); 
      if (a[v] > 0 and b[u] > 0) valid.pb({v, u}); 
      else if (a[v] <= 0) exceed.pb({v, u}); 
      else if (b[u] <= 0) need.pb({v, u}); 
      dir[v].pb(u); 
      dfs(u, visto, g); 
    }
  }; 
  dfs(0, visto, g);

  cout << n << ' ' << (A + B) /2 << '\n'; 
  forn(i,n) forn(j,g[i]) cout << i +1 << ' ' << j +1 << '\n';

  return 0;
}