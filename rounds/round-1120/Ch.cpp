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

void solve() {
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  ll N = n + 1;
  vi h(N), dp(N, N); 
  forn(i,n) {
    ll bot = (i + 1) * a[i]; 
    ll top = max(0LL, min(n - 1, bot + i)); 
    if (bot <= top) {
      h[bot]--, h[top + 1]++; 
      dp[bot] = min(dp[bot], i + 1); 
    } 
  } 
  for (int i = N - 2; i >= 0; i--) dp[i] = min(dp[i], dp[i + 1]);

  dbg(a); 
  dbg(h);
  dbg(dp); 

  ll acc = 0, tot = 1, prev = 0;
  forn(i, N) {
    if (acc >= 0 and acc + h[i] < 0) {
      ll len = i - prev; 
      ll x = dp[i]; 
      ll k = len / x; 
      ll rem = len % x; 

      tot *= max(1LL, (k * (be(2, x) - 1))) % MOD; 
      tot %= MOD; 

      tot *= max(1LL, (be(2, rem) - 1)) % MOD; 
      tot %= MOD; 

    } else if (acc < 0 and acc + h[i] >= 0) prev = i; 
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
