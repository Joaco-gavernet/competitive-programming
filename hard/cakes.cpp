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

int main(){
  FIN;

  int g, c, t; cin >> g >> c >> t; 
  vi profit(c); forn(i,c) cin >> profit[i]; 
  vi ing(g); forn(i,g) cin >> ing[i]; 
  vi tool(t); forn(i,t) cin >> tool[i]; 
  vector<vi> recipes(c, vi(g)); 
  forn(i,c) forn(j,g) cin >> recipes[i][j]; 
  vector<vi> tools_needed(c); 
  forn(i,c) { 
    int tot, x; cin >> tot; 
    while (tot--) cin >> x, tools_needed[i].pb(x); 
  } 
  /*
  dbg(profit); 
  dbg(ing); 
  dbg(tool); 
  dbg(recipes); 
  dbg(tools_needed); 
  */

  // discount the ingredients from the profit
  forn(i,c) forn(j,g) profit[i] -= recipes[i][j] *ing[j];
  // dbg(profit); 

  ll ans = 0;
  forn(i,c) ans += profit[i]; 

  int n = 2 + c + t; 
  Dinic red(n); 
  forn(i,c) {
    // dbg(0, i, profit[i]); 
    red.add_edge(0, 1+i, profit[i]); 
    for (int k : tools_needed[i]) red.add_edge(1+i, k + c, INF); 
  }
  forn(i,t) red.add_edge(c +1 +i, n-1, tool[i]); 

  ll aux = red.max_flow(0,n-1); 
  // dbg(ans, aux); 
  ans -= aux; 
  if (ans < 0) ans = 0; 
  cout << ans << '\n'; 



  return 0;
}
