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

vector<vector<int>> g; // graph represented as an adjacency list
vector<bool> visto(MAXN,true);

void dfs(int v) {
  visto[v] = true;
  for (int u : g[v]) if (!visto[u]) dfs(u);
}

int main(){
  FIN;
  
  int n,m; cin >> n >> m;
  vector<vector<char>> mat(n); // mat - original rooms
  forn(i,n) mat[i].resize(m);
  forn(i,n) forn(j,m) cin >> mat[i][j];
  
  //~ dbg(n,m);
  g.resize(n*m); // g - constructed graph
  forn(i,n) {
    forn(j,m) {
      if (mat[i][j] == '.') {
	//~ if (i == 1 and j == 9) dbg(i > 1 and mat[i-1][j] == '.');
	if (j > 0 and mat[i][j-1] == '.') g[i*m+j].pb(i*m+j-1);
	if (i > 0 and mat[i-1][j] == '.') g[i*m+j].pb((i-1)*m+j);
	if (j+1 < m and mat[i][j+1] == '.') g[i*m+j].pb(i*m+j+1);
	if (i+1 < n and mat[i+1][j] == '.') g[i*m+j].pb((i+1)*m+j);
	visto[i*m+j] = 0;
      }
    }
  }
  //~ RAYA;
  //~ forn(i,(n*m)) dbg(i,g[i]);
  
  //~ RAYA;
  int tot = 0;
  forn(i,(n*m)) {
    if (visto[i] == 0) {
      //~ dbg(i,tot);
      dfs(i);
      tot++;
    }
  }
  
  cout << tot << '\n';
  
  return 0;
}



