#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

#define nodes first
#define dist second
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

void dfs(vector<vi> &g, vector<pi> &dp, int v = 0, int prev = -1) {
  if (g[v].size() == 1 and prev != -1) return;

  for (int u: g[v]) {
    if (u != prev) {
      dfs(g,dp,u,v);
      dp[v].nodes += dp[u].nodes;
      dp[v].dist += (dp[u].dist + dp[u].nodes);
    }
  }
}

void dfs2(vector<vi> &g, vector<pi> &dp, vi &ans, int v = 0, int prev = -1) {
  if (prev == -1) ans[v] = dp[v].dist;
  else ans[v] = ans[prev] +g.size() -2*dp[v].nodes; 

  for (int u: g[v]) if (u != prev) dfs2(g,dp,ans,u,v);
}


int main(){
  FIN;

  int n; cin >> n;
  vector<vi> g(n);

  int u,v;
  forn(i,n-1) {
    cin >> u >> v;
    g[--u].pb(--v);
    g[v].pb(u);
  }

  vector<pi> dp(n,{1,0});
  // dp[x].first = "amount of nodes in subtree rooted at x. "
  // dp[x].second = "total distance in subtree rooted at x. "
  dfs(g,dp);

  vi ans(n,-1);
  dfs2(g,dp,ans);

  for(auto h: ans) cout << h << ' ';
  cout << '\n';

  return 0;
}
