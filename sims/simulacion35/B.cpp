#include <bits/stdc++.h> 
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SZ(x) int((x).size())
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "================================\n"

const int MAXN=200005;
typedef long long tipo;
int INF = 1<<30;

struct nodo{
  int origen,destino;
  int id;
  //~ int ang;
  //~ int cos;
  nodo(int o,int d){
    origen=o;
    destino=d;
    id=1000*d+o;
    //~ ang=a;
  }
  bool operator <(nodo n) const{
    return id<n.id;
  }
};

vector<vector<ii>> g(1e6+7);
vector<nodo> v(1e6+7,nodo(0,0));

ll BFS(int start, int n,int fin){
  //~ DBG(n);
  vector<bool> visto(n,false);
  vector<int> dist(n,INF);
  queue<int> q;
  ll ans=INF;
  visto[start]=true; dist[start]=0; q.push(start);
  while(!q.empty()){
    int xx=q.front(); q.pop();		//Desde acá hay que modificar
    for(auto u:g[xx]){
      if(visto[u.first]) continue;
      dist[u.first]=dist[xx]+u.second;
      if(v[u.first].destino==fin) ans=min(INF,dist[u.first]);
      q.push(u.first);
    }
  }
  //~ RAYA;
  return ans;
}

int main() {
  FIN; 
  int n,d,a1,a2; cin>>n>>d>>a1>>a2;
  g.resize(1000*n+6);
  vector<vector<ii>> par(n,vector<ii>(n,{INF,INF}));
  forn(i,n){
    int m; cin>>m;
    vector<ll> b(m),t(m),dx(m);
    forn(j,m){ cin>>dx[j]>>t[j]>>b[j]; dx[j]--;}
    forn(x,m){
      forn(y,m){
	int b1=b[x],b2=b[y];
	bool posible=false;
	if(b1<b2){
	  if(b2-b1-180>=0 and b2-b1-180<=a1)posible=true;
	  else if (b2-b1-180<=0 and b2-b1-180>=(-1)*a2)posible=true;
	}else{
	  if(b2-b1+180>=0 and b2-b1+180<=a1)posible=true;
	  else if (b2-b1+180<=0 and b2-b1+180>=(-1)*a2)posible=true;
	}
	if(posible){
	  v[i*1000+dx[x]]=nodo(dx[x],i);
	  g[i*1000+dx[x]].pb({1000*dx[y]+i,t[y]});
	}
      }
    }
  }
  RAYA;
  //~ forn(i,n){
    //~ forn(j,n){
      //~ if(i!=j){
	//~ int b1,b2;
	//~ b1=par[i][j].first;
	//~ b2=par[j][i].first;
	//~ if(b1<b2){
	  //~ int dif=b2-b1-180;
	  //~ if(dif==0 or (dif>0 and dif<a1)){
	    //~ v[1000*j+i]=nodo(i,j,par[i][j].second);
	    //~ g[1000*j+i].pb()
	  //~ } 
	//~ }else{
	  //~ int dif=b2-b1+180;
	  //~ if(dif==0 or (dif<0 and dif>(-1)*a2)){
	    //~ v[1000*j+i]=nodo(i,j,par[i][j].second);
	  //~ }
	//~ }
      //~ }
    //~ }
  //~ }
  forn(i,1000*n+6){
    if(!empty(g[i])){
      DBG(i);
      for(auto u:g[i]) DBG(u.first);
    }
  }
  RAYA;
  //~ sort(all(v));
  //~ int tam=SZ(v);
  ll ans=INF;
  //FALLA ESTA PARTE
  forn(i,n){
    ll aux;
    aux=min(ans,BFS(1000*(d-1)+i,1000*n+6,1));
    if(aux<INF){
      forn(j,n){
	ll aux2=BFS(1000*j,1000*j+6,i);
	aux=aux+aux2;
	ans=min(ans,aux);
      }
    }
  }
  cout<<ans<<"\n";
  return 0; 
}
