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

ll dfs(int x, vi &l, vi &r, vi &dp) {
  dp[x] = 0; 
  if (l[x] > 0) dp[x] += dfs(l[x], l, r, dp) + 2; 
  if (r[x] > 0) dp[x] += dfs(r[x], l, r, dp) + 2; 
  return dp[x]; 
}

void ifs(int x, vi &l, vi &r, vi &dp, vi &ans, ll act = 0) {
  if (x > 0) (act += dp[x] + 1) %= MOD; 
  ans[x] = act; 
  if (l[x] > 0) ifs(l[x], l, r, dp, ans, act); 
  if (r[x] > 0) ifs(r[x], l, r, dp, ans, act); 
  (act += MOD - (dp[x] + 1)) %= MOD; 
} 

void solve() {
  int n; cin >> n; 
  vi l(n + 1), r(n + 1); 
  forr(i,1,n+1) cin >> l[i] >> r[i]; 
  l[0] = 1; 

  vi dp(n + 1); 
  dfs(0, l, r, dp); 

  vi ans(n + 1); 
  ifs(0, l, r, dp, ans); 

  forr(i,1,n+1) cout << ans[i] << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
