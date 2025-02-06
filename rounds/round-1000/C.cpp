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
#define esta(x,v) (v).find(x) != (v).end() 

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


ii attempt(const int n, vector<set<int>> &g, int dif = -1) {
  int mx = n; 
  forn(i,n) if (i != dif and SZ(g[i]) >= SZ(g[mx])) mx = i; 
  assert(mx != n); 
  ll tot = SZ(g[mx]); 

  ll sz2 = 0; 
  forn(i,n) if (i != mx and i != dif) {
    ll sz = SZ(g[i]) -int(esta(mx, g[i])); // adds O(log n) that could be avoided preprocessing parents and checking in O(1) 
    if (sz > sz2) sz2 = sz;
  } 
  tot += sz2 -1; 

  assert(tot != -1); 
  return {tot, mx}; 
} 

void solve() {
  int n; cin >> n; 
  vector<set<int>> g(n +1); 
  forn(_,n-1) {
    int u, v; cin >> u >> v; 
    g[--u].insert(--v); 
    g[v].insert(u); 
  } 

  auto [a, mx] = attempt(n,g); 
  auto [b, mx2] = attempt(n,g,mx); 
  cout << max(a, b) << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
