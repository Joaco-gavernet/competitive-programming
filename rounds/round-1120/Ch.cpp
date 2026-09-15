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

void solve() {
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  ll m = n - 1; 

  vector<ii> good, bad; 
  forn(i,n) {
    if ((i + 1) * a[i] <= m) 
      bad.pb({(i + 1) * a[i], min(m, max(0ll, (i + 1) * (a[i] + 1) - 1))}); 
    forn(j, a[i]) {
      if ((i + 1) * j > n) return void(cout << "0\n"); 
      good.pb({(i + 1) * j, min(m, (i + 1) * (j + 1) - 1)}); 
    } 
  } 

  // discard redundant good intervals using monotonic stack 
  auto cmp = [&](ii a, ii b) {
    if (a.ff == b.ff) return a.ss > b.ss; 
    else return a.ff < b.ff; 
  };  
  sort(all(good), cmp); 
  vector<ii> stk; 
  for (auto [l, r] : good) {
    while (SZ(stk) and stk.back().ff <= l and r <= stk.back().ss) stk.pop_back(); 
    stk.pb({l, r}); 
  } 
  good = stk; 

  // find tot options 
  vi diff(m + 2); 
  for (auto [l, r] : bad) {
    diff[l]++;
    if (r + 1 <= m) diff[r + 1]--; 
  } 

  vi dp(m + 2), pref(m + 2); 
  dp[0] = pref[0] = 1; 
  ll sum = 0, ptr = 0, limit = -1; 
  forr(x, 0, m + 1) {
    sum += diff[x]; 
    while (ptr < SZ(good) and good[ptr].ss < x) 
      limit = max(limit, good[ptr++].ff); 

    if (sum == 0) {
      ll aux = pref[x]; 
      if (limit >= 0) aux = (aux - pref[limit] % MOD + MOD) % MOD; 
      dp[x + 1] = aux; 
    } 
    pref[x + 1] = (pref[x] + dp[x + 1]) % MOD; 
  } 

  ll ans = 0; 
  ll l_max = SZ(good) ? good.back().ff : -1; 
  forr(x, -1, m + 1) if (x >= l_max) ans = (ans + dp[x + 1]) % MOD; 

  cout << ans << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
