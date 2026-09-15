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

ll be(ll x, ll y, ll m = MOD) {
  if (y == 0) return 1;
  ll p = be(x, y/2, m) % m;
  p = (p * p) % m;
  return (y%2 == 0)? p : (x * p) % m;
}

const ll INF = 1LL<<60; 

void solve() {
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  ll MX = 1;
  forn(i,n) MX = max(MX, (a[i] + 1) * (i + 1) + 5); 

  vi h(MX), evt(MX, INF);
  vector<vi> dp(MX); 
  forn(i,n) {
    ll in = (i + 1) * a[i]; 
    ll out = in + i + 1;  
    ll pos = in - (i + 1); 
    if (pos >= 0) evt[pos] = min(evt[pos], i + 1); 

    in = min(MX - 1, in); 
    out = min(MX - 1, out); 

    h[in]++;
    if (in < out) h[out]--; 
    dp[in].pb(i + 1); 
  } 

  ll acc = 0, i = 0, prev = 0;
  while (i < MX) {
    if (acc == 0 and h[i] > 0) prev = i; 
    if (prev != i) for (auto x : dp[i]) dbg(prev, x), dp[prev].pb(x); 
    acc += h[i++]; 
  } 

  dbg(evt); 
  acc = 0, prev = 0;
  ll tot = 1;
  forn(i, MX) {
    if (acc == 0 and h[i] > 0) {
      ll j = i - 1, len = 1, post = INF; 
      while (j >= prev) {
        if (evt[j] > -1) {
          if (post / evt[j] == j / evt[j]) tot *= max(1LL, be(2, len));  
          else tot *= max(1LL, (be(2, len) - 1)); 
          post = j; 
          tot %= MOD; 
          j--; 
        } 
      } 
    } else if (h[i] < 0 and acc + h[i] == 0) prev = i; 

    acc += h[i]; 
  } 

  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
