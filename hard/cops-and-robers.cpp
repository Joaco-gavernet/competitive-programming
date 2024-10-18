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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

// Dinic: Max Flow en O(V^2 E). Para el grafo bipartito con source
// y sink dummy, funciona en O(sqrt(V) E). Equivalente a Hopcroft-Karp.

// Matching: aristas saturadas (que no incluyan source/sink)
// Min cut: nodos con dist>=0 vs nodos con dist<0
// MVC: Nodos izquierda con dist<0 + nodos derecha con dist>0
// Maximum Independent Set: complemento de MVC (N-MVC)
struct Dinic{
  int nodes,src,dst;
  vector<int> dist,q,work;
  struct edge { int to,rev; ll f,cap; };
  vector<vector<edge>> g;
  Dinic(int x):nodes(x),dist(x),q(x),work(x),g(x){}
  void add_edge(int s, int t, ll cap){
    g[s].pb({t,SZ(g[t]),0,cap});
    g[t].pb({s,SZ(g[s])-1,0,0});
  }
  bool dinic_bfs(){
    fill(all(dist),-1);dist[src]=0;
    int qt=0;q[qt++]=src;
    forn(qh, qt){
      int u=q[qh];
      forn(i,SZ(g[u])){
        edge &e=g[u][i];int v=g[u][i].to;
        if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
      }
    }
    return dist[dst]>=0;
  }
  ll dinic_dfs(int u, ll f){
    if(u==dst)return f;
    for(int &i=work[u];i<SZ(g[u]);i++){
      edge &e=g[u][i];
      if(e.cap<=e.f)continue;
      int v=e.to;
      if(dist[v]==dist[u]+1){
        ll df=dinic_dfs(v,min(f,e.cap-e.f));
        if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
      }
    }
    return 0;
  }
  ll max_flow(int _src, int _dst){
    src=_src;dst=_dst;
    ll result=0;
    while(dinic_bfs()){
      fill(all(work),0);
      while(ll delta=dinic_dfs(src,INF))result+=delta;
    }
    return result;
  }
};

int dx[] = {0,1,0,-1}; 
int dy[] = {-1,0,1,0}; 

void bfs(const int n, const int m, const int yb, const int xb, const vector<string> &tab, Dinic &din) {
  vector<vb> visto(m, vb(n,false)); 
  queue<ii> q; q.push({yb, xb}); 
  queue<ii> last; last.push({-1, -1}); 
  visto[yb][xb] = true; 

  while (q.size()) {
    auto [y, x] = q.front(); q.pop(); 
    auto [ly, lx] = last.front(); last.pop(); 
    forn(i,4) {
      int _y = y + dy[i]; 
      int _x = x + dx[i];
      if (_y < 0 or _y >= m or _x < 0 or _x >= n) {
        din.add_edge(y*n +x +m*n, 2*m*n, INF); 
      } else {
        din.add_edge(y*n +x +m*n, _y*n +_x, INF); 
        if (visto[_y][_x] == false) {
          visto[_y][_x] = true; 
          q.push({_y, _x}); 
          last.push({y,x}); 
        }
      }
    }
  }
}

int main(){
  FIN;

  int n, m, c; cin >> n >> m >> c; 
  vector<string> tab(m); 
  int yb = -1, xb = -1; 
  forn(i,m) {
    cin >> tab[i]; 
    forn(j,n) if (tab[i][j] == 'B') yb = i, xb = j; 
  }
  vi cost(c); forn(i,c) cin >> cost[i]; 

  Dinic din(2*m*n +5); 
  forn(y,m) forn(x,n) {
    ll _cost = INF; 
    char c = tab[y][x]; 
    if (c != '.' and c != 'B' and c != '$') _cost = cost[c -'a']; 
    din.add_edge(y*n +x, y*n +x +m*n, _cost); 
  }

  bfs(n,m,yb,xb,tab,din); 

  ll ans = din.max_flow(yb*n +xb, 2*m*n); 
  if (ans >= INF) cout << "-1\n"; 
  else cout << ans << '\n'; 


  return 0;
}
