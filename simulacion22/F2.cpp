#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "========================= \n"

const ll MAXN = -1;
const ll MOD = -1;
const ll INF = -1;

long double remtime(ii dron1, ii dron2){
  if(dron1.second==dron2.second) return -1;
  long double ans=dron2.first-dron1.first;
  ans=ans/(dron1.second-dron2.second);
  return ans;
}

int main() {
  FIN;
  ll n; cin>>n;
  vector<ii> drones(n);
  vector<bool> nochocados(n,true); int cont=n;
  forn(i,n) cin>>drones[i].first>>drones[i].second;
  sort(all(drones));
  set<pair<long double,ll>> choques;
  vector<ll> prev(n),prox(n);
  forn(i,n){
    prev[i]=i-1; prox[i]=i+1;
  }
  forn(i,n-1){
    long double t=remtime(drones[i],drones[i+1]);
    if(t>0) choques.insert({t,i});
  }
  long double aux;
  while(SZ(choques)){
    pair<long double,ll> proxchoque=*(choques.begin());
    ll cme=proxchoque.second,cma=prox[proxchoque.second];
    cont-=2;
    nochocados[cme]=false; nochocados[cma]=false;
    //~ cout<<cme<<" "<<cma<<"\n";
    choques.erase(choques.begin());
    //~ cout<<prev[cme]<<" "<<prox[cma]<<"\n";
    if(prev[cme]>=0 and prox[cma]<n){
      //~ cout<<"INSERTO: "<<prev[cme]<<" "<<prox[cma]<<"\n";
      aux=remtime(drones[prev[cme]],drones[prox[cma]]);
      if(aux>0) choques.insert({aux,prev[cme]});
    }
    if(prev[cme]>=0){
      choques.erase({remtime(drones[prev[cme]],drones[cme]),prev[cme]});
      prox[prev[cme]]=prox[cma];
    }
    if(prox[cma]<n){
      choques.erase({remtime(drones[cma],drones[prox[cma]]),cma});
      prev[prox[cma]]=prev[cme];
    }
  }
  cout<<cont<<"\n";
  forn(i,n){
    if(nochocados[i]) cout<<i+1<<" ";
  }
  cout<<"\n";
  return 0;
}
