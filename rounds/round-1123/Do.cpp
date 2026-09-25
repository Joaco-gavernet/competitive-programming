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
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vector<vi> v(2); 
  forn(i,n) v[i&1].pb(a[i]); 
  forn(j,2) sort(all(v[j])); 

  vi ans = {v[0][0]}; 
  vi p(2); p[0] = 1; 
  v[0][0] = -1; 
  while (true) {
    ll id = SZ(ans) % 2; 
    while (p[id] < SZ(v[id]) and v[id][p[id]] < ans.back()) p[id]++; 
    if (p[id] < SZ(v[id])) {
      ans.pb(v[id][p[id]]); 
      v[id][p[id]] = -1;
    } else break; 
  } 
  forn(j,2) reverse(all(v[j])); 

  // remove -1s 
  vector<vi> u(2); 
  forn(j,2) for (auto x : v[j]) if (x != -1) u[j].pb(x); 
  v = u; 

  p = {0, 0}; 
  while (p[0] < SZ(v[0]) or p[1] < SZ(v[1])) {
    ll id = SZ(ans) % 2; 
    if (v[id][p[id]] > ans.back()) return void(cout << "NO\n"); 
    else {
      ans.pb(v[id][p[id]]); 
      p[id]++; 
    } 
  } 
  if (SZ(ans) < n) cout << "NO\n";
  else cout << "YES\n"; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
