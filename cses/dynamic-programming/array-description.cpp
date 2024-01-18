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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


int main(){
  FIN;
  
  int n,m; cin >> n >> m;
  vector<ll> v(n); forn(i,n) cin >> v[i];
  vector<vector<ll>> dp(n, vector<ll>(m+2));
  
  if (v[0] != 0) dp[0][v[0]] = 1;
  else forr(i,1,m+1) dp[0][i] = 1;
  
  forr(i,1,n) {
    if (i < n and v[i] != 0) {
      dp[i][v[i]] = dp[i-1][v[i]-1]%MOD + dp[i-1][v[i]]%MOD + dp[i-1][v[i]+1]%MOD;
      dp[i][v[i]] %= MOD;
    } else {
      forr(j,1,m+1) {
	dp[i][j] = dp[i-1][j-1]%MOD + dp[i-1][j]%MOD + dp[i-1][j+1]%MOD;
	dp[i][j] %= MOD;
      }
    }
  }
  
  //~ forn(i,n) dbg(dp[i]);
  //~ forr(i,n-2,n) dbg(dp[i]);
  
  if (v[n-1] != 0) {
    dbg("aca");
    cout << dp[n-1][v[n-1]]%MOD << '\n';
  }
  else {
    cout << accumulate(all(dp[n-1]),0LL)%MOD << '\n';
  }
  
  return 0;
}





