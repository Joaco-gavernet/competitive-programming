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


const ll INF = 1LL<<60; 

void solve() {
  ll n, k; cin >> n >> k; 
  vi dp(n); forn(i,n) cin >> dp[i]; 
  vi p(k); forn(i,k) cin >> p[i], dp[--p[i]] = 0; 

  vi w(n), in(n); 
  vector<vi> g(n); 
  forn(i,n) {
    ll m; cin >> m; 
    if (m == 0) w[i] = INF; 
    vi e(m); forn(j,m) cin >> e[j], w[i] += dp[--e[j]]; 
    forn(j,m) g[e[j]].pb(i); 
    in[i] = m; 
  } 

  priority_queue<ii, vector<ii>, greater<ii>> pq; 
  forn(i,n) if (dp[i] == 0 or in[i] == 0) pq.push({dp[i], i}); 

  while (SZ(pq)) {
    auto [k, x] = pq.top(); pq.pop(); 

    ll mn = min(dp[x], w[x]);  
    for (auto y : g[x]) {
      if (--in[y] == 0 and dp[y] > 0) pq.push({dp[y], y}); 
      w[y] -= dp[x]; 
      w[y] += mn; 
    } 
    dp[x] = mn; 
  } 

  forn(i,n) cout << dp[i] << ' '; 
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
