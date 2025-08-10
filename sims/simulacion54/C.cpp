#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '

const int INF = 200;

struct Dinic {
  int nodes, src, dst; 
  vi dist, q, work;
  struct edge { int to, rev; ll f, cap; };
  vector<vector<edge>> g;
  Dinic (int x): nodes(x), dist(x), q(x), work(x), g(x) {}
  void add_edge(int s, int t, ll cap) {
    g[s].pb({t, SZ(g[t]), 0, cap}); 
    g[t].pb({s, SZ(g[s]) -1, 0, 0}); 
  }
  bool dinic_bfs() {
    fill(all(dist), -1); dist[src] = 0;
    int qt = 0; q[qt++] = src;
    forn(qh, qt) {
      int u = q[qh]; 
      forn(i,SZ(g[u])) {
        edge &e = g[u][i]; int v = g[u][i].to;
        if (dist[v] < 0 and e.f < e.cap) dist[v] = dist[u] +1, q[qt++] = v;
      }
    }
    return dist[dst] >= 0;
  }

  ll dinic_dfs(int u, ll f) {
    if (u == dst) return f;
    for (auto &i = work[u]; i < SZ(g[u]); i++) {
      edge &e = g[u][i]; 
      if (e.cap <= e.f) continue; 
      int v = e.to;
      if (dist[v] == dist[u] +1) {
        ll df = dinic_dfs(v, min(f, e.cap -e.f));
        if (df > 0) { e.f += df; g[v][e.rev].f -= df; return df; }
      }
    } 
    return 0;
  }

  ll max_flow(int _src, int _dst) {
    src = _src; dst = _dst; 
    ll result = 0;
    while (dinic_bfs()) {
      fill(all(work), 0);
      while (ll delta = dinic_dfs(src, INF))
        result += delta; 
    }
    return result;
  }
};

int main() {
  FIN;
  ll r,c; cin>>r>>c;
  vector<vi> mat(r,vi(c));
  ll sum=0,cant=0;
  vi maxrow(r,0);
  vi maxcol(c,0);
  Dinic match(r+c+2);
  forn(i,r) match.add_edge(0,i+1,1);
  forn(i,c) match.add_edge(r+c-i,r+c+1,1);
  forn(i,r) forn(j,c){
    cin>>mat[i][j];
    if(mat[i][j]){
      cant++; sum+=mat[i][j];
    }
    maxrow[i]=max(maxrow[i],mat[i][j]);
    maxcol[j]=max(maxcol[j],mat[i][j]);
  }
  // DBG(sum); DBG(cant);
  ll rec=cant;
  forn(i,r) forn(j,c) if(maxrow[i]==maxcol[j] and maxrow[i]>0 and mat[i][j]!=0) match.add_edge(i+1,r+1+j,1);
  ll cmatch=match.max_flow(0,r+c+1);
  // DBG(cmatch);
  vb vr(r),vc(c);
  forn(i,r){
    for(auto u:match.g[i+1]) if(u.f == 1){
      vr[i]=true;
      // DBG(i);
      // DBG(u.to-(r+1));
      vc[u.to-(r+1)]=true;
      rec+=(maxrow[i]-1);
    }
  }
  // DBG(rec);
  forn(i,r) if(!vr[i] and maxrow[i]>0) rec+=(maxrow[i]-1);
  forn(i,c) if(!vc[i] and maxcol[i]>0) rec+=(maxcol[i]-1);
  cout<<sum-rec<<"\n";
  return 0;
}