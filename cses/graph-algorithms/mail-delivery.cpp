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
#define SZ(x) int((x).size())
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(5e5+5);


// Todos tienen que cumplir: SZ(path) == tot_edges+1
// 
// Existencia undirected:
// Path: Que el start y final tengan deg impar, el resto todo par
// Cycle: Todos los nodos in_deg=out_deg

struct edge {
  int y;
  list<edge>::iterator rev;
  edge(int _y):y(_y){}
};

list<edge> g[MAXN];
vector<int> p;

void add_edge(int a, int b){
  g[a].push_front(edge(b)); auto ia = g[a].begin();
  g[b].push_front(edge(a)); auto ib = g[b].begin();
  ia->rev=ib; ib->rev=ia;
}
void go(int x){
  while(SZ(g[x])){
    int y = g[x].front().y;
    g[y].erase(g[x].front().rev);
    g[x].pop_front();
    go(y);
  }
  p.pb(x);
}
vector<int> get_path(int x){ // get a path that begins in x
  // check that a path exists from x before calling to get_path!
  dbg("fin.");
  p.clear(); go(x); reverse(all(p));
  return p;
}

bitset<MAXN> visto;
void dfs(int v) {
  visto[v] = 1;
  for (auto u: g[v]) {
    if (visto[u.y] == 0) dfs(u.y);
  }
}

int main(){
  FIN;

  int n,m; cin >> n >> m;
  int a,b;
  forn(_,m) {
    cin >> a >> b;
    add_edge(--a,--b);
  }
  
  dfs(0);

  // check if unconnected components are singular nodes
  forn(i,n) {
    if ((visto[i] == 0 and g[i].size() > 0) or g[i].size() % 2 != 0) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  vector<int> ans = get_path(0);
  if ((SZ(ans) == m+1) and (ans[0] == ans[SZ(ans)-1])) {
    for(int i: ans) cout << i +1 << ' ';
  } else cout << "IMPOSSIBLE\n";

  return 0;
}









