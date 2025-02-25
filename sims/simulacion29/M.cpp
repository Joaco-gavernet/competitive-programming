#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);



struct node {
  bool heavy; 
  ll lazy; 
  vi adj; 
  vi hadj; 
  node() : heavy(false), lazy(0), adj(vi()) {}
}; 

ostream &operator << (ostream &os, const node v) {
  return os << '(' << v.heavy << ',' << v.lazy << ',' << v.adj << ',' << v.hadj << ')'; 
}

int main(){
  FIN;

  int n, m; cin >> n >> m; 
  vi val(n); forn(i,n) cin >> val[i]; 
  vector<vi> _g(n); 
  vector<node> g(n);
  vi deg(n); 
  forn(_,m) {
    int a, b; cin >> a >> b; 
    _g[--a].pb(--b); 
    _g[b].pb(a); 
    deg[a]++; deg[b]++; 
  }

  forn(i,n) if (deg[i]*deg[i] >= n) g[i].heavy = true; 
  forn(i,n) {
    for (auto u: _g[i]) {
      if (g[u].heavy) g[i].hadj.pb(u); 
      else g[i].adj.pb(u); 
    }
  }

  int q; cin >> q; 
  while (q--) {
    int op,v,x; cin >> op >> v; 
    v--; 
    if (op == 1) {
      cin >> x; 
      if (g[v].heavy) g[v].lazy += x; 
      else {
        for (auto u: g[v].adj) val[u] += x; 
        for (auto u: g[v].hadj) val[u] += x; 
      }
    } else {
      ll ans = val[v]; 
      for (auto u: g[v].hadj) ans += g[u].lazy; 
      cout << ans << '\n'; 
    }
  }


  return 0;
}
