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
  string s, t; cin >> s >> t; 
  s = '$' + s;
  t = '?' + t;
  const int n = SZ(s), m = SZ(t); 

  vector<vi> dp(n, vi(m)); 
  if (s[0] == t[0]) dp[0][0] = 1; 
  forr(x,1,m) dp[0][x] = max(dp[0][x-1], ll(s[0] == t[x]));
  forr(y,1,n) dp[y][0] = max(dp[y-1][0], ll(s[y] == t[0]));

  forr(y,1,n) {
    forr(x,1,m) {
      if (s[y] == t[x]) dp[y][x] = dp[y-1][x-1] +1;
      else dp[y][x] = max(dp[y-1][x], dp[y][x-1]); 
    } 
  } 

  string ans; 
  int y = n-1, x = m-1;
  while (y > 0 and x > 0) {
    if (dp[y][x] == dp[y-1][x]) y--; 
    else if (dp[y][x] == dp[y][x-1]) x--; 
    else ans.pb(s[y]), y--, x--; 
  }

  reverse(all(ans)); 
  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
