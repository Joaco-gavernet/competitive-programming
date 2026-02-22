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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "======================\n"

map<vi, int> mp; 
map<int, vi> mpr; // to debug

bool dfs(int z, vb &visto, vector<vi> &g, vector<ii> &aux, map<ii, ii> &id) {
  // cerr << z << " = "; 
  // for (auto x: mpr[z]) cerr << x << ' ';
  // cerr << '\n'; 
  visto[z] = true; 
  if (z == 0) return true; 
  for (auto f: g[z]) if (visto[f] == false) {
    if (dfs(f, visto, g, aux, id)) {
      aux.pb(id[{z, f}]); 
      return true; 
    } 
  }
  return false; 
}; 

int main() {
  FIN;

  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vector<ii> ans; 

  auto op = [](vi &a, int i, int j) {
    ll aux[] = {a[i], a[i+1], a[i+2]}; 
    if (i < j) for (int k = i + 3; k <= j + 2; k++) a[k-3] = a[k]; 
    else for (int k = i - 1; k >= j; k--) a[k+3] = a[k]; 
    forn(k,3) a[j + k] = aux[k]; 
  }; 

  forn(i, n - 5) {
    int pos = -1; 
    forn(j,n) {
      if (a[j] == i + 1) {
        pos = j;
        break;
      }
    }
    // DBG(pos);
    // for (auto x: a) cerr << x << ' ';
    // cerr << '\n'; 

    if (n - 2 <= pos){
      op(a, n-3, i);
      pos=i+pos-(n-3);
      ans.pb({n-3,i});
    }
    op(a, pos, i); 
    ans.pb({pos, i}); // TO-DO: check if makes sense 
  }

  // up to this point we have everything sorted but a[n-5 ... n-1] 
  // for (auto x: a) cerr << x << ' ';
  // cerr << '\n'; 
  // RAYA; 

  // build graph of all possible permutations
  vi v(5);
  iota(all(v), 1); 

  do {
    mp[v] = SZ(mp); 
    mpr[mp[v]] = v; 
    // cerr << mp[v] << " = "; 
    // forn(i, 5) cerr << v[i] << ' ';
    // cerr << '\n'; 
  } while (next_permutation(all(v))); 
  
  iota(all(v), 1); 
  vector<vi> g(125); 
  map<ii, ii> id; 
  do {
    int ib = mp[v], ic = -1; 
    vector<ii> p = {{0, 1}, {0, 2}, {1, 2}, {1, 0}, {2, 0}, {2, 1}}; 
    for (auto [l, r]: p) {
      vi c(all(v)); 
      op(c, l, r);
      ic = mp[c]; 
      id[{ib, ic}] = {l, r}; 
      g[ib].pb(ic);
    }
  } while (next_permutation(all(v))); 

  // DBG("debug"); 
  // vi vec = {102}; 
  // for (auto x: vec) {
  //   cerr << x << " = "; 
  //   for (auto u: mpr[x]) cerr << u << ' ';
  //   cerr << '\n';
  //   for (auto y: g[x]) {
  //     cerr << y << " = "; 
  //     for (auto u: mpr[y]) cerr << u << ' ';
  //     cerr << '\n'; 
  //   }
  // }
  // RAYA; 

  // quiero llegar desde el estado u al estado 0 
  vb visto(125); 
  vector<ii> aux; 

  vi u(5); 
  forn(i,5) u[i] = a[n-5+i] - n + 5; 
  // DBG(mp[u]); 
  // for (auto x: u) cerr << x << ' ';
  // cerr << '\n'; 
  dfs(mp[u], visto, g, aux, id); 

  cout << SZ(ans) + SZ(aux) << '\n'; 
  for (auto [l, r]: ans) cout << l + 1 << ' ' << r + 1 << '\n'; 
  reverse(all(aux)); 
  for (auto [l, r]: aux) cout << l + 1 + (n - 5) << ' ' << r + 1 + (n - 5) << '\n'; 

  return 0; 
}