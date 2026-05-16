#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

const ll INF = 1LL<<60;

int main() {
  FIN;
  ll n,m,d; cin>>n>>m>>d;
  vector<vii> g(n);
  // map<ii,ll> mejorarista;
  forn(i,m){
    ll u,v,h; cin>>u>>v>>h;
    u--; v--;
    g[u].pb({v,h});
  }
  vi tags; forn(i,d){ll x; cin>>x; tags.pb(x);}
  tags.pb(INF);
  sort(all(tags)); reverse(all(tags));
  if(tags.back()==0) tags.pop_back();
  ll proxtag=tags.back(); tags.pop_back();
  priority_queue<ii> dijkstra;
  vi previo(n,-1);
  vb visto(n,false);
  vb multiple(n,false);
  vi dist(n,INF); dist[0]=0;
  visto[0]=true;
  for(auto u:g[0]){
    if(visto[u.ff]) continue;
    ll dprox=u.ss;
    if(dprox > proxtag) continue;
    if(dist[u.ff] == dprox) multiple[u.ff]=true;
    else if(dprox < dist[u.ff]){
      multiple[u.ff]=multiple[0];
      dist[u.ff]=dprox;
      previo[u.ff]=0;
      dijkstra.push({-u.ss,u.ff});
    }
  }
  while(SZ(dijkstra)){
    auto elem=dijkstra.top(); dijkstra.pop();
    if(visto[elem.ss]) continue;
    elem.ff*=-1;
    // DBG(elem.ss); DBG(elem.ff);
    if(elem.ss == n-1){
      if(multiple[n-1]==true){cout<<"1\n"; return 0;}
      else{
        vi ans;
        ll puntero=n-1;
        ans.pb(puntero+1);
        while(previo[puntero]>=0){
          puntero=previo[puntero];
          ans.pb(puntero+1);
        }
        reverse(all(ans));
        cout<<SZ(ans)<<"\n";
        for(auto u:ans) cout<<u<<"\n";
        return 0;
      }
    }
    visto[elem.ss]=true;
    if(elem.ff == proxtag){proxtag=tags.back(); tags.pop_back();} 
    for(auto u:g[elem.ss]){
      if(visto[u.ff]) continue;
      ll dprox=u.ss+dist[elem.ss];
      // DBG(u.ff); DBG(dprox);
      if(dprox > proxtag) continue;
      if(dist[u.ff] == dprox) multiple[u.ff]=true;
      else if(dprox < dist[u.ff]){
        multiple[u.ff]=multiple[elem.ss];
        dist[u.ff]=dprox;
        previo[u.ff]=elem.ss;
        dijkstra.push({-dprox,u.ff});
      }
    }
  }
  cout<<"0\n"; 
  return 0; 
}