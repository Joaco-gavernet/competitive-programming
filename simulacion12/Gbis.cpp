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
#define SZ(x) int((x).size())
#define RAYA cerr << "===============================" << endl

const int INF = 1<<30;

// Dinic: Max Flow en O(V^2 E). Para el grafo bipartito con source
// y sink dummy, funciona en O(sqrt(V) E). Equivalente a Hopcroft-Karp.

// Matching: aristas saturadas (que no incluyan source/sink)
// Min cut: nodos con dist>=0 vs nodos con dist<0
// MVC: Nodos izquierda con dist<0 + nodos derecha con dist>0
// Maximum Independent Set: complemento de MVC (N-MVC)

struct edge { 
  int to,rev; 
  ll f,cap; 
};
struct Dinic{
  int nodes,src,dst;
  vector<int> dist,q,work;
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

bool cmp(const edge &a, const edge &b) { 
  if (a.f < b.f) return true;
  else return false;
} 


// struct edge { int to,rev; ll f,cap; };
int main(){
  FIN;

  int p,r,c; cin >> p >> r >> c;
  int n = p+r+2;
  int obj = 0;
  vector<int> demands(p); forn(i,p) cin >> demands[i], obj += demands[i];
  vector<int> stocks(r); forn(i,r) cin >> stocks[i];


  vector<edge> s;
  ll worst = -1;
  forn(i,c) {
    int a,b; ll w;
    cin >> a >> b >> w;
    worst = max(worst,w);
    s.pb({b,a+r,w,-1});
  }
  sort(all(s),cmp);
  dbg(obj);

  for (edge e: s) dbg(e.to,e.rev,e.f,e.cap);
  RAYA;

  int pl = -1, pr = worst +1;
  while (pl + 1 < pr) {
    int mid = pl + (pr-pl)/2;
    dbg(pl,mid,pr);

    // build flow network (source and sink)
    Dinic flow(n);
    forr(i,1,r+1) flow.add_edge(0,i,stocks[i-1]); // link source
    forr(i,r+1,p+1+r) flow.add_edge(i,p+r+1,demands[i-(r+1)]); // link sink

    // add considered edges up to mid time
    for (auto e: s) {
      if (mid < e.f) break;
      dbg(e.to,e.rev);
      flow.add_edge(e.to, e.rev, INF);
    }
    ll result = flow.max_flow(0,p+r+1);
    dbg(result);

    if (result < obj) pl = mid;
    else pr = mid;
    RAYA;
  }

  if (pr == worst +1) cout << "-1\n";
  else cout << pr << '\n';


  return 0;
}
