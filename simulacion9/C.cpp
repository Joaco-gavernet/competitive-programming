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
const int INF = (int)(1<<30); // (1LL<<60)
// const int MAXN = (int)(2e5+5);
const int MAXN = 10;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef int tipo;

vb visto(MAXN,0);
vi distToEnd(MAXN,INF);
vi distToWormhole(MAXN,INF);

struct nodo {
  tipo d; bool visto; //d -> distance, visto -> seen
};

vector<nodo> BFS(int start, int n, vector<vi> &g, vb &isw) {
  vector<nodo> ans(n); queue<int> q;
  forn(i, n) ans[i] = {INF,false};
  ans[start] = {0,true}; q.push(start); 
  if (start == 0 and isw[start]) distToWormhole[start] = 0;
  if (start == n-1 and isw[start]) distToEnd[start] = 0;

  while(!q.empty()) {
    int v = q.front(); q.pop();
    for(int u : g[v]) {
      if(ans[u].visto) continue;
      if (start == 0 and isw[u] == true) distToWormhole[u] = ans[v].d+1;
      if (start == n-1 and (isw[u] == true or u == 0)) distToEnd[u] = ans[v].d+1;
      ans[u] = {ans[v].d+1, true}; q.push(u);
    }
  }
  return ans;
}

int main(){
  FIN;

  int n,m,k; cin >> n >> m >> k;
  vi w; // wormholes
  vb isw(n,false);
  vector<vi> g(n); // grafo

  int act;
  forn(i,k) {
    cin >> act; 
    w.pb(--act);
    isw[act] = true;
  }

  int a,b;
  forn(_,m) {
    cin >> a >> b;
    g[--a].pb(--b); // aristas no-dirigidas
    g[b].pb(a);
  }

  BFS(0,n,g,isw);
  fill(all(visto),false);
  BFS(n-1,n,g,isw);

  dbg(distToWormhole);
  dbg(distToEnd);
  RAYA;

  ll s = 0;
  forn(i,k) s += distToEnd[w[i]];
  dbg(s);

  ll path = distToEnd[0]*(k-1);
  forn(i,k) {
    path = min(path, s -distToEnd[w[i]] +distToWormhole[w[i]]*(k-1));
  }
  dbg(path);

  cout << path << '/' << k-1 << endl;



  return 0;
}
