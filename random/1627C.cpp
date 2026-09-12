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
  int n; cin >> n; 

  vector<vi> g(n); 
  map<ii,ll> id; 
  forn(i,n - 1) {
    int x, y; cin >> x >> y; x--, y--; 
    g[x].pb(y); 
    g[y].pb(x); 
    ii p = {x, y}, pr = {y, x}; 
    id[p] = id[pr] = i; 
  } 
  bool ok = true; 
  forn(i,n) if (SZ(g[i]) > 2) ok = false;
  if (!ok) return void(cout << "-1\n");  

  vi ans(n - 1); 
  function<void(int, int, int)> fix = [&](int x, int prev, int op) -> void {
    ii p = {x, prev}; 
    if (id.count(p) > 0) ans[id[p]] = op; 
    for (auto y : g[x]) if (y != prev) fix(y, x, op ^ 1); 
  }; 
  forn(i,n) if (SZ(g[i]) == 1) {
    fix(i, -1, 0); 
    break; 
  } 

  vi prim = {2, 3}; 
  for (auto x : ans) cout << prim[x] << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
