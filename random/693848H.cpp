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


const ll MOD = 1e9+7; 


void dfs(int x, vector<vector<ii>> &g, vector<ii> &par, vi &dp, int prev) {
  dp[x] = 1;
  for (auto [y, w] : g[x]) if (y != prev) {
    dfs(y, g, par, dp, x); 
    par[y] = {x, w}; 
    dp[x] += dp[y]; 
  }
} 

struct edge {
  ll x, y, w; 
}; 

void solve() {
  ll n, q; cin >> n >> q; 

  vector<vector<ii>> g(n); 
  vector<edge> edg; 
  forn(i,n-1) {
    ll a, b, w; cin >> a >> b >> w; 
    --a, --b; 
    g[a].pb({b, w});
    g[b].pb({a, w}); 
    edg.pb({a, b, w});
  } 

  vector<ii> par(n, {-1, 0}); 
  vi dp(n); 
  dfs(0, g, par, dp, -1); 

  // find initial total sum S
  ll S = 0; 
  forr(i,1,n) {
    S += ((n - dp[i]) * dp[i] % MOD) * par[i].ss;
    S %= MOD; 
  }

  forn(i,q) {
    ll id, nw; cin >> id >> nw; 
    id--; 
    auto [a, b, w] = edg[id]; 
    if (par[a].ff == b) swap(a, b); 
    assert(par[b].ff == a); 
    S = (S - (((n - dp[b]) * dp[b] % MOD) * w) % MOD + MOD) % MOD;
    S += ((n - dp[b]) * dp[b] % MOD) * nw;
    edg[id].w = nw; 
    S %= MOD; 
    cout << S << '\n'; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
