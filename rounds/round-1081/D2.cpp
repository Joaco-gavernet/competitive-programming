#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vector<vi> g(n); 
  forn(i,n-1) {
    int u, v; cin >> u >> v; 
    g[--u].pb(--v); 
  } 

  vi cost(n), costop(n), sum(n), depth(n); 
  function<void(ll)> f = [&](ll x) {
    vector<ii> ops; 
    sum[x] = a[x]; 
    for (auto y : g[x]) {
      f(y); 
      depth[x] = max(depth[x], depth[y] + 1); 
      cost[x] += cost[y] + sum[y]; 
      costop[x] += cost[y] + sum[y]; 
      sum[x] += sum[y]; 
      ops.pb({depth[y] + 1, y}); 
    } 

    sort(all(ops)); 
    dbg(x, ops); 
    ll D = 0; 
    if (SZ(ops)) D = ops.back().ff; 
    dbg(D); 
    dbg(x, cost[x], costop[x], sum[x]); 
    for (auto [d, y]: ops) {
      if (d == D and SZ(ops) > 1) D = ops[SZ(ops) - 2].ff; 
      dbg(y, cost[y], costop[y], sum[y]); 
      costop[x] = max(costop[x], costop[x] - cost[y] + costop[y]); 
      costop[x] = max(costop[x], costop[x] + sum[y] * D - sum[y]); 
    } 
  }; 
  f(0); 

  for (auto x: costop) cout << x << ' '; 
  cout << '\n'; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
