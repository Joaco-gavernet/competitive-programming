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



ll dfs(ll x, vector<vi>& g, vb& is, ll m, vector<ii>& ans, ll prev = -1) {
  ll sub = 0; 
  for (auto y : g[x]) sub += dfs(y, g, is, m, ans, x); 
  if (is[x] and sub < m) ans.pb({min(x, prev), max(x, prev)}); 
  return sub + is[x]; 
} 

void solve() {
  int n; cin >> n;
  vector<vi> g(n); 
  vi p(n, -1); 
  map<ii, ll> id; 
  forr(i,1,n) {
    cin >> p[i], p[i]--, g[p[i]].pb(i); 
    ii P = {i, p[i]}; 
    if (P.ff > P.ss) swap(P.ff, P.ss); 
    id[P] = i;
  } 

  int m; cin >> m; 
  vb is(n); 
  forn(i,m) {
    int x; cin >> x; x--; 
    is[x] = true; 
  } 

  vector<ii> ans; 
  dfs(0, g, is, m, ans); 

  vi toprint; 
  ans.pop_back(); 
  for (auto p: ans) toprint.pb(id[p]); 
  cout << SZ(toprint) << ' '; 
  for (auto x : toprint) cout << x + 1 << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
