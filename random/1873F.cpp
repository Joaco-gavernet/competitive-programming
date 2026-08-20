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


ll f(vi& c, ll k) {
  const int n = SZ(c); 
  vi p(n + 1); 
  forn(i,n) p[i + 1] = p[i] + c[i]; 

  ll best = 0; 
  map<ll,ll> mp; 
  mp[0] = 0; 
  forr(i,1,n+1) {
    ll x = p[i]; 
    if (mp.count(x) == 0) mp[x] = i; 
    auto it = mp.lower_bound(x - k); 
    ll act = i - it->ss;
    if (x - it->ff <= k) best = max(best, act); 
  } 

  return best; 
} 

void solve() {
  int n, k; cin >> n >> k; 
  vi a(n), h(n);
  forn(i,n) cin >> a[i];
  forn(i,n) cin >> h[i]; 

  ll best = 0, i = 1;
  vi c = {a[0]}; 
  while (i < n) {
    if (h[i - 1] % h[i] == 0) c.pb(a[i]); 
    else {
      best = max(best, f(c, k)); 
      c = {a[i]}; 
    } 
    i++; 
  } 
  best = max(best, f(c, k)); 
  cout << best << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
