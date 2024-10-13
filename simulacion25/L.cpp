#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n" 
#define esta(x,c) ((c).find(x) != (c).end())

struct bf{
  int posicion,pila,nro;
  
  bool operator <(bf b) const{
    if(posicion==b.posicion) return pila<b.pila;
    return posicion<b.posicion;
  }
};

struct prox{
  int posicion,pila,nro,dif;
  
  bool operator <(prox b) const{
    if(dif==b.dif and posicion==b.posicion) return pila<b.pila;
    if(dif==b.dif) return posicion<b.posicion;
    return dif<b.dif;
  }
};

int main() {
  FIN; 
  vector<int> poscarta(101,-1);
  vector<int> pila(98);
  vector<int> min1={1},min2={1},max1={100},max2={100};
  int pm1=0,pm2=0,pm3=0,pm4=0;
  forn(i,98){
    cin>>pila[i];
    poscarta[pila[i]]=i+1;
  }
  //~ for(auto u:pila){cout<<u<<" ";} cout<<endl;
  set<int> pos,neg;
  int puntero=8;
  forn(i,8){
    pos.insert(pila[i]);
    neg.insert(pila[i]*(-1));
  }
  //~ bool cumplo=true;
  int cjf=2;
  while(cjf==2){
    cjf=0;
    forn(z,2){
      int cj=0;
      //Chequeo Backflips
      vector<bf> backflips;
      if(esta(min1[pm1]-10,pos)){
	backflips.pb({poscarta[min1[pm1]-10],1,min1[pm1]-10});
      }
      if(esta(min2[pm2]-10,pos)){
	backflips.pb({poscarta[min2[pm2]-10],2,min2[pm2]-10});
      }
      if(esta(max1[pm3]+10,pos)){
	backflips.pb({poscarta[max1[pm3]+10],3,max1[pm3]+10});
      }
      if(esta(max2[pm4]+10,pos)){
	backflips.pb({poscarta[max2[pm4]+10],4,max2[pm4]+10});
      }
      sort(all(backflips));
      int i=-1;
      while(cj<1 and (i+1)<SZ(backflips)){
	i++;
	if(poscarta[backflips[i].nro]==-1) continue;
	else{
	  if(backflips[i].pila==1){ min1.pb(backflips[i].nro); pm1++; poscarta[backflips[i].nro]=-1;}
	  else if(backflips[i].pila==2){ min2.pb(backflips[i].nro); pm2++; poscarta[backflips[i].nro]=-1;}
	  else if(backflips[i].pila==3){ max1.pb(backflips[i].nro); pm3++; poscarta[backflips[i].nro]=-1;}
	  else if(backflips[i].pila==4){ max2.pb(backflips[i].nro); pm4++; poscarta[backflips[i].nro]=-1;}
	  cj++; cjf++;
	  pos.erase(backflips[i].nro); neg.erase((-1)*(backflips[i].nro));
	}
      }
      vector<prox> proximas;
      if(cj<1){
	auto it=pos.lower_bound(min1[pm1]);
	if(it!=pos.end()) proximas.pb({poscarta[*it],1,*it,(*it)-min1[pm1]});
	it=pos.lower_bound(min2[pm2]);
	if(it!=pos.end()) proximas.pb({poscarta[*it],2,*it,(*it)-min2[pm2]});
	it=neg.lower_bound((-1)*max1[pm3]);
	if(it!=neg.end()) proximas.pb({poscarta[(*it)*(-1)],3,(*it)*(-1),(*it)+max1[pm3]});
	it=neg.lower_bound((-1)*max2[pm4]);
	if(it!=neg.end()) proximas.pb({poscarta[(*it)*(-1)],4,(*it)*(-1),(*it)+max2[pm4]});
	sort(all(proximas));
	i=-1;
	while(cj<1 and (i+1)<SZ(proximas)){
	  i++;
	  if(poscarta[proximas[i].nro]==-1) continue;
	  else{
	    if(proximas[i].pila==1){ min1.pb(proximas[i].nro); pm1++; poscarta[proximas[i].nro]=-1;}
	    else if(proximas[i].pila==2){ min2.pb(proximas[i].nro); pm2++; poscarta[proximas[i].nro]=-1;}
	    else if(proximas[i].pila==3){ max1.pb(proximas[i].nro); pm3++; poscarta[proximas[i].nro]=-1;}
	    else if(proximas[i].pila==4){ max2.pb(proximas[i].nro); pm4++; poscarta[proximas[i].nro]=-1;}
	    cj++; cjf++;
	    pos.erase(proximas[i].nro); neg.erase((-1)*(proximas[i].nro));
	  }
	}
      }
    }
    if(cjf==2 and puntero<98){
      pos.insert(pila[puntero]); neg.insert(pila[puntero]*(-1));
      puntero++;
      pos.insert(pila[puntero]); neg.insert(pila[puntero]*(-1));
      puntero++;
    }
    //~ }else{	
      //~ cjf=0;
    //~ }
  }
  //Salidas
  for(auto u:min1) cout<<u<<" ";
  cout<<"\n";
  for(auto u:min2) cout<<u<<" ";
  cout<<"\n";
  for(auto u:max1) cout<<u<<" ";
  cout<<"\n";
  for(auto u:max2) cout<<u<<" ";
  cout<<"\n";
  vector<pair<int,int>> rem;
  for(auto u:pos){
    rem.pb({poscarta[u],u});
  }
  sort(all(rem));
  forn(i,SZ(rem)) cout<<rem[i].second<<" ";
  cout<<"\n";
  forr(i,puntero,98) cout<<pila[i]<<" ";
  cout<<"\n";
  return 0;
}
