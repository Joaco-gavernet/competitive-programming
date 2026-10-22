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
  string a; cin >> a;
  string b; cin >> b; 

  const ll n = SZ(a);
  const ll m = SZ(b);

  vi pa(n + 1); forn(i,n) pa[i + 1] = (pa[i] + (a[i] - '0')) % 10; 
  vi pb(m + 1); forn(i,m) pb[i + 1] = (pb[i] + (b[i] - '0')) % 10; 

  if (pa.back() != pb.back()) return void(cout << -1 << '\n'); 

  // find LCS 
  vector<vi> dp(n + 1, vi(m + 1)); 
  forr(i, 1, n + 1) {
    forr(j, 1, m + 1) {
      if (pa[i] == pb[j]) dp[i][j] = dp[i - 1][j - 1] + 1; 
      dp[i][j] = max(dp[i][j], dp[i - 1][j]); 
      dp[i][j] = max(dp[i][j], dp[i][j - 1]); 
    } 
  } 

  cout << dp[n][m] << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
