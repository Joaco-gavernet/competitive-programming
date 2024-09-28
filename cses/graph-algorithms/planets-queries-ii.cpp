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
const ll LOG = 20; // check ???????????????????????????
const int MAXN = 2e5+5;

#define SZ(x) int((x).size())
typedef vector<int> vi;
typedef vector<bool> vb;

vector<vi> succ(MAXN, vi(32));
vb vis(MAXN, false);
vi len(MAXN);

void dfs_topo(int v) {
  vis[v] = true;
  int u = succ[v][0];
  if (vis[u] == false) dfs_topo(u);
  len[v] = len[u] +1;
}

int go(int x, int d) {
  if (d <= 0) return x;
  int i = 0;
  while (d) {
    if (d&1) x = succ[x][i];
    d >>= 1;
    i++;
  }
  return x; 
}

int main(){
  FIN;

  // Observations: 
  // 1. We are given a functional graph. 
  // 2. There are 3 possible cases:
  //   - case 1: both in cycle
  //   - case 2: both in tree
  //   - case 3: one in each

  int n, q; cin >> n >> q; 
  forn(i,n) cin >> succ[i][0]; 
  forn(i,n) succ[i][0]--;

  forr(j,1,32) forn(i,n) succ[i][j] = succ[succ[i][j-1]][j-1];

  forn(i,n) if (vis[i] == false) dfs_topo(i);

  forn(i,q) {
    int x, y; cin >> x >> y; 
    x--, y--;
    int z = go(x, len[x]); // Me voy al final del ciclo
    
    if (go(x, len[x] -len[y]) == y) cout << len[x] -len[y] << "\n";
    else if (go(z, len[z] -len[y]) == y) cout << len[x] +len[z] -len[y] << "\n";
    else cout << "-1\n";
  }


  return 0;
}










