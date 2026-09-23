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
  ll n, k, m; cin >> n >> k >> m; 
  string s; cin >> s; 

  vector<vi> dp(m); 
  vi h(k, m); 
  for (int i = m - 1; i >= 0; i--) {
    h[s[i] - 'a'] = i; 
    dp[i] = h; 
  } 

  bool ok = true; 
  string ans = "";
  ll l = -1; 
  while (SZ(ans) < n) {
    ll id = 0; 
    forn(c,k) if (dp[l + 1][id] < dp[l + 1][c]) id = c; 
    if (dp[l + 1][id] == m) {
      while (SZ(ans) < n) ans += 'a' + id; 
      ok = false; 
      break; 
    } else ans += 'a' + id, l = dp[l + 1][id]; 
    if (l + 1 == m) {
      if (SZ(ans) < n) {
        while (SZ(ans) < n) ans += 'a'; 
        ok = false; 
      } 
      break; 
    } 
  } 
  if (ok) cout << "YES\n"; 
  else cout << "NO\n" << ans << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
