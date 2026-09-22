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


const ll INF = 1ll<<60; 

ll find(vi& a) {
  const ll n = SZ(a); 
  vi p(n + 1); 
  forn(i,n) p[i + 1] = p[i] + a[i]; 

  ll best = 0, mn = 0; 
  forn(i,n + 1) {
    best = max(best, p[i] - mn); 
    mn = min(mn, p[i]); 
  } 
  return best; 
} 

void solve() {
  ll n, k; cin >> n >> k; 
  string s; cin >> s; 
  vi a(n); forn(i,n) cin >> a[i];

  vi p(n + 1); 
  forn(i,n) {
    if (s[i] == '0') a[i] = -INF;
    p[i + 1] = a[i] + p[i]; 
  } 

  ll mx = find(a); 
  if (mx > k) return void(cout << "NO\n"); 

  int pos = -1; 
  forn(i,n) if (s[i] == '0') pos = i; 

  if (pos > -1) {
    ll b = 0; forr(i,pos + 1,n) b = max(b, p[i + 1] - p[pos + 1]); 
    ll c = 0; forn(i,pos) c = max(c, p[pos] - p[i]); 
    a[pos] = k - b - c; 
  } 
  mx = find(a); 
  if (mx != k) cout << "NO\n"; 
  else {
    cout << "YES\n"; 
    for (auto x : a) cout << x << ' '; 
    cout << '\n'; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
