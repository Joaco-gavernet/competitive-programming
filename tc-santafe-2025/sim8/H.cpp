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
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl



int dfs(int v, vector<vi> &g, vector<ii> &ans, int prev = -1) {
  int rest = -1; 
  for (auto u: g[v]) if (u != prev) {
    int aux = dfs(u, g, ans, v); 
    if (rest == -1) rest = aux; 
    else ans.pb({rest, aux}), rest = -1; 
  } 
  if (rest == -1) rest = v;
  return rest; 
} 

void solve() {
  int n; cin >> n; 
  vector<vi> g(n); 
  vi deg(n); 
  forn(i,n-1) {
    int u, v; cin >> u >> v; 
    g[--u].pb(--v); g[v].pb(u); 
    deg[v]++, deg[u]++; 
  }

  int start = -1; 
  forn(v,n) if (deg[v] %2 == 0) {
    start = v; 
    break; 
  }

  vector<ii> ans; 
  int rest = -1; 
  if (start == -1) cout << "-1\n"; 
  else {
    dfs(start, g, ans); 
    cout << SZ(ans) << '\n'; 
    for (auto [a, b]: ans) {
      cout << a +1 << ' ' << b +1 << '\n'; 
    }
  } 
}

int main(){
  FIN;
  int t; cin >> t; 
  while (t--) solve(); 
  return 0;
}
