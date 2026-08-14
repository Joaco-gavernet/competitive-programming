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
  int n; cin >> n;
  vector<string> v(2); forn(i,2) cin >> v[i]; 

  string path;
  path += v[0][0]; 
  int c = 1; 
  while (c < n and (v[0][c] == '0' or (v[0][c] == '1' and v[1][c - 1] == '1'))) path += v[0][c++]; 
  path += v[1][c-1]; 
  while (c < n) path += v[1][c++]; 

  vector<vi> dp(2, vi(n)); 
  dp[0][0] = 1; 
  forr(i,1,n) {
    if (v[0][i] == path[i]) dp[0][i] += dp[0][i-1]; 
    if (v[1][i-1] == path[i]) dp[1][i-1] += dp[0][i-1] + (i - 2 >= 0 ? dp[1][i-2] : 0LL); 
  } 

  cout << path << '\n'; 
  cout << dp[0][n-1] + dp[1][n-2] << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
