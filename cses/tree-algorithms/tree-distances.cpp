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

typedef vector<ll> vi;
typedef vector<bool> vb;

void dfs(vector<vi> &g, vector<vi> &dp, int v, int prev) {
  if (g[v].size() == 1 and prev == g[v][0]) { // its a leaf
    dp[v][0] = dp[v][1] = 0; // check ??????????
    return;
  }

  for (int u: g[v]) {
    if (u != prev) {
      dfs(g,dp,u,v);
      if (dp[v][0] < dp[u][0] +1) {
        dp[v][1] = dp[v][0]; // change best path in another direction
        dp[v][0] = dp[u][0] +1; // change best path
      } else dp[v][1] = max(dp[v][1], dp[u][0] +1);
    }
  }
}

void dfs2(vector<vi> &g, vector<vi> &dp, vi &best, int v, int prev) {
  if (prev == -1) best[v] = dp[v][0];
  else {
    dp[v][1] = max(dp[v][1], dp[prev][1] +1);
    if (best[prev] == dp[v][0] +1) 
      best[v] = max(dp[prev][1] +1, dp[v][0]);
    else 
      best[v] = max(best[prev] +1, dp[v][0]);
  }

  dbg(v,best);

  for (int u: g[v]) if (u != prev) dfs2(g,dp,best,u,v);
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

  vector<vi> dp(n, vi(2,0)); 
  // dp[x][0] = "max length path from x in any direction. "
  // dp[x][1] = "max length path from x in another direction. "
  dfs(g,dp,0,-1);
  forn(i,n) dbg(i,dp[i]);

  vi best(n,-1);
  dfs2(g,dp,best,0,-1);

  for(int h: best) cout << h << ' ';
  cout << '\n';

  return 0;
}
