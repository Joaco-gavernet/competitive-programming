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

void dfs1(vector<vector<int>> &g, string &typ, int v = 0, int prev = -1) {
  int p = 0, s = 0;

  if (prev != -1) {
    if (typ[prev] == 'P') p++;
    else if (typ[prev] == 'S') s++;
  }

  for (int u: g[v]) {
    if (u != prev) {
      dfs1(g,typ,u,v);
      if (typ[u] == 'P') p++;
      else if (typ[u] == 'S') s++;
    }
  }
  if (typ[v] == 'C') {
    if (p > s) typ[v] = 'P';
    else if (p < s) typ[v] = 'S';
    else ;
  }
}

int dfs2(vector<vector<int>> &g, string &typ, int v = 0, int prev = -1) {
  int tot = 0;
  for (int u: g[v]) {
    if (u != prev) {
      if (typ[v] == 'S' and typ[u] == 'P') tot++;
      else if (typ[v] == 'P' and typ[u] == 'S') tot++;
      tot += dfs2(g,typ,u,v);
    }
  }
  return tot;
}

int main(){
  FIN;

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<vector<int>> g(n);

    int b;
    forr(a,1,n) {
      cin >> b;
      g[a].pb(--b);
      g[b].pb(a);
    }

    string typ; cin >> typ;

    dfs1(g,typ);
    int ans = dfs2(g,typ);
    cout << ans << '\n';
  }



  return 0;
}
