#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

void dfs(int v, vector<vector<ii>> &g, vi &p, int &l, int &r, int prev = -1, ll dif = -1) {
  for (auto [u, dif]: g[v]) if (u != prev) {
    dfs(u, g, p, l, r, v, dif); 
  } 

  if (prev == -1 or dif > 0) p[v] = l++; 
  else p[v] = r--; 
}

void solve() {
  int n; cin >> n; 

  int l = 1, r = n; 
  vector<vector<ii>> g(n); 
  forn(i,n-1) {
    int u, v; cin >> u >> v; 
    ll x, y; cin >> x >> y; 
    g[--u].pb({--v, x-y}); 
    g[v].pb({u, y-x}); 
  } 

  vi p(n); 
  dfs(0, g, p, l, r); 
  for (auto &x: p) cout << x << ' '; 
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
