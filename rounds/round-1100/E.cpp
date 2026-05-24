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


const int MOD = 998'244'353; 

void dfs(int x, vector<vi>& g, vi& par, int prev = -1) {
  par[x] = prev; 
  for (auto y : g[x]) if (y != prev) dfs(y, g, par, x); 
} 


void solve() {
  int n; cin >> n; 
  vector<vi> g(n);
  forn(i,n-1) {
    int a, b; cin >> a >> b; 
    --a, --b;
    g[a].pb(b);
    g[b].pb(a); 
  } 

  vi par(n, -1); // par[i] = "parent of node i-th with tree rooted in 0" 
  dfs(0, g, par); 
  vi deg(n); 
  forn(i,n) deg[i] = SZ(g[i]); 

  forn(i,n) dbg(i, g[i]); 
  dbg(par); 
  dbg(deg); 

  // first pick max leaf available 
  vi leaves;  
  forn(i,n) if (deg[i] == 1) leaves.pb(i); 
  sort(all(nxt)); 
  priority_queue<ll, vi, greater<ll>> pq; 
  pq.push(leaves.back()); 
  leaves.pop_back(); 


  while (SZ(pq)) {
    dbg(pq.top(), leaves); 
    int mx = pq.top(); 

    vi nxt; 
    while (SZ(leaves)) {
      auto x = leaves.back(); leaves.pop_back(); 
      deg[par[x]]--; 
      if (deg[par[x]] == 1) {
        if (par[x] < mx) leaves.pb(par[x]); 
        else pq.push(par[x]); 
      } 
    } 
  } 


  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
