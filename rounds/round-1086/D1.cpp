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

void dfs(int orig, int x, vector<vi> &g, vector<vector<char>> &u, int prev = -1) {
  for (auto y: g[x]) if (y != prev) {
    u[orig][y] = '1'; 
    dfs(orig, y, g, u, x); 
  } 
} 

int xdfs(int x, vector<vi> &gn, vb &visto, bool &ok, int prev = -1) {
  visto[x] = true; 
  int tot = 1;
  for (auto y: gn[x]) if (y != x and y != prev) {
    if (visto[y]) {
      ok = false;
      return 0;
    }
    tot += xdfs(y, gn, visto, ok, x); 
  } 
  return tot;
} 


bool valid(vector<vi> &gn) {
  bool ok = true; 
  vb visto(SZ(gn)); 
  int tot = xdfs(0, gn, visto, ok); 
  return (ok and tot == SZ(gn)); 
} 

bool check_tree(vector<vi> &g) {
  const int n = SZ(g); 
  vector<vi> gn(n); 
  int tot = 0;
  forn(i,n) {
    for (auto y: g[i]) {
      tot++; 
      gn[i].pb(y);
      gn[y].pb(i); 
    } 
  } 

  if (tot != n-1) return false; 
  if (!valid(gn)) return false;
  return true; 
} 

bool check(vector<vi> &g, vector<vector<char>> &v) {
  if (check_tree(g) == false) return false; 

  const int n = SZ(g); 
  vector<vector<char>> u(n, vector<char>(n, '0')); 
  forn(i,n) u[i][i] = '1';
  forn(i,n) dfs(i, i, g, u); 

  bool miss = false; 
  forn(i,n) forn(j,n) miss |= (v[i][j] != u[i][j]); 

  return !miss; 
} 

void solve() {
  int n; cin >> n; 
  vector<vector<char>> v(n, vector<char>(n)); 
  forn(i,n) forn(j,n) cin >> v[i][j]; 

  vector<vi> g(n); 
  forn(y,n) {
    forn(x,n) {
      if (x == y) continue; 
      if (v[y][x] == '0') continue; 
      bool ok = true; 
      forn(k,n) if (k != y and k != x) {
        if (v[y][k] == '1' and v[k][x] == '1') ok = false; 
      } 
      if (ok) g[y].pb(x); 
    } 
  } 

  if (check(g, v) == false) cout << "No\n";
  else {
    cout << "Yes\n"; 
    forn(i,n) for (auto y: g[i]) cout << i + 1 << ' ' << y + 1 << '\n'; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
