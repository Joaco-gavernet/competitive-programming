#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


struct arista {
  int u, v;
  ll w;
  bool operator<(const arista& other) const { return w < other.w; }
};
struct DSU {
  vi link, sz;

  DSU(int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i, tam+5) link[i] = i, sz[i] = 1;
  }

  ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }

  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
  }
};

vector<arista> kruskal(int n, vector<arista> &g) {
  sort(all(g)); DSU dsu(n);
  vector<arista> mst;
  for(arista e : g) {
    if(!dsu.same(e.v, e.u)){
      dsu.join(e.v, e.u); mst.pb(e);
    }
  }
  return mst;
}


int main(){
  NaN;

  ll n; cin >> n; 
  vi x(n), y(n); 
  forn(i,n) cin >> x[i] >> y[i]; 
  vi c(n), k(n);
  forn(i,n) cin >> c[i]; 
  forn(i,n) cin >> k[i]; 

  auto man = [&](ll i, ll j) -> ll {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]); 
  }; 

  vector<arista> edg; 
  forn(i,n) forr(j,i+1,n) edg.pb({i, j, man(i, j) * (k[i] + k[j])}); 
  forn(i,n) edg.pb({i, n, c[i]}); 

  vector<arista> mst = kruskal(n + 1, edg); 

  ll tot = 0; 
  vi C; 
  vector<ii> par; 
  for (auto [x, y, w] : mst) {
    if (y == n) C.pb(x); 
    else par.pb({x, y}); 
    tot += w; 
  } 
  cout << tot << '\n'; 
  cout << SZ(C) << '\n'; 
  sort(all(C)); 
  for (auto x : C) cout << x + 1 << ' ';
  cout << '\n'; 
  cout << SZ(par) << '\n';
  for (auto [x, y] : par) cout << x + 1 << ' ' << y + 1 << '\n'; 

  return 0;
}
