#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

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

  int n, m;
  cin >> n >> m;
  
  // n+m+2 
  // 0 fuente
  // [1 a n] banderas
  // [n+1 a n+m] colores
  // n+m+1 sumidero
  
  vector <vi> g(n+m+2);
  
  Dinic mflow(n+m+2);
  
  forr(i,1,n+1) {
    mflow.add_edge(0,i,1);
  }
  forr(i,n+1,n+m+1) {
    mflow.add_edge(i,n+m+1,1);
  }
  
  forn(i,n) {
    int k; cin >> k;
    forn(_,k) {
      int x; cin >> x;
      mflow.add_edge(i+1,n+x,1);
    }
  }
  
  cout << mflow.max_flow(0,n+m+1) << "\n";
  return 0;
}











