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


void solve() {
  ll n, m, x, y; cin >> n >> m >> x >> y; 
  map<ll,ll> h; 
  vi a(x); forn(i,x) cin >> a[i], h[a[i]]++;
  vi b(y); forn(i,y) cin >> b[i], h[b[i]]++; 

  vi v; 
  ll nv = 0, mv = 0; 
  while (SZ(a) and SZ(b) and SZ(v) < n + m - 1) {
    if (a.back() > b.back()) {
      if (h[a.back()] == 1 and nv < n) v.pb(a.back()), nv++; 
      else if (h[a.back()] == 2) if (SZ(v) == 0 or (SZ(v) and v.back() != a.back())) v.pb(a.back()); 
      a.pop_back(); 
    } else {
      if (h[b.back()] == 1 and mv < m) v.pb(b.back()), mv++; 
      else if (h[b.back()] == 2) if (SZ(v) == 0 or (SZ(v) and v.back() != b.back())) v.pb(b.back()); 
      b.pop_back(); 
    } 
  } 
  while (SZ(v) < n + m - 1 and SZ(a)) {
    if (h[a.back()] == 1 and nv < n) v.pb(a.back()), nv++; 
    else if (h[a.back()] == 2) if (SZ(v) == 0 or (SZ(v) and v.back() != a.back())) v.pb(a.back()); 
    a.pop_back(); 
  } 
  while (SZ(v) < n + m - 1 and SZ(b)) {
    if (h[b.back()] == 1 and mv < m) v.pb(b.back()), mv++; 
    else if (h[b.back()] == 2) if (SZ(v) == 0 or (SZ(v) and v.back() != b.back())) v.pb(b.back()); 
    b.pop_back(); 
  }


  ll tot = 0; 
  for (auto x : v) tot += x; 
  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
