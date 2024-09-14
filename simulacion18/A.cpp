#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> pi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ================= \n"
#define fs first
#define ss second

const int INF = -1;
const int MAXN = -1;
const int MOD = -1;
int b=-1;

typedef ll tipo;

struct arista {
  int x,y; tipo d; tipo w;
};

struct nodo {
  tipo rec,d=INF, v, a;
  bool operator <(const nodo &x) const {
    return d > x.d;
  }
};

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
  //~ vector<set<pair<int,int>> pos(n);
  vector<nodo> ans(n);
  vb visto(n, false);
  priority_queue<nodo> p; p.push({0,0, start, -1});
  while (!p.empty()) {
    nodo it = p.top(); p.pop();
    if (visto[it.v]) continue;
    else {
      ans[it.v] = it; visto[it.v] = true;
      for (arista u : g[it.v]) {
	if ((!visto[u.x]) and (u.d+it.rec<=b)) p.push({u.d+it.rec, it.d + u.w, u.x, it.v});
	//~ if ((!visto[u.x]) and (it.d+u.w <=b)) p.push({it.d + u.w, u.x, it.v});
      }
    }
  }
  
  return ans;
}

vector<vector<int>> dist(101,vector<int>(101,0));

void init_dist(){
  forn(i,101){
    forn(j,101){
      dist[i][j]=ceil(sqrt(i*i+j*j));
    }
  }
}

int main() {
  FIN;
  init_dist();
  int x,y; cin>>x>>y;		//Origen
  int w,z; cin>>w>>z;		//Destino
  cin>>b;			//Max Dist
  int c0; cin>>c0;
  int t; cin>>t;
  vector<int> c(t+1); c[0]=c0;
  forn(i,t){cin>>c[i+1];}
  int n; cin>>n;
  map<int,pair<int,int>> m;
  vector<vector<arista>> g(n+2); //0 es casa, n+1 es destino, las otras son estaciones
  arista aux; 
  aux.x=n+1;
  aux.d=dist[abs(x-w)][abs(y-z)];
  aux.w=aux.d*c[0];
  g[0].pb(aux);
  //~ cout<<"Arista a estacion "<<aux.x<<" con distancia "<<aux.d<<" y  peso "<<aux.w<<"\n";
  aux.x=0;
  g[n+1].pb(aux);
  vector<pair<int,int>> stats(n);
  vector<vector<pair<int,int>>> via(n);
  //~ DBG(n);
  forn(i,n){
    int xs,ys; cin>>xs>>ys; stats[i]={xs,ys};
    m[i]=stats[i];
    int l; cin>>l;
    forn(j,l){
      int qq,ww; cin>>qq>>ww;
      via[i].pb({qq,ww});
    }
  }
  //~ DBG(n);
  forn(i,n){
    //~ cout<<i+1<<":\n";
    pair<int,int> a; a=stats[i];
    aux.x=i+1;
    aux.w=dist[abs(x-a.first)][abs(y-a.second)]*c[0];
    aux.d=dist[abs(x-a.first)][abs(y-a.second)];
    g[0].pb(aux);
    //~ cout<<"Arista a estacion "<<aux.x<<" con distancia "<<aux.d<<" y  peso "<<aux.w<<"\n";
    aux.x=0;
    g[i+1].pb(aux);    
    aux.x=n+1;
    aux.w=dist[abs(w-a.first)][abs(z-a.second)]*c[0];
    aux.d=dist[abs(w-a.first)][abs(z-a.second)];
    g[i+1].pb(aux);
    //~ cout<<"Arista a estacion "<<aux.x<<" con distancia "<<aux.d<<" y  peso "<<aux.w<<"\n";
    aux.x=i+1;
    g[n+1].pb(aux);
    for(auto p:via[i]){
      int sta,tra; sta=p.first; tra=p.second;
      //~ cout<<p.first<<" "<<p.second<<endl;
      pair s=m[sta];
      aux.x=sta+1;
      aux.w=dist[abs(a.first-s.first)][abs(a.second-s.second)]*c[tra];
      aux.d=dist[abs(a.first-s.first)][abs(a.second-s.second)];
      g[i+1].pb(aux);
      //~ cout<<"Arista a estacion "<<aux.x<<" con distancia "<<aux.d<<" y  peso "<<aux.w<<"\n";
      aux.x=i+1;
      g[sta+1].pb(aux);
    }
  }
  vector<nodo> ans=Dijkstra(0,n+2,g);
  for(auto u:ans){
    //~ cout<<u.d<<" "<<u.v<<"\n";
    if (u.v == n+1){
      cout<<u.d<<"\n";
      return 0;
    }
  }
  cout<<-1<<"\n";
  return 0;
}
