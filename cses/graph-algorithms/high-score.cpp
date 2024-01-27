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

typedef long long tipo;
const int MAXN = 3000;
tipo INF = (tipo)(1e18+7);

// Description: Bellman-Ford algorithm for finding the shortest path from a source to all other nodes in a graph. It can also detect negative cycles.
// Time: O(VE)

struct arista {
  int x, y; tipo w; // Edge from x to y, w = weight
};

struct nodo {
  int p; tipo d; //f -> parent, d -> distance
  bool m = 0;
};

vector<nodo> ans(MAXN);
unordered_map<int,int> ciclo; 

void bFord(vector<arista> &lista, int n, int start) {
  forn(i,n) ans[i].p = i, ans[i].d = -INF;
  ans[start].d = 0; int x = -1;
  forn(i,n) {
    x = -1;
    for(arista u : lista) {
      if(ans[u.y].d < ans[u.x].d + u.w or ans[u.y].d == -INF) {
        ans[u.y].d = ans[u.x].d + u.w;
        ans[u.y].p = u.x;
        x = u.y;
        if (i == n-1) ans[u.y].m = 1;
      }
    }
  }
//  if(x == -1) return false;
//  else {
//    forn(i,n) x = ans[x].p;
//    for(int v = x ;; v = ans[v].p) {
//      ciclo[v]++;
//      if(v == x && ciclo.size() > 1) break;
//    }
//    return true;
//  }
}

vector<bool> visto;
void dfs(int v, vector<vector<int>> &g) {
  visto[v] = true;
  for(int i: g[v]) {
    if (visto[i] == 0) dfs(i,g);
  }
}

vector<bool> visto2;
bool dfs2(int v, vector<vector<int>> &g) {
  visto2[v] = true;
  if (ans[v].m == 1 and visto[v] == 1) return true;
  bool ans = false;
  for(int i: g[v]) {
    if (visto2[i] == 0) ans = dfs2(i,g);
    if (ans == true) break;
  }
  return ans;
}


int main(){
  FIN;
  
  int n,m; cin >> n >> m;
  vector<arista> g(m);
  forn (i,m) { 
    cin >> g[i].x >> g[i].y >> g[i].w;
    g[i].x--; g[i].y--;
  }
  
  dbg("fin.");
  bFord(g,n,0);
  RAYA;
  forn(i,n) dbg(i,ans[i].d,ans[i].p);

  // mark nodes reached from 0
  vector<vector<int>> g2(n);
  forn(i,m) g2[g[i].x].pb(g[i].y);
  visto.resize(n);
  dfs(0,g2);
  dbg(visto);
 
  // reverse adjency list
  vector<vector<int>> g3(n);
  forn(i,m) g3[g[i].y].pb(g[i].x);

  // dfs to check if last vertex reaches a cycle ???
  visto2.resize(n);
  bool loop = dfs2(n-1,g3);
  dbg(visto2);
  
  if (loop == true) cout << "-1\n";
  else cout << ans[n-1].d << '\n';

  return 0;
}












