#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long; 
using vi = vector<ll>; 
using vb = vector<bool>; 
using ii = pair<ll,ll>; 
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second 


// DSU struct con path compression y union por size
// Complejidad: O(ack(n)) por operacion, donde ack(n) es la funcion inversa de Ackermann, casi O(1)
struct DSU {
  vi link, sz, h, c;
  ll mx = 0, tot = 0; 

  DSU(int tam, vi _c) {
    link.resize(tam), sz.resize(tam);
    h.resize(tam); 
    c = _c; 
    tot = tam; 
    forn(i, tam) link[i] = i, sz[i] = 1, h[i] = c[i], mx = max(mx, c[i]); 
  }

  ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }

  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    tot--; 
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    h[a] += h[b];
    mx = max(mx, h[a]); 
    link[b] = a;
  }
};

int main(){  
  NaN;

  int n, m; cin >> n >> m; 
  vi c(n); forn(i,n) cin >> c[i]; 

  DSU ds(n, c); 
  forn(i,m) {
    ll u, v; cin >> u >> v; 
    --u, --v; 
    ds.join(u, v); 
    cout << ds.tot << ' ' << ds.mx << '\n'; 
  } 


  return 0;
}
