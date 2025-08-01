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


void dfs(ll v, vector<vi> &g, vb &visto, map<ii, bool> &skip, ll prev = -1) {
  visto[v] = true; 
  for (auto u: g[v]) if (u != prev) {
    if (visto[u] == false) dfs(u, g, visto, skip, v); 
    else {
      int mn = min(v, u), mx = max(v, u); 
      skip[{mn, mx}] = true; 
    }
  } 
} 

void solve() {
  int n; cin >> n; 
  vector<vi> g(2*n); 
  vb valid(2*n); 
  vector<ii> prs; 
  forn(i,n) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
    prs.pb({a, b}); 
    valid[a] = valid[b] = true; 
  } 
  map<ii,bool> skip; 
  vb visto(2*n, false); 
  forn(v,2*n) if (valid[v]) {
    if (visto[v] == false) dfs(v, g, visto, skip); 
  } 

  vi ans; 
  forn(i,n) if (skip[prs[i]] == false) ans.pb(i); 
  cout << SZ(ans) << '\n'; 
  for (auto &x: ans) cout << x +1 << ' ';
  cout << '\n'; 
}

int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
