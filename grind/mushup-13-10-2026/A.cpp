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


const ll INF = 1LL<<60; 

void solve() {
  ll n; cin >> n; 
  vi b(n); forn(i,n) cin >> b[i]; 

  vi h(n); 
  forn(i,n) if (b[i] > 0) {
    h[max(0ll, i - b[i] + 1)]++; 
    if (i + b[i] < n) h[i + b[i]]--; 
  } 

  ll on = 0; 
  forn(i,n) {
    on += h[i]; 
    if (b[i] == -1 and on == 0) b[i] = 0; 
  } 

  // check if construction works 
  vi dp(n, INF); 
  ll prev = -1; 
  forn(i,n) {
    if (b[i] == 0) prev = i; 
    if (prev == -1) continue; 
    dp[i] = min(dp[i], i - prev);
  } 
  prev = -1; 
  forn(j,n) {
    int i = n - 1 - j; 
    if (b[i] == 0) prev = i; 
    if (prev == -1) continue; 
    dp[i] = min(dp[i], prev - i);
  } 
  forn(i,n) {
    if (b[i] == -1) b[i] = dp[i]; 
    else if (b[i] != dp[i]) return void(cout << -1 << '\n'); 
  } 

  for (auto x : b) cout << (x == 0 ? '1' : '0'); 
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
