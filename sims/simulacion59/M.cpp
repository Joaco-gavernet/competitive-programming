#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"
ll MAXN=2e5+5;

struct edge{
  int u; ll w;
};

vector<vi> tree(MAXN);
vi costo(MAXN);
vector <vector<edge>> g(MAXN);
vb visto(MAXN,false);
vi color(MAXN,-1);
vector <vi> comp(MAXN);
bool find_cicle(int v){
  visto[v]=true;
  for(auto &[u,w] : g[v])if(!visto[u] or u==0){
    if(u==0 and g[0][0].u!=v){
      costo[0]+=w;
      color[v]=0;
      comp[0].pb(v);
      return true;
    }
    else if(u!=0 and find_cicle(u)){
      costo[0]+=w;
      color[v]=0;
      comp[0].pb(v);
      return true;
    }
  }
  return false;
}

int main() {
  FIN;
  int n, m; cin >> n >> m;
  vector <unordered_map <int,pair<ll,int>>> mapa(n);
  ll ans=-1e17;
  forn(i,m){
    int a, b; ll w;
    cin >> a >> b >> w;
    a--; b--;
    if(mapa[a][b].second==0) {
      g[a].pb({b,w}); mapa[a][b]={w,SZ(g[a])};
      g[b].pb({a,w}); mapa[b][a]={w,SZ(g[b])};
    }
    else{
      ans=max(ans,w+mapa[a][b].first);
      mapa[a][b].first=max(mapa[a][b].first,w);
      g[a][mapa[a][b].second].w=max(w,g[a][mapa[a][b].second].w);
      mapa[b][a].first=max(mapa[b][a].first,w);
      g[b][mapa[b][a].second].w=max(w,g[b][mapa[b][a].second].w);
    }
  }
  // DBG(ans);
  // forn(v,n){
  //   RAYA;
  //   for(auto &[u,w] : g[v]) cout << v << " " << u << " " << w << endl;
  // }
  find_cicle(0);
  cout << costo[0] << endl;
  for(auto v : comp[0]) DBG(v);
  return 0; 
}