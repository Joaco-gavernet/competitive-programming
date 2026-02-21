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



unordered_map<ll,ll> dfs(int x, vector<vi> &g, vi &ans, vi &my, vi &add, vi &a) {
  unordered_map<ll,ll> level; 
  level[0] += a[x]; 
  for (auto y : g[x]) {
    unordered_map<ll,ll> li = dfs(y, g, ans, my, add, a); 
    if (SZ(level) < SZ(li)) swap(li, level); // small-to-large
    for (auto [k, v]: li) {
      ans[x] += ((y == my[x]) * add[x] + (k + 1)) * v; 
      level[k + 1] += v;
    } 
    li.clear(); 
  } 
  dbg(x, level); 
  return level; 
} 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vector<vi> g(n); 
  forn(i,n-1) {
    int u, v; cin >> u >> v; 
    g[--u].pb(--v); 
  } 

  vi toleaf(n, 1); 
  vi my(n, -1), add(n), sum(n); 
  function<void(ll)> f = [&](ll x) {
    vi bmx = {-1, -1}; 
    sum[x] = a[x]; 
    for (auto y : g[x]) {
      f(y); 
      toleaf[x] = max(toleaf[x], toleaf[y] + 1);  
      sum[x] += sum[y]; 
      if (my[x] == -1 or sum[my[x]] < sum[y]) my[x] = y; 
      if (bmx[0] == -1 or toleaf[bmx[0]] < toleaf[y]) bmx[0] = y; 
      else if (bmx[1] == -1 or toleaf[bmx[1]] < toleaf[y]) bmx[1] = y; 
    } 
    add[x] = (bmx[0] == -1 ? 0 : toleaf[bmx[0]]); 
    if (my[x] == bmx[0]) add[x] = (bmx[1] == -1 ? 0 : toleaf[bmx[1]]); 
  }; 
  f(0); 
  dbg(my); 
  dbg(add); 

  vi ans(n); 
  dfs(0, g, ans, my, add, a); 

  for (auto x: ans) cout << x << ' '; 
  cout << '\n'; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
