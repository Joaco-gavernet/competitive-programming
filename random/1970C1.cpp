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



bool good(int x, int n) {
  if (x == -1 or x == n) return false; 
  if (x % 2 == 0 or (n - x) % 2 == 0) return true; 
  return false; 
} 

void solve() {
  int n, t; cin >> n >> t; 
  vector<vi> g(n); 
  forn(i,n-1) {
    int u, v; cin >> u >> v; 
    u--, v--; 
    g[u].pb(v); 
    g[v].pb(u); 
  } 


  vi prev(n, -1), nxt(n, -1), ord(n); 
  function<void(int, int)> f = [&](int x, int len) -> auto {
    ord[x] = len; 
    for (auto y : g[x]) if (y != prev[x]) {
      nxt[x] = y; 
      prev[y] = x; 
      f(y, len + 1); 
    } 
  }; 

  forn(i,n) if (SZ(g[i]) == 1) {
    f(i, 0); 
    break; 
  } 

  forn(_,t) {
    ll p; cin >> p; p--; 
    if ((ord[prev[p]] % 2 == 0) or ((n - ord[nxt[p]]) % 2 == 1)) cout << "Ron\n";
    else cout << "Hermione\n"; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
