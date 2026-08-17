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
  int n, m; cin >> n >> m; 
  vi a(n); forn(i,n) cin >> a[i];
  vi b(m); forn(i,m) cin >> b[i]; 
  a.pb(0);
  b.pb(0);
  n++, m++; 

  vi u;
  forr(i,1,n) u.pb(a[i - 1] - a[i] + 1); 
  a = u; 
  u.clear(); 

  forr(i,1,m) u.pb(b[i - 1] - b[i] + 1); 
  b = u;
  u.clear(); 
  reverse(all(a));
  reverse(all(b)); 

  while (SZ(a) and SZ(b)) {
    if (a.back() >= b.back()) {
      a.back() -= b.back();
      b.pop_back(); 
      if (a.back() == 0) a.pop_back(); 
    } else {
      b.back() -= a.back();
      a.pop_back(); 
    } 
  } 

  if (SZ(b) == 0) cout << 1 << '\n';
  else cout << 2 << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
