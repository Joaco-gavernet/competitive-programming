#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

struct evento{
  ll persona,maquina;
  ll time;
  
  bool operator < (evento e) const{
    if(time==e.time){
      return persona>e.persona;
    }else return time<e.time;
  }
};


int main() {
  FIN; 
  vi tmaq(10,-1);
  vector<vector<ii>> times(11,vector<ii>(10,{0,0}));
  set<evento> eventos;
  evento aux; aux.persona=0; aux.maquina=0; aux.time=0;
  eventos.insert(aux);
  forn(i,10){
    cin>>times[0][i].first>>times[0][i].second;
  }
  forn(i,10){
    cin>>times[i+1][i].first>>times[i+1][i].second;
    cin>>aux.time;
    aux.maquina=i;
    aux.persona=i+1;
    eventos.insert(aux);
  }
  ll cont=0;
  while(cont<30){
    auto it =eventos.begin();
    evento prox=*it;
    eventos.erase(it);
    if(tmaq[prox.maquina]>prox.time){
      prox.time=tmaq[prox.maquina];
      eventos.insert(prox);
    }else{
      tmaq[prox.maquina]=prox.time+times[prox.persona][prox.maquina].first;
      if(prox.persona>0){
	prox.time=prox.time+times[prox.persona][prox.maquina].first+times[prox.persona][prox.maquina].second;
      }else if(prox.persona==0){
	cont++;
	//~ if(cont==30){
	  //~ cout<<prox.time+times[prox.persona][prox.maquina].first<<"\n";
	  //~ return 0;
	//~ }
	prox.time=prox.time+times[prox.persona][prox.maquina].first+times[prox.persona][prox.maquina].second;
	prox.maquina=((prox.maquina+1)%10);
      }else DBG(prox.time);
      eventos.insert(prox);
    }
  }
  cout<<tmaq[9]<<"\n";
  return 0;
}
