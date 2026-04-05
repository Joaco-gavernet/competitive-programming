#include <bits/stdc++.h>
using namespace std; 

// un solo engargado: puede mirar el scoreboard y tiene que administra los tiempos. 
// anotar en la tablita el tiempo de inicio de codeo de cada uno. 
// si se pasa mucho tiempo sacarlo y que se encargue otro.
// prioricen codear un nuevo problema antes de debuggear. 
// debuggen solo en papel o desde el celu si no tienen impresora.
// planteen como objetivo quedar top 18 (Posicion para clasificar al mundial)

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back 
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 
const ll MAXN=1e5+5;
vector <vi> g(MAXN);
vb c(MAXN,false);
vi ans(MAXN);
void color(int v, int p){
  for(auto u : g[v]) if(u!=p){
    c[u]=!c[v];
    color(u,v);
  }
}

ll count(vi &v, ll m){
  ll x=0, y=SZ(v)+1;
  while(y-x>1){
    ll med=(y+x)/2;
    if(v[med-1]<m) x=med;
    else y=med;
  }
  return x;
}

void dfs(int v, int p, bool b){
  if(c[v]!=b){
    ll x=0;
    if(p<v) x+=SZ(g[p]);
    x-=count(g[p],v);
    for(auto u : g[v]) if(u!=p){
      ll z=0;
      if(u<v) z+=SZ(g[u]);
      z-=count(g[u],v);
      ans[u]=ans[p]+x-z;
    }
  }
  for(auto u : g[v]) if(u!=p) dfs(u,v,b);
}

int main() {
  NaN;
  ll n; cin >> n;
  forn(i,n-1){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  color(0,-1);
  forn(i,n) sort(all(g[i]));
  dfs(0,-1,c[0]);
  ll x=g[0][0];
  dfs(x,-1,c[x]);
  ll m0=0, mx=0;
  forn(i,n){
    if(c[i]==c[0]) m0=min(m0,ans[i]);
    else mx=min(mx,ans[i]);
  }
  forn(i,n){
    if(c[i]==c[0]) ans[i]=n-m0+ans[i];
    else ans[i]=n-mx+ans[i];
    cout << ans[i] << " ";
  }
  return 0; 
} 
