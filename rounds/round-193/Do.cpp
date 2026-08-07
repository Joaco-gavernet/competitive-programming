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
  ll p = 0, q = 0; 
  ll a = 0, b = 0; 
  string ans; 
  while (SZ(ans) < l) {
    // what if i don't increment a anymore? 
    ll xr = x - p, yr = y - q; 
    ll jmps = l - SZ(ans); 
    if (jmps * (a + 1) <= xr and jmps * (b + 1) <= yr) {
      // find which option minimizes euclidean distance 
      if (euc(p + a + 1, q + b, x, y) < euc(p + a, q + b + 1, x, y)) ans += 'X', a++;  
      else ans += 'Y', b++; 
    } 
    else if (jmps * (a + 1) <= xr) ans += 'X', a++;  
    else if (jmps * (b + 1) <= yr) ans += 'Y', b++; 
    else assert(false); 
    p += a; 
    q += b; 
  } 
  assert(p + q == L); 
  cout << ans << '\n';
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}


