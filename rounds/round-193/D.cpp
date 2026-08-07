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


ll euc(ll p, ll q, ll x, ll y) {
  return (p - x) * (p - x) + (q - y) * (q - y); 
} 

void solve() {
  ll x, y; cin >> x >> y; 
  ll l = 0, r = x + y; 
  while (l + 1 < r) {
    ll mid = (l + r) / 2; 
    if (mid * (mid + 1) / 2 <= x + y) l = mid;
    else r = mid; 
  } 

  const ll L = l * (l + 1) / 2;

  // build all possible ops 
  vector<ii> ops; 
  for (int pi = L - (L - x), qi = L - x; pi >= 0; pi--, qi++) {
    if (pi <= x and qi <= y) ops.pb({pi, qi}); 
    else break; 
  } 

  // find option which minimizes euc distance to (x, y)
  ll P = 0, Q = 0; 
  for (auto [pi, qi] : ops) {
    if (euc(P, Q, x, y) >= euc(pi, qi, x, y)) 
      P = pi, Q = qi; 
  } 

  string ans(l, 'Y'); 
  forn(i,l) if (P - (l - i) >= 0) P -= l - i, ans[i] = 'X'; 
  cout << ans << '\n';
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}


