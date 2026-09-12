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

  vi dp(n + 1, n); 
  vi mn(n + 1, n); 
  forn(i,n) {
    ll bot = min((i + 1) * a[i], n); 
    ll top = max(0LL, min(n, bot + i)); 
    if (dp[top] == n) dp[top] = i + 1; 
    mn[top] = min(mn[top], bot); 
  } 
  for (int i = n - 2; i >= 0; i--) {
    if (mn[i + 1] <= i) mn[i] = min(mn[i], mn[i + 1]); 
    dp[i] = min(dp[i], dp[i + 1]); 
  } 

  dbg(a); 
  dbg(mn); 
  dbg(dp); 
  ll tot = 1, acc = 0; 
  forr(i,0,n + 1) {
    if (mn[i] == i) {
      if (acc > 0) {
        ll k = acc / dp[i]; 
        ll base = be(2, dp[i]) - 1;
        ll aux = max(1LL, k * base);
        aux %= MOD; 

        ll rem = acc % dp[i]; 
        aux *= max(1LL, be(2, rem) - 1); 
        aux %= MOD; 

        dbg(i, dp[i], acc); 
        dbg(k, rem, aux);

        dbg(tot, aux); 
        tot *= aux;
        tot %= MOD; 
        acc = 0; 
      } 
    } else acc++; 
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
