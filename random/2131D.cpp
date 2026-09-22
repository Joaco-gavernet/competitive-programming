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


void solve() {
  ll n; cin >> n; 

  vector<vi> g(n); 
  forn(_,n-1) {
    ll u, v; cin >> u >> v; 
    --u, --v; 
    g[u].pb(v); 
    g[v].pb(u); 
  } 

  if (n <= 3) return void(cout << 0 << '\n'); 

  vi dp(n); 
  function<ll(ll, ll)> dfs = [&](ll x, ll prev) -> ll {
    for (auto y : g[x]) if (y != prev) dp[x] += dfs(y, x); 
    if (prev == 0 and SZ(g[0]) == 1) dp[x]++; 
    return SZ(g[x]) == 1; 
  }; 


  dfs(0, -1); 

  ll leaves = 0; 
  forn(i,n) leaves += SZ(g[i]) == 1; 

  ll best = 1ll<<60; 
  forn(x,n) if (SZ(g[x]) > 1) best = min(best, leaves - dp[x]); 
  cout << best << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
