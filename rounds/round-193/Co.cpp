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


ll f(ll n, ll m, ll x, ll y, vi& a, vi& b) {
  ll tot = 0; 
  map<ll,ll> h; 
  int C = min(y, m) - 1; 
  int R = min(x, n) - 1;
  dbg(n, m, x, y, C, R); 
  dbg(a);
  dbg(b); 
  if (C == 0 and R == 0) {
    if (n == 1 or m == 1) return max(a.back(), b.back()); 
    else return a.back() + b.back(); 
  } 
  while (SZ(b) and C) {
    if (h.count(b.back()) == 0) tot += b.back(), h[b.back()]++, C--;
    b.pop_back(); 
  } 
  while (SZ(a) and R) {
    if (h.count(a.back()) == 0) tot += a.back(), h[a.back()]++, R--;
    a.pop_back(); 
  } 
  while (SZ(a) and h.count(a.back())) a.pop_back(); 
  while (SZ(b) and h.count(b.back())) b.pop_back(); 

  if (SZ(a) and SZ(b)) tot += max(a.back(), b.back()); 
  else if (SZ(a)) tot += a.back();
  else if (SZ(b)) tot += b.back(); 
  return tot; 
} 

void solve() {
  ll n, m, x, y; cin >> n >> m >> x >> y; 
  vi a(x); forn(i,x) cin >> a[i]; 
  vi b(y); forn(i,y) cin >> b[i]; 

  ll best = 0; 
  best = f(n, m, x, y, a, b); 
  // swap(a, b);
  // swap(n, m);
  // swap(x, y); 
  // best = max(best, f(n, m, x, y, a ,b)); 
  cout << best << '\n'; 

  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
